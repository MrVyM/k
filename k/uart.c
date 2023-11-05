#include "uart.h"
#include <k/kstd.h>
#include "stdio.h"

int write(const char *buf, size_t count)
{
    puts(buf);
    return 1;
}
