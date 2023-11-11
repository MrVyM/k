#ifndef IO_H_
#define IO_H_

#include <k/types.h>

// outb transfers a data byte (8 bits) from the register 
// u16 port
// u8 val
static inline void outb(u16 port, u8 val)
{
	asm volatile ("outb %0, %1" : /* No output */ : "a"(val), "d"(port));
}

// inb return a data byte (8 bits) from the register 
// u16 port
static inline u8 inb(u16 port)
{
	u8 res;

	asm volatile ("inb %1, %0" : "=&a"(res) : "d"(port));

	return res;
}

// outw transfers a data word (16 bits) from the register 
// u16 port
// u8 val
static inline void outw(u16 port, u16 val)
{
	asm volatile ("outw %0, %1" : /* No output */ : "a"(val), "d"(port));
}

// inw return a data word (16 bits) from the register 
// u16 port
static inline u16 inw(u16 port)
{
	u16 res;

	asm volatile ("inw %1, %0" : "=&a"(res) : "d"(port));

	return res;
}

#endif				/* !IO_H_ */
