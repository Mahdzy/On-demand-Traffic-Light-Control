/*
 * File:	Button.c
 * Project:	On demand Traffic Light Control
 * Author:	Abdelrahman Almahdy
 */ 


#include "Button.h"

EN_ButtonError_t Button_Init(EN_PortNo_t ButtonPort, uint8_t ButtonPin)
{
	if (GPIO_Init(ButtonPort, ButtonPin, Input) == GPIO_OK)
	{
		return Button_OK;
	}
	else
	{
		return Button_Error;
	}
}

EN_ButtonError_t Button_Read(EN_PortNo_t ButtonPort, uint8_t ButtonPin, uint8_t* ButtonState)
{
	if (GPIO_Read(ButtonPort, ButtonPin, ButtonState) == GPIO_OK)
	{
		return Button_OK;
	}
	else
	{
		return Button_Error;
	}
}