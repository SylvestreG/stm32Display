#include <sys/types.h>
#include <dev/gpio.h>
#include <kernel.h>

void kern_main(void)
{
    int i;
	bool val = true;

	gpio_set_mode(GpioBankA, 5, GpioOutput);
	gpio_set_value(GpioBankA, 5, val);
	i = 0;

	while (true)
	{
		i++;
		if ((i % 50000) == 0) {
			val = !val;
			gpio_set_value(GpioBankA, 5, val);
		}
	}
}
