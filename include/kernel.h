/*
*kernel.h
*Holds kernel-wide defines.
*/
#ifndef KERNEL_H
#define KERNEL_H

typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef char BYTE;
typedef unsigned char UBYTE;
typedef int BOOL;

#define NULL 0
#define true 1
#define false 0

//macros
#define MIN(a,b)(a<b?a:b)
#define MAX(a,b)(a>b?a:b)
#define MAKEWORD(low,high)	( (((unsigned short)((high) & 0xFF)) << 8) | ((unsigned short)((low) & 0xFF)) )
#define MAKEDWORD(low,high)	( (((unsigned int)((high) & 0xFFFF)) << 16) | ((unsigned int)((low) & 0xFFFF)) )
#define HIBYTE(val)			( (((val) & 0xFF00) >> 8) )
#define LOBYTE(val)			( (((val) & 0x00FF)) )
#define HIWORD(val)			( (((val) & 0xFFFF0000) >> 16) )
#define LOWORD(val)			( (((val) & 0x0000FFFF)) )
#endif
