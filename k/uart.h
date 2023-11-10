#ifndef UART_H
#define UART_H

#define COM1 ((void*)0x3F8)
#define COM2 ((void*)0x2F8)
#define COM3 ((void*)0x3E8)
#define COM4 ((void*)0x2E8)

enum uart_registers 
{
    THR	= 0,
    RBR= 0,
    DLL= 0,
    IER= 1,
    DLH= 1,
    IIR= 2,
    FCR= 2,
    LCR= 3,
    MCR= 4,
    LSR= 5,
    MSR= 6,
    SR= 7,
};

#include <k/types.h>
int write(const char *buf, size_t count);
char get_lsr_value(void *com, enum uart_registers offset);
#endif 
