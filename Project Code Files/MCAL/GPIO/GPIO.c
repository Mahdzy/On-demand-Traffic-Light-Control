/*
* File:	GPIO.c
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
*/


#include "GPIO.h"

static volatile uint8_t* Ports[4][3] = { {PORTA, DDRA, PINA}, {PORTB, DDRB, PINB}, {PORTC, DDRC, PINC}, {PORTD, DDRD, PIND} }; //Array of GPIO Registers
static uint8_t* ModePtr; // Points to Mode of Traffic Lights
static uint8_t* IndexPtr; // Points to Index of current Light
static uint8_t* StatePtr; // Points to State of Pedestrian Traffic Lights
static uint16_t* CounterPtr; // Points to Counter of LED blink loops

EN_GPIOState_t GPIO_Init (EN_PortNo_t Port, uint8_t Pin, EN_PortDirection_t Direction)
{
	if (Direction == Input)
	{
		ClearBit(Ports[Port][1], Pin);
		return GPIO_OK;
	}
	else if (Direction == Output)
	{
		SetBit(Ports[Port][1], Pin);

		return GPIO_OK;
	}
	else
	{
		return Init_Error;
	}
}

EN_GPIOState_t GPIO_Write (EN_PortNo_t Port, uint8_t Pin, uint8_t Value)
{
	if ((ReadBit(Ports[Port][1], Pin))) // Checking if the Direction is Output
	{
		if (Value == Low)
		{
			ClearBit(Ports[Port][0], Pin);
			return GPIO_OK;
		}
		else if (Value == High)
		{
			SetBit(Ports[Port][0], Pin);
			return GPIO_OK;
		}
		else
		{
			return Write_Error;
		}
	}
	else
	{
		return Write_Error;
	}
}

EN_GPIOState_t GPIO_Toggle (EN_PortNo_t Port, uint8_t Pin)
{
	ToggleBit(Ports[Port][0], Pin);
	return GPIO_OK;
}

EN_GPIOState_t GPIO_Read (EN_PortNo_t Port, uint8_t Pin, uint8_t* Reading)
{
	*Reading = ReadBit(Ports[Port][2], Pin);
	return GPIO_OK;
}

/* Storing the address of variables the control light signals in pointers to be used in INT0 ISR */
void GetState(uint8_t* Ptr1, uint8_t* Ptr2, uint8_t* Ptr3)
{
	ModePtr = Ptr1;
	IndexPtr = Ptr2;
	StatePtr = Ptr3;
}

void GetCounter(uint16_t* Ptr)
{
	CounterPtr = Ptr;
}

/* Interrupt Service Routine of INT0 */
ISR(EXT_INT_0)
{
	if(*StatePtr == 1) // Checking if the Pedestrian mode is not running
	{
		*StatePtr = 0; // Setting the Pedestrian mode to running
		
		if (*IndexPtr == 1) // Checking if current cars light is green
		{
			GPIO_Write(B, 2, 1); // Turns on Pedestrian red light
		}
		else
		{
			OverFlows = 1; // To turn off
			Flag = 1;	  // Delay Timer
			*CounterPtr = 999; // To turn off LED blink
		}
		*ModePtr = 3; // Setting the traffic mode to Pedestrian
	}
}