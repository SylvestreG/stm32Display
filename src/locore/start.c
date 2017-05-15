#include <hw/vector.h>
#include <kernel.h>

void _start(void);
#define STACK_TOP 0x20004000 // just a tiny stack for demo

static void
nmi_handler(void)
{
	for (;;);
}

static void
hardfault_handler(void)
{
	for (;;);
}

void
_start(void)
{
	kern_main();
}

volatile struct cortex_m3_vector vectors __attribute__ ((section(".vectors"))) = {
	.sp = STACK_TOP,
	.reset = _start,
	.nmi = nmi_handler,
	.hardfault = hardfault_handler
};


