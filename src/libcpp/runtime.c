#include <types.h>

extern uint8_t *__init_array_start;
extern uint8_t *__init_array_end__;
extern size_t __init_array_size__;

void* __dso_handle __attribute__ ((__weak__));
typedef void (**func)(void);

void __aeabi_atexit(void)
{

}

void do_ctors(void)
{
  size_t len = (size_t)&__init_array_size__;

  func f = (func)(&__init_array_start);

  for(size_t i = 0; i < (len / 4); i++)
  {
    f[i]();
  }
}
