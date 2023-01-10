/*
* File:		LED.c
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
*/


#include "LED.h"

uint16_t Counter = 0;

EN_LEDError_t LED_Init(EN_PortNo_t LEDPort, uint8_t LEDPin)
{
	if (GPIO_Init(LEDPort, LEDPin, Output) == GPIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_Error;
	}
}

EN_LEDError_t LED_On(EN_PortNo_t LEDPort, uint8_t LEDPin)
{
	if (GPIO_Write(LEDPort, LEDPin, High) == GPIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_Error;
	}
}

EN_LEDError_t LED_Off(EN_PortNo_t LEDPort, uint8_t LEDPin)
{
	if (GPIO_Write(LEDPort, LEDPin, Low) == GPIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_Error;
	}
}

EN_LEDError_t LED_Toggle(EN_PortNo_t LEDPort, uint8_t LEDPin)
{
	if (GPIO_Toggle(LEDPort, LEDPin) == GPIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_Error;
	}
}

EN_LEDError_t LED_Blink(EN_PortNo_t LEDPort, uint8_t LEDPin, uint16_t blinkTime, uint16_t TotalTime)
{
	GetCounter(&Counter);
	
	for (Counter = 0; Counter < (TotalTime / blinkTime); Counter++)
	{
		if (LED_Toggle(LEDPort, LEDPin) == LED_OK)
		{
			Delay(Timer_2, blinkTime);
		}
		else
		{
			return LED_Error;
		}
	}
	
	return LED_OK;
}


EN_LEDError_t Two_LEDs_Blink(EN_PortNo_t LEDPort1, uint8_t LEDPin1, EN_PortNo_t LEDPort2, uint8_t LEDPin2, uint16_t blinkTime, uint16_t TotalTime)
{
	for (uint8_t Counter = 0; Counter < (TotalTime / blinkTime); Counter++)
	{
		if ((LED_Toggle(LEDPort1, LEDPin1) == LED_OK) && (LED_Toggle(LEDPort2, LEDPin2) == LED_OK))
		{
			Delay(Timer_2, blinkTime);
		}
		else
		{
			return LED_Error;
		}
	}
	
	return LED_OK;
}

