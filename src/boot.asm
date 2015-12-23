[BITS 32]

global loader
jmp loader ;jmp to the "main loader" label

extern kmain ; Kernel entry point
extern edata
extern ebss

ALIGN 4
mboot:
	MODULEALIGN equ 1<<0
	MEMINFO equ 1<<1
	FLAGS equ 111b
	MAGIC equ 0x1BADB002
	CHECKSUM EQU -(MAGIC+FLAGS)

	dd MAGIC
	dd FLAGS
	dd CHECKSUM
	dd mboot ; header_addr
	dd loader ; load_addr
	dd edata ; load_end_addr
	dd ebss ; bss_end_addr
	dd loader ; entry_addr
	STACKSIZE equ 0x4000

loader:
	mov esp,stack
	push eax
	push ebx
	call kmain
cli
hlt
.failsafe:
nop
	jmp .failsafe

; STACK AREA
SECTION .bss
	ALIGN 32
	resb STACKSIZE
stack:
