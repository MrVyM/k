#include "uart.h"
#include <k/kstd.h>
#include "../io.h"

void serial_init()
{
    // Enable Transmitter Holding Register Empty Interrupt
    outb(COM1 + IER, 0x02);

    // Access to the DLAB
    outb(COM1 + LCR, 0x80);

    // Set the baudrate to 115200
    // TODO: Get the baudrate in argument
    outb(COM1 + DLH, 0x00);
    outb(COM1 + DLL, 0x01);
    
    // No parity, One stop bit, word = *bits
    // Close the access of DLAB
    outb(COM1 + LCR, 0x03);

    // Enable the fifo 
    outb(COM1 + FCR, 0xC7);

    // Clear to send
    outb(COM1 + MCR, 0x04);
}

u8 write_available()
{
    // https://en.wikibooks.org/wiki/Serial_Programming/8250_UART_Programming#Line_Status_Register
    // Check on the LSR if the Holding Register is empty
    return inb(COM1 + LSR) & 0x20;
}

void write_char(const char c)
{
    while (write_available() == 0);
    outb(COM1,c);
}

size_t write(const char *buf, size_t count)
{
    // NOTE: The function is blocking the whole exec
    size_t send = 0;
    while (send < count)
        write_char(buf[send++]);
    return send;
}
