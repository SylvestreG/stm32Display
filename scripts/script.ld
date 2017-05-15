/* This will work with STM32 type of microcontrollers.    *
 * The sizes of RAM and flash are specified smaller than  *
 * what most of the STM32 provide to ensure that the demo *
 * program will run on ANY STM32.                         */
MEMORY
{
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 80K
    rom (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
}

ENTRY(_start)

SECTIONS
{
	.vectors : ALIGN(0x000)
	{
		FILL(0xFF)
		KEEP(*(.vectors))  
	}>rom
	
    .text : ALIGN(0x400)
    {
        . = ALIGN(4);
        _stext = .;
        *(.text*)   /* code */
        *(.rodata*) /* read only data */

        /*
         * NOTE: .glue_7 and .glue_7t sections are not needed because Cortex-M
         * only supports Thumb instructions, no ARM/Thumb interworking.
         */

        /* Static constructors and destructors */
        KEEP(*(.init))
        KEEP(*(.fini))

        . = ALIGN(4);
		_etext = .;
	}>rom

    .data :
    {
        __data_start__ = .;
        *(.data)      /* Data memory */
	. = ALIGN(4);
        __data_end__ = .;
    } >ram AT >rom

    /* startup code must copy __data_size__ bytes from __data_loadaddr__ to
     * __data_start__ before calling C */
    __data_loadaddr__ = LOADADDR(.data);

    .bss :
    {
        __bss_start__ = .;
        *(.bss)       /* Zero-filled run time allocate data memory */
	. = ALIGN(4);
        __bss_end__ = .;
    } >ram
}

__data_size__ = SIZEOF(.data);
__bss_size__ = SIZEOF(.bss);
