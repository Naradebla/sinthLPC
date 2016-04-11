/*
 * registers.h
 *
 *  Created on: 29 mar 2016
 *      Author: Gioele
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define FIO0DIR *(volatile unsigned long*) 0x2009C000
#define FIO0SET *(volatile unsigned long*) 0x2009C018
#define FIO0CLR *(volatile unsigned long*) 0x2009C01C
#define FIO0PIN *(volatile unsigned long*) 0x2009C014

#define FIO2DIR *(volatile unsigned long*) 0x2009C040
#define FIO2SET *(volatile unsigned long*) 0x2009C058
#define FIO2CLR *(volatile unsigned long*) 0x2009C05C

#define IO0IntStatF *(volatile unsigned long*) 0x40028088
#define IO0IntClr *(volatile unsigned long*) 0x4002808C
#define IO0IntEnF *(volatile unsigned long*) 0x40028094

#define STCTRL *(volatile unsigned long*) 0xE000E010
#define STRELOAD *(volatile unsigned long*) 0xE000E014

#define PCONP *(volatile unsigned long*) 0x400FC0C4

#define PINSEL1 *(volatile unsigned long*) 0x4002C004

#define DACR *(volatile unsigned long*) 0x4008C000
#define DACCTRL *(volatile unsigned long*) 0x4008C004
#define DACCNTVAL *(volatile unsigned long*) 0x4008C008


#define ISER0 *(volatile unsigned long*) 0xE000E100
#define IPR5 *(volatile unsigned long*) 0xE000E414

//GPDMA REGISTERS
#define DMACEnbldChns *(volatile unsigned long*) 0x5000401C
#define DMACConfig *(volatile unsigned long*) 0x50004030
#define DMACSync *(volatile unsigned long*) 0x50004034
//GPDMA Ch0
#define DMACC0SrcAddr *(volatile unsigned long*) 0x50004100
#define DMACC0DestAddr *(volatile unsigned long*) 0x50004104
#define DMACC0LLI *(volatile unsigned long*) 0x50004108
#define DMACC0Control *(volatile unsigned long*) 0x5000410C
#define DMACC0Config *(volatile unsigned long*) 0x50004110


#endif /* REGISTERS_H_ */
