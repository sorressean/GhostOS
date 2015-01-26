/*
*Methods and constants for i/o on ports and the like.
*/
#ifndef IO_H
#define IO_H
#include <kernel.h>

void outb(WORD port, UBYTE value);
UBYTE inb(WORD port);
WORD inw(WORD port);
#endif
