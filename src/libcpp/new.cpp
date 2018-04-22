#include <types.h>
#include <libc.h>

void *operator new(unsigned int len)
{
  return malloc(len);
}

void operator delete(void *allocated_slot)
{
  free(allocated_slot);
}
