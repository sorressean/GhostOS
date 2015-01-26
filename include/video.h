/*
*video.h
*Used for printing and controling the screen.
*/
#ifndef VIDEO_H
#define VIDEO_H
#include <kernel.h>
#include <video_constants.h>

void MonitorPutc(BYTE c);
void MonitorClear();
void MonitorPuts(const char* s);
#endif