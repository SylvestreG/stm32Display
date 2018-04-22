#include <types.h>

void
memset(void *dest, char c, size_t size)
{
  for(size_t len = 0; len < size; len++) {
    ((uint8_t *)dest)[len] = c;
  }
}
