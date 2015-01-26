#Ghost OSMakefile
OUTPUT=../bin/kernel.bin

#compiler flags:
AS = nasm
CC	= gcc
CFLAGS	= -O0 -I../include -nostdlib -nostartfiles -nodefaultlibs -fno-stack-protector -Wall -ggdb -m32
CFLAGS += -fno-omit-frame-pointer -ffreestanding
CFLAGS+=	-mpreferred-stack-boundary=8
CFLAGS+=	-mno-mmx -mno-sse

L_FLAGS	=
FORMATTER = astyle
FORMAT_FLAGS = --style=k/r

A_FILES=
A_FLAGS = -f elf
LD = ld -m elf_i386

S_FILES= video.c io.c kmain.c
O_FILES := $(patsubst %.c,%.o, $(filter %.c, $(S_FILES)))
O_FILES += $(patsubst %.asm,%.o, $(filter %.asm, $(A_FILES)))
all:$(O_FILES)
	@rm -f $OUTPUT
	@echo Linking
	@$(LD) -t -T linker.ld -o $(OUTPUT) $(O_FILES)
	@cd ../;scripts/mkiso.sh;cd $(CURDIR)

%.o:%.asm
	@echo Compiling $<.
	@$(AS) $(A_FLAGS) $<

%.o:%.c
	@echo Compiling $<.
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo Cleaning
	@rm -f *.o
	@rm -f $(OUTPUT)
	@rm -f ../iso/sapphire_x86.iso

format:
	@echo Formatting
	@$(FORMATTER) $(FORMAT_FLAGS) $(S_FILES)
	@$(FORMATTER) $(FORMAT_FLAGS) *.h
	@rm -f *.orig

iso:
	@cd ../;scripts/mkiso.sh;cd $(CURDIR)
