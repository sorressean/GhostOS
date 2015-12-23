OUTPUT_FORMAT(elf32-i386)
ENTRY (loader)

SECTIONS
{
    . = 0x00100000;
    kernelBegin = .;
    .text ALIGN(0x1000):{
*(.mboot)
	stext = .;
        *(.text)
	etext = .;
    }

    .rodata ALIGN (0x1000) : {
        *(.rodata)
    }

    .data ALIGN (0x1000) : {
	sdata = .;
        *(.data)
	edata = .;
    }

    .bss : {
        sbss = .;
        *(COMMON)
        *(.bss)
        ebss = .;
    }
    kernelEnd = .;
}


