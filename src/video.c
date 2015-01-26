#include <kernel.h>
#include <io.h>
#include <video.h>

static WORD cursor_x = 0;
static WORD cursor_y = 0;
static WORD* const topmem = (WORD*)0xB8000;

static void MonitorUpdate()
{
    WORD location = (cursor_y*80)+cursor_x;

//set the high cursor byte:
    outb(0x3D4, 14);
    outb(0x3D4, HIWORD(location));
//set the low byte
    outb(0x3D4, 15);
    outb(0x3D5, LOWORD(location));
}

static inline void MonitorScroll()
{
    if (cursor_y >= 25) {
        WORD filler = MAKEWORD(0x20, ((COLOR_BLACK<<4)|(COLOR_WHITE&0x0F)));
        int i = 0;
        for (; i< 1980; i++) {
            topmem[i] = topmem[i+80];
        }
        for (i = 1920; i < 2000; i++) {
            topmem[i] = filler;
        }
        cursor_y=24;
        MonitorUpdate();
    }
}

void MonitorPutc(BYTE c)
{
    if (c == 0x08 && cursor_x) {
        cursor_x -= 1;
    } else if(c == 0x09 && cursor_x <= 76) {
        cursor_x += 4;
    } else if (c=='\r') {
        cursor_x = 0;
    } else if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        WORD* where = topmem+(cursor_y*80+cursor_x);
        *where = MAKEWORD(c, ((COLOR_BLACK<<4)|(COLOR_WHITE&0x0F)));
        cursor_x++;
        if (cursor_x >= 80) {
            cursor_x = 0;
            cursor_y++;
            if (cursor_y>= 25) {
                MonitorScroll();
            }
        }
    }
}
void MonitorClear()
{
    WORD filler = MAKEWORD(' ', ((COLOR_BLACK<<4)|(COLOR_WHITE&0x0F)));
    int i = 0;
    for (i = 0; i < 2000; i++) {
        topmem[i] = filler;
    }

    cursor_x = 0;
    cursor_y = 0;
    MonitorUpdate();
}
void MonitorPuts(const char* s)
{
    while (*s != '\0') {
        MonitorPutc(*s);
        s++;
    }
}
