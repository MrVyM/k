#include "uart.h"
#include <k/kstd.h>
#include "stdio.h"

char get_lsr_value(void *com, enum uart_registers offset)
{
    char *port = com;
    return *(port + offset); 
}

int write(const char *buf, size_t count)
{
    size_t send = 0;
    return send;
}
