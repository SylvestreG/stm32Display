#include <dev/gpio.h>
#include <dev/rcc.h>

#define GPIO_BANK_A_BASE_ADDR 0x40020000
#define GPIO_BANK_B_BASE_ADDR 0x40020400
#define GPIO_BANK_C_BASE_ADDR 0x40020800
#define GPIO_BANK_D_BASE_ADDR 0x40020C00
#define GPIO_BANK_E_BASE_ADDR 0x40021000
#define GPIO_BANK_H_BASE_ADDR 0x40021400
#define GPIO_BANK_F_BASE_ADDR 0x40021800
#define GPIO_BANK_G_BASE_ADDR 0x40021C00

static struct gpio_reg *get_ip(gpio_bank bank)
{
	struct gpio_reg *gpio;

	switch (bank)
	{
	case GpioBankA:
		gpio = (struct gpio_reg *)GPIO_BANK_A_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioA);
		break;
	case GpioBankB:
		gpio = (struct gpio_reg *)GPIO_BANK_B_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioB);
		break;
	case GpioBankC:
		gpio = (struct gpio_reg *)GPIO_BANK_C_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioC);
		break;
	case GpioBankD:
		gpio = (struct gpio_reg *)GPIO_BANK_D_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioD);
		break;
	case GpioBankE:
		gpio = (struct gpio_reg *)GPIO_BANK_E_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioE);
		break;
	case GpioBankF:
		gpio = (struct gpio_reg *)GPIO_BANK_F_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioF);
		break;
	case GpioBankG:
		gpio = (struct gpio_reg *)GPIO_BANK_G_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioG);
		break;
	case GpioBankH:
		gpio = (struct gpio_reg *)GPIO_BANK_H_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioH);
		break;
	default:
		gpio = NULL;
		break;
	}

	return (gpio);
}

void gpio_set_mode(gpio_bank bank, uint8_t pin, gpio_mode mode)
{
	struct gpio_reg *gpio;

	gpio = get_ip(bank);

	switch (mode)
	{
	case GpioInput:
		gpio->mode &= ~(0x3u << (pin * 2));
		break;
	case GpioOutput:
		gpio->mode &= ~(0x3u << (pin * 2));
		gpio->mode |= (0x1u << (pin * 2));
		break;
	default:
		//TODO
		break;
	}
}

void gpio_set_value(gpio_bank bank, uint8_t pin, bool enable)
{
	struct gpio_reg *gpio;

	gpio = get_ip(bank);

	if (enable)
		gpio->bit_set_reset = (0x1u << pin);
	else
		gpio->bit_set_reset = (0x1u << pin) << 16;
}

/*bool gpio_get_mode(gpio_bank bank, uint8_t pin)
{
	struct gpio_reg *gpio;

	gpio = get_ip(bank);
}*/
