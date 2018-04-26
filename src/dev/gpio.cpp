#include <dev/gpio.h>
#include <dev/rcc.h>

using namespace stm32;

#pragma pack(push,1)
struct gpio_reg {
	volatile uint32_t mode;
	volatile uint32_t output_type;
	volatile uint32_t output_speed;
	volatile uint32_t pull_up_down;
	volatile uint32_t input_data;
	volatile uint32_t output_data;
	volatile uint32_t bit_set_reset;
	volatile uint32_t config_lock;
	volatile uint32_t alternate_fn_high;
	volatile uint32_t bit_reset;
};
#pragma pack(pop)

#define GPIO_BANK_A_BASE_ADDR 0x40020000
#define GPIO_BANK_B_BASE_ADDR 0x40020400
#define GPIO_BANK_C_BASE_ADDR 0x40020800
#define GPIO_BANK_D_BASE_ADDR 0x40020C00
#define GPIO_BANK_E_BASE_ADDR 0x40021000
#define GPIO_BANK_H_BASE_ADDR 0x40021400
#define GPIO_BANK_F_BASE_ADDR 0x40021800
#define GPIO_BANK_G_BASE_ADDR 0x40021C00

Gpio::Gpio(Gpio::GpioBank bank) : _bank(bank)
{
	switch (bank)
	{
	case Gpio::GpioBankA:
		_bankRegisters = (struct gpio_reg *)GPIO_BANK_A_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioA);
		break;
	case Gpio::GpioBankB:
		_bankRegisters = (struct gpio_reg *)GPIO_BANK_B_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioB);
		break;
	case Gpio::GpioBankC:
		_bankRegisters = (struct gpio_reg *)GPIO_BANK_C_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioC);
		break;
	case Gpio::GpioBankD:
		_bankRegisters = (struct gpio_reg *)GPIO_BANK_D_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioD);
		break;
	case Gpio::GpioBankE:
		_bankRegisters = (struct gpio_reg *)GPIO_BANK_E_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioE);
		break;
	case Gpio::GpioBankF:
		_bankRegisters = (struct gpio_reg *)GPIO_BANK_F_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioF);
		break;
	case Gpio::GpioBankG:
		_bankRegisters = (struct gpio_reg *)GPIO_BANK_G_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioG);
		break;
	case Gpio::GpioBankH:
		_bankRegisters = (struct gpio_reg *)GPIO_BANK_H_BASE_ADDR;
		rcc_enable_ahb_periph_clock(AhbPeriphClockGpioH);
		break;
	default:
		_bankRegisters = (struct gpio_reg *)NULL;
		break;
	}
}

Gpio::~Gpio(void)
{
	switch(_bank)
	{
	case Gpio::GpioBankA:
		rcc_disable_ahb_periph_clock(AhbPeriphClockGpioA);
		break;
	case Gpio::GpioBankB:
		rcc_disable_ahb_periph_clock(AhbPeriphClockGpioB);
		break;
	case Gpio::GpioBankC:
		rcc_disable_ahb_periph_clock(AhbPeriphClockGpioC);
		break;
	case Gpio::GpioBankD:
		rcc_disable_ahb_periph_clock(AhbPeriphClockGpioD);
		break;
	case Gpio::GpioBankE:
		rcc_disable_ahb_periph_clock(AhbPeriphClockGpioE);
		break;
	case Gpio::GpioBankF:
		rcc_disable_ahb_periph_clock(AhbPeriphClockGpioF);
		break;
	case Gpio::GpioBankG:
		rcc_disable_ahb_periph_clock(AhbPeriphClockGpioG);
		break;
	case Gpio::GpioBankH:
		rcc_disable_ahb_periph_clock(AhbPeriphClockGpioH);
		break;
	default:
		break;
	}
}

void
Gpio::set_mode(uint8_t io, Gpio::GpioMode mode)
{
	switch (mode)
	{
	case Gpio::GpioInput:
		_bankRegisters->mode &= ~(0x3u << (io * 2));
		break;
	case Gpio::GpioOutput:
		_bankRegisters->mode &= ~(0x3u << (io * 2));
		_bankRegisters->mode |= (0x1u << (io * 2));
		break;
	default:
		//TODO
		break;
	}
}

void
Gpio::set_value(uint8_t io, bool highLevel)
{
	if(true == highLevel)
		_bankRegisters->bit_set_reset = (0x1u << io);
	else
		_bankRegisters->bit_set_reset = (0x1u << io) << 16;
}
