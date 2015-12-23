#include <video.h>

static void Banner()
{
    MonitorPuts("Ghost OS");
}

int kmain()
{
    Banner();

    while(true);
    return 0;
}
