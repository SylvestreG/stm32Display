#include <types.h>
#include <libc.h>
#include <dev/gpio.h>
#include <kernel.h>

#define HEAP_SIZE 0x10000

extern "C" {
void _init(void);
void do_ctors(void);

//data
extern uint8_t *__data_start__;
extern uint8_t *__data_size__;
extern uint8_t *__data_loadaddr__;

//bss
extern uint8_t *__bss_start__;
extern uint8_t *__bss_end__;
extern size_t __bss_size__;

};

size_t heap_size = HEAP_SIZE;
uint8_t heap[HEAP_SIZE];

stm32::Gpio gpio(stm32::Gpio::GpioBankA);

void cpp_runtime_enable(void)
{
  //init data + bss
  memcpy(&__data_start__, &__data_loadaddr__, (size_t)&__data_size__);
  memset(&__bss_start__, 0x00, (size_t)&__bss_size__);

  malloc_init();

  do_ctors();
}

void kern_main(void)
{
  bool val = true;

  cpp_runtime_enable();

  gpio.set_mode(5, stm32::Gpio::GpioOutput);
  gpio.set_value(5, val);

  int i =0;
  while (true)
  {
    i++;
    if ((i % 50000) == 0) {
      val = !val;
      gpio.set_value(5, val);
    }
  }
}
