#ifndef UART_H
#define UART_H

#define COM1 ((void*)0x3F8)
#define COM2 ((void*)0x2F8)
#define COM3 ((void*)0x3E8)
#define COM4 ((void*)0x2E8)

#include <k/types.h>
int write(const char *buf, size_t count);
#endif 
