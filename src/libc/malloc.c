#include <types.h>

#define NB_MALLOC_CHUNK   0x0a
#define MALLOC_HEADER     ((uint16_t)0xcafe)
#define MALLOC_FOOTER     ((uint16_t)0xdede)

struct malloc_chunk
{
  void *start;
  uint16_t chunk_size;
  uint16_t nb_chunk;
  uint16_t nb_allocated_chunk;
  uint16_t first_free_chunk;
};

static uint16_t free_slot_lookup(struct malloc_chunk *chunk);

extern struct malloc_chunk *heap;
extern size_t heap_size;

void
malloc_init(void)
{
  size_t  memory_left;
  uint8_t *memory;

  memory_left = heap_size - (NB_MALLOC_CHUNK * sizeof(*heap));
  memory      = (uint8_t *)heap + NB_MALLOC_CHUNK * sizeof(*heap);

  for(uint8_t i = 0; i < NB_MALLOC_CHUNK; i++) {
    heap[i].chunk_size  = 4096 / ((i == 0) ? 1 : i * 2);
    heap[i].nb_chunk    = (memory_left / NB_MALLOC_CHUNK) / heap[i].chunk_size;

    heap[i].nb_allocated_chunk  = 0;
    heap[i].first_free_chunk    = 0;

    heap[i].start       = memory;
    memory              += heap[i].chunk_size * heap[i].nb_chunk;
  }
}

void *malloc(size_t size)
{
  void *allocated_slot;
  int i;

  allocated_slot = NULL;
  size = size + sizeof(MALLOC_FOOTER) + sizeof(MALLOC_HEADER); //header + footer

  if (size > 4096 || size == 0) {
      //log_error
  }

  for(i = 0; (i < NB_MALLOC_CHUNK) && (size < heap[i+1].chunk_size); i++);

  if (heap[i].nb_allocated_chunk == heap[i].nb_chunk)
  {
      //log_error
  }

  allocated_slot = heap[i].start +
    (heap[i].first_free_chunk + heap[i].chunk_size);
  heap[i].nb_allocated_chunk++;
  heap[i].first_free_chunk = free_slot_lookup(&heap[i]);

  return allocated_slot;
}

void free(void *buffer)
{
  //check footer
  buffer -= 2;
  if (((uint16_t *)buffer)[0] != MALLOC_HEADER)
  {
    //LOG_ERROR
  }

  ((uint16_t *)buffer)[0] = 0x0000;
}

static uint16_t free_slot_lookup(struct malloc_chunk *chunk)
{
  uint16_t  free_slot;
  bool      chunk_found;

  chunk_found = false;
  free_slot   = chunk->first_free_chunk + 1;

  for(; free_slot < chunk->nb_chunk; free_slot++)
  {
    if (*((uint16_t *)(chunk->start + (free_slot * chunk->chunk_size))) == MALLOC_HEADER)
      continue;
    chunk_found = true;
    break;
  }

  if(!chunk_found)
  {
    for(free_slot = 0; free_slot < chunk->first_free_chunk; free_slot++)
    {
      if (*((uint16_t *)(chunk->start + (free_slot * chunk->chunk_size))) == MALLOC_HEADER)
        continue;
      break;
    }
  }

  return free_slot;
}
