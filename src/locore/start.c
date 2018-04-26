#include <hw/vector.h>
#include <kernel.h>

void _start(void);

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

static void
memfault_handler(void)
{
	for (;;);
}

static void
busfault_handler(void)
{
	for(;;);
}

static void
usagefault_handler(void)
{
	for(;;);
}

void
_start(void)
{
	__asm__("LDR r13, =0x20013ffc");

	kern_main();
		for (;;);
}

volatile struct cortex_m3_vector vectors __attribute__ ((section(".vectors"))) = {
	.sp 				= 0x20013ffc,
	.reset 			= _start,
	.nmi 				= nmi_handler,
	.hardfault 	= hardfault_handler,
	.memfault 	= memfault_handler,
	.busfault		= busfault_handler,
	.usagefault = usagefault_handler
};
