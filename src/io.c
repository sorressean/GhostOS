#include <kernel.h>
#include <io.h>

void outb(WORD port, UBYTE value)
{
    asm volatile("outb %1, %0" : : "dN" (port), "a" (value));
}

UBYTE inb(WORD port)
{
    UBYTE ret;
    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}
WORD inw(WORD port)
{
    WORD ret;
    asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}
