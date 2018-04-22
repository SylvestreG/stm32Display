#ifndef __RCC_H__
#define __RCC_H__

#include <types.h>

#pragma pack(push,1)
struct rcc_reg {
	volatile uint32_t cr;
	volatile uint32_t icscr;
	volatile uint32_t cfgr;
	volatile uint32_t cir;
	volatile uint32_t ahbrstr;
	volatile uint32_t ahb2rstr;
	volatile uint32_t ahb1rstr;
	volatile uint32_t ahbenr;
	volatile uint32_t ahb2enr;
	volatile uint32_t apb1enr;
	volatile uint32_t ahblpenr;
	volatile uint32_t apb2lpenr;
	volatile uint32_t apb1lpenr;
	volatile uint32_t csr;
};
#pragma pack(pop)

typedef enum {
	AhbPeriphClockGpioA,
	AhbPeriphClockGpioB,
	AhbPeriphClockGpioC,
	AhbPeriphClockGpioD,
	AhbPeriphClockGpioE,
	AhbPeriphClockGpioH,
	AhbPeriphClockGpioF,
	AhbPeriphClockGpioG,
	AhbPeriphClockGpioCRC,
	AhbPeriphClockGpioFLITF,
	AhbPeriphClockGpioDMA1,
	AhbPeriphClockGpioDMA2,
	AhbPeriphClockGpioAES,
	AhbPeriphClockGpioFSMC
} ahb_periph_clock;

void rcc_enable_ahb_periph_clock(ahb_periph_clock);
void rcc_disable_ahb_periph_clock(ahb_periph_clock);

#endif /* __RCC_H__ */
