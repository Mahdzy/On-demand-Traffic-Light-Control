/*
* File:		Registers.h
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
*/


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "TypeDefinitions.h"

#define SREG ((Reg_8Bit) (0X5F))
#define SPH ((Reg_8Bit) (0X5E))
#define SPL ((Reg_8Bit) (0X5D))
#define OCR0 ((Reg_8Bit) (0X5C))
#define GICR ((Reg_8Bit) (0X5B))
#define GIFR ((Reg_8Bit) (0X5A))
#define TIMSK ((Reg_8Bit) (0X59))
#define TIFR ((Reg_8Bit) (0X58))
#define SPMCR ((Reg_8Bit) (0X57))
#define TWCR ((Reg_8Bit) (0X56))
#define MCUCR ((Reg_8Bit) (0X55))
#define MCUCSR ((Reg_8Bit) (0X54))
#define TCCR0 ((Reg_8Bit) (0X53))
#define TCNT0 ((Reg_8Bit) (0X52))
#define OSCCAL ((Reg_8Bit) (0X51))
#define SFIOR ((Reg_8Bit) (0X50))

#define TCCR1A ((Reg_8Bit) (0X4F))
#define TCCR1B ((Reg_8Bit) (0X4E))
#define TCNT1H ((Reg_8Bit) (0X4D))
#define TCNT1L ((Reg_8Bit) (0X4C))
#define OCR1AH ((Reg_8Bit) (0X4B))
#define OCR1AL ((Reg_8Bit) (0X4A))
#define OCR1BH ((Reg_8Bit) (0X49))
#define OCR1BL ((Reg_8Bit) (0X48))
#define ICR1H ((Reg_8Bit) (0X47))
#define ICR1L ((Reg_8Bit) (0X46))
#define TCCR2 ((Reg_8Bit) (0X45))
#define TCNT2 ((Reg_8Bit) (0X44))
#define OCR2 ((Reg_8Bit) (0X43))
#define ASSR ((Reg_8Bit) (0X42))
#define WDTCR ((Reg_8Bit) (0X41))
#define UCSRC ((Reg_8Bit) (0X40))

#define EEARH ((Reg_8Bit) (0X3F))
#define EEARL ((Reg_8Bit) (0X3E))
#define EEDR ((Reg_8Bit) (0X3D))
#define EECR ((Reg_8Bit) (0X3C))
#define PORTA ((Reg_8Bit) (0X3B))
#define DDRA ((Reg_8Bit) (0X3A))
#define PINA ((Reg_8Bit) (0X39))
#define PORTB ((Reg_8Bit) (0X38))
#define DDRB ((Reg_8Bit) (0X37))
#define PINB ((Reg_8Bit) (0X36))
#define PORTC ((Reg_8Bit) (0X35))
#define DDRC ((Reg_8Bit) (0X34))
#define PINC ((Reg_8Bit) (0X33))
#define PORTD ((Reg_8Bit) (0X32))
#define DDRD ((Reg_8Bit) (0X31))
#define PIND ((Reg_8Bit) (0X30))

#define SPDR ((Reg_8Bit) (0X2F))
#define SPSR ((Reg_8Bit) (0X2E))
#define SPCR ((Reg_8Bit) (0X2D))
#define UDR ((Reg_8Bit) (0X2C))
#define UCSRA ((Reg_8Bit) (0X2B))
#define UCSRB ((Reg_8Bit) (0X2A))
#define UBRRL ((Reg_8Bit) (0X29))
#define ACSR ((Reg_8Bit) (0X28))
#define ADMUX ((Reg_8Bit) (0X27))
#define ADCSRA ((Reg_8Bit) (0X26))
#define ADCH ((Reg_8Bit) (0X25))
#define ADCL ((Reg_8Bit) (0X24))
#define TWDR ((Reg_8Bit) (0X23))
#define TWAR ((Reg_8Bit) (0X22))
#define TWSR ((Reg_8Bit) (0X21))
#define TWBR ((Reg_8Bit) (0X20))

#endif /* REGISTERS_H_ */