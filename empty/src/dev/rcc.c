#include <dev/rcc.h>

#define RCC_BASE_ADDR 0x40023800

void rcc_enable_ahb_periph_clock(ahb_periph_clock clk)
{
	struct rcc_reg *rcc = (struct rcc_reg *)RCC_BASE_ADDR;

	switch (clk)
	{
	case AhbPeriphClockGpioA:
		rcc->ahbenr |= 0x1u;
		break;
	case AhbPeriphClockGpioB:
		rcc->ahbenr |= (0x1u << 1);
		break;
	case AhbPeriphClockGpioC:
		rcc->ahbenr |= (0x1u << 2);
		break;
	case AhbPeriphClockGpioD:
		rcc->ahbenr |= (0x1u << 3);
		break;
	case AhbPeriphClockGpioE:
		rcc->ahbenr |= (0x1u << 4);
		break;
	case AhbPeriphClockGpioH:
		rcc->ahbenr |= (0x1u << 5);
		break;
	case AhbPeriphClockGpioF:
		rcc->ahbenr |= (0x1u << 6);
		break;
	case AhbPeriphClockGpioG:
		rcc->ahbenr |= (0x1u << 7);
		break;
	case AhbPeriphClockGpioCRC:
		rcc->ahbenr |= (0x1u << 12);
		break;
	case AhbPeriphClockGpioFLITF:
		rcc->ahbenr |= (0x1u << 15);
		break;
	case AhbPeriphClockGpioDMA1:
		rcc->ahbenr |= (0x1u << 24);
		break;
	case AhbPeriphClockGpioDMA2:
		rcc->ahbenr |= (0x1u << 25);
		break;
	case AhbPeriphClockGpioAES:
		rcc->ahbenr |= (0x1u << 27);
		break;
	case AhbPeriphClockGpioFSMC:
		rcc->ahbenr |= (0x1u << 30);
		break;
	default:
		/* TODO */
		break;
	}
}

void rcc_disable_ahb_periph_clock(ahb_periph_clock clk)
{
	struct rcc_reg *rcc = (struct rcc_reg *)RCC_BASE_ADDR;

	switch (clk)
	{
	case AhbPeriphClockGpioA:
		rcc->ahbenr &= ~(0x1u);
		break;
	case AhbPeriphClockGpioB:
		rcc->ahbenr &= ~(0x1u << 1);
		break;
	case AhbPeriphClockGpioC:
		rcc->ahbenr &= ~(0x1u << 2);
		break;
	case AhbPeriphClockGpioD:
		rcc->ahbenr &= ~(0x1u << 3);
		break;
	case AhbPeriphClockGpioE:
		rcc->ahbenr &= ~(0x1u << 4);
		break;
	case AhbPeriphClockGpioH:
		rcc->ahbenr &= ~(0x1u << 5);
		break;
	case AhbPeriphClockGpioF:
		rcc->ahbenr &= ~(0x1u << 6);
		break;
	case AhbPeriphClockGpioG:
		rcc->ahbenr &= ~(0x1u << 7);
		break;
	case AhbPeriphClockGpioCRC:
		rcc->ahbenr &= ~(0x1u << 12);
		break;
	case AhbPeriphClockGpioFLITF:
		rcc->ahbenr &= ~(0x1u << 15);
		break;
	case AhbPeriphClockGpioDMA1:
		rcc->ahbenr &= ~(0x1u << 24);
		break;
	case AhbPeriphClockGpioDMA2:
		rcc->ahbenr &= ~(0x1u << 25);
		break;
	case AhbPeriphClockGpioAES:
		rcc->ahbenr &= ~(0x1u << 27);
		break;
	case AhbPeriphClockGpioFSMC:
		rcc->ahbenr &= ~(0x1u << 30);
		break;
	default:
		/* TODO */
		break;
	}
}
