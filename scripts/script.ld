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
	.vectors : ALIGN(4)
	{
		FILL(0xFF)
		KEEP(*(.vectors))
	}>rom

  constructors : ALIGN(100) SUBALIGN(4)
  {
    PROVIDE(__init_array_start = .);
    KEEP(*(SORT(.init_array.*)))
    KEEP(*(.init_array))
    PROVIDE(__init_array_end = .);
  }>rom

  destructors : ALIGN(4) SUBALIGN(4)
  {
    PROVIDE(__fini_array_start = .);
    KEEP(*(.fini_array))
    KEEP(*(SORT(.fini_array.*)))
    PROVIDE(__fini_array_end = .);
  } > rom

  .text : ALIGN(0x400)
  {
    . = ALIGN(4);
    _stext = .;
    *(.text*)   /* code */
    *(.rodata*) /* read only data */

    . = ALIGN(4);
    KEEP(*(.init))
    KEEP(*(.fini))

    . = ALIGN(4);
    _etext = .;
  }>rom

  .data : ALIGN(0x100)
  {
    __data_start__ = .;
    *(.data)      /* Data memory */
    . = ALIGN(4);
    __data_end__ = .;
  } >ram AT >rom

  /* startup code must copy __data_size__ bytes from __data_loadaddr__ to
   * __data_start__ before calling C */
  __data_loadaddr__ = LOADADDR(.data);

  .bss : ALIGN(0x100)
  {
    __bss_start__ = .;
    *(.bss)       /* Zero-filled run time allocate data memory */
    . = ALIGN(4);
    __bss_end__ = .;
  } >ram
}

__init_array_size__ = SIZEOF(constructors);
__data_size__ = SIZEOF(.data);
__bss_size__ = SIZEOF(.bss);
