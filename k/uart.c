#include "uart.h"
#include <k/kstd.h>
#include "stdio.h"

char get_lsr_value(char *com, enum uart_registers offset)
{
    return com[offset]; 
}

void set_baud_rate(char *com, int rate)
{
    int divisor_latch = 115200 / rate;
    com[LCR] = com[LCR] | 0x80; 
    com[LCR + 1] = divisor_latch >> 8;
    com[LCR + 0] = divisor_latch & 0xff;
    com[LCR] = com[LCR] & 0x7f; 
}

int get_baud_rate(char *com)
{
    com[LCR] = com[LCR] | 0x80; 
    int divisor_latch = (com[LCR + 1] << 8) + com[LCR + 0];
    com[LCR] = com[LCR] & 0x7f; 
    return 115200 / divisor_latch;
}

int write(const char *buf, size_t count)
{
    size_t send = 0;
    return send;
}
