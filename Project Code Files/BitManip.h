/*
 * File:	BitManip.h
 * Project:	On demand Traffic Light Control
 * Author:	Abdelrahman Almahdy
 */ 


#ifndef BITMANIP_H_
#define BITMANIP_H_

#define SetBit(Reg, Bit) (*(Reg) |= (1 << Bit))
#define ClearBit(Reg, Bit) (*(Reg) &= ~(1 << Bit))
#define ToggleBit(Reg, Bit) (*(Reg) ^= (1 << Bit))
#define ReadBit(Reg, Bit) ((*(Reg) & (1 << Bit)) >> Bit)

#endif /* BITMANIP_H_ */