#include <sys/types.h>
#include <dev/gpio.h>
#include <kernel.h>

void kern_main(void)
{
	volatile int i;

	gpio_set_mode(GpioBankA, 5, GpioOutput);
	gpio_set_value(GpioBankA, 5, true);
	i = 0;

	while (true)
	{
		i++;
	}
}
