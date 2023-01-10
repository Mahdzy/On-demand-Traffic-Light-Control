/*
* File:		Interrupts.c
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
 */ 


#include "Interrupts.h"

/* Enabling Global Interrupts */
void GlobalInt_En (void) 
{
	SetBit(SREG, 7);
}

/* Initiating External Interrupts */
EN_ExtIntError_t ExtInt_Init (EN_ExtInterrupts_t Interrupt, EN_ExtIntSense_t IntType) 
{
	switch(Interrupt)
	{
		/*External Interrupt 0 */
		case Int_0:
		switch(IntType)
		{
			case LOW:
			ClearBit(MCUCR, 0);
			ClearBit(MCUCR, 1);
			break;
			
			case Change:
			SetBit(MCUCR, 0);
			ClearBit(MCUCR, 1);
			break;
			
			case F_Edge:
			ClearBit(MCUCR, 0);
			SetBit(MCUCR, 1);
			break;
			
			case R_Edge:
			SetBit(MCUCR, 0);
			SetBit(MCUCR, 1);
			break;
			
			default:
			return Ext_Interrupt_Error;
			break;
		}
		SetBit(GICR, 6);
		break;
		
		/*External Interrupt 1 */
		case Int_1:
		switch(IntType)
		{
			case LOW:
			ClearBit(MCUCR, 2);
			ClearBit(MCUCR, 3);
			break;
			
			case Change:
			SetBit(MCUCR, 2);
			ClearBit(MCUCR, 3);
			break;
			
			case F_Edge:
			ClearBit(MCUCR, 2);
			SetBit(MCUCR, 3);
			break;
			
			case R_Edge:
			SetBit(MCUCR, 2);
			SetBit(MCUCR, 3);
			break;
			
			default:
			return Ext_Interrupt_Error;
			break;
		}
		SetBit(GICR, 7);
		break;
		
		/*External Interrupt 2 */
		case Int_2:
		switch(IntType)
		{
			case F_Edge:
			ClearBit(MCUCSR, 6);
			break;
			
			case R_Edge:
			SetBit(MCUCSR, 6);
			break;
			
			default:
			return Ext_Interrupt_Error;
			break;
		}
		SetBit(GICR, 5);
		break;
	}
	return Ext_Interrupt_OK;
}

EN_TimIntError_t TimInt_Init (EN_TimInterrupts_t Timer, EN_TimIntType_t Type)
{
	switch(Timer)
	{
		case Tim_0:
		switch(Type)
		{
			case OverFlow:
			SetBit(TIMSK, 0);
			break;
			
			case CompareMatch:
			SetBit(TIMSK, 1);
			break;
			
			default:
			return Tim_Interrupt_Error;
			break;
		}
		break;
		
		case Tim_2:
		switch(Type)
		{
			case OverFlow:
			SetBit(TIMSK, 6);
			break;
			
			case CompareMatch:
			SetBit(TIMSK, 7);
			break;
			
			default:
			return Tim_Interrupt_Error;
			break;
		}
		break;
		
		default:
		return Tim_Interrupt_Error;
		break;
	}
	return Tim_Interrupt_OK;
}
