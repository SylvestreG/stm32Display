#include <types.h>
#include <libc.h>
#include <dev/gpio.h>
#include <kernel.h>

size_t heap_size = 0x10000;
uint8_t heap[0x10000];

void kern_main(void)
{
  int i;
	bool val = true;
  uint8_t *j;

  malloc_init();
  j = new uint8_t;

  *j = 5;

	gpio_set_mode(GpioBankA, 5, GpioOutput);
	gpio_set_value(GpioBankA, 5, val);
	i = 0;

  delete j;

	while (true)
	{
		i++;
		if ((i % 50000) == 0) {
			val = !val;
			gpio_set_value(GpioBankA, 5, val);
		}
	}
}
