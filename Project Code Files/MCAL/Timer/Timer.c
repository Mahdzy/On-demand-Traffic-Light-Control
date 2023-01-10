/*
* File:		Timer.c
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
*/


#include "Timer.h"

uint32_t OverFlows = 0;
uint8_t Flag = 0;

EN_TimerError_t Timer_Init (EN_Timers_t TimerNum, EN_TimerMode_t Mode, EN_Clock_t ClkSrc)
{
	switch (TimerNum)
	{
		/* Timer 0 */
		case Timer_0:
		switch (Mode)
		{
			case Normal:
			ClearBit(TCCR0, 3);
			ClearBit(TCCR0, 6);
			break;
			
			case CTC:
			SetBit(TCCR0, 3);
			ClearBit(TCCR0, 6);
			break;
			
			case Fast_PWM:
			SetBit(TCCR0, 3);
			SetBit(TCCR0, 6);
			break;
			
			case Correct_PWM:
			ClearBit(TCCR0, 3);
			SetBit(TCCR0, 6);
			break;
			
			default:
			return Timer_Error;
			break;
		}
		
		switch (ClkSrc)
		{
			case Internal:
			{
				ClearBit(TCCR0, 0);
				ClearBit(TCCR0, 1);
				ClearBit(TCCR0, 2);
			}
			break;
			
			case External_R_Edge:
			SetBit(TCCR0, 0);
			SetBit(TCCR0, 1);
			SetBit(TCCR0, 2);
			break;
			
			case External_F_Edge:
			ClearBit(TCCR0, 0);
			SetBit(TCCR0, 1);
			SetBit(TCCR0, 2);
			break;
			
			default:
			return Timer_Error;
			break;
		}
		break;
		
		/* Timer 2 */
		case Timer_2:
		switch (Mode)
		{
			case Normal:
			ClearBit(TCCR0, 3);
			ClearBit(TCCR0, 6);
			break;
			
			case CTC:
			SetBit(TCCR0, 3);
			ClearBit(TCCR0, 6);
			break;
			
			case Fast_PWM:
			SetBit(TCCR0, 3);
			SetBit(TCCR0, 6);
			break;
			
			case Correct_PWM:
			ClearBit(TCCR0, 3);
			SetBit(TCCR0, 6);
			break;
			
			default:
			return Timer_Error;
			break;
		}
		
		switch (ClkSrc)
		{
			case Internal:
			{
				ClearBit(TCCR0, 0);
				ClearBit(TCCR0, 1);
				ClearBit(TCCR0, 2);
			}
			break;
			
			case Asynchronous:
			SetBit(ASSR, 3);
			break;
			
			default:
			return Timer_Error;
			break;
		}
		break;
		
		default:
		return Timer_Error;
		break;
	}
	
	return Timer_OK;
}

EN_TimerError_t Timer_Start (EN_Timers_t TimerNum, EN_PreScaler_t PreScaler, uint8_t InitialValue)
{
	switch (TimerNum)
	{
		/* Timer 0 */
		case Timer_0:
		*TCNT0 = InitialValue;
		switch (PreScaler)
		{
			case PS_1:
			SetBit  (TCCR0, 0);
			ClearBit(TCCR0, 1);
			ClearBit(TCCR0, 2);
			break;
			
			case PS_8:
			ClearBit(TCCR0, 0);
			SetBit(TCCR0, 1);
			ClearBit(TCCR0, 2);
			break;
			
			case PS_64:
			SetBit(TCCR0, 0);
			SetBit(TCCR0, 1);
			ClearBit(TCCR0, 2);
			break;
			
			case PS_256:
			ClearBit(TCCR0, 0);
			ClearBit(TCCR0, 1);
			SetBit(TCCR0, 2);
			break;
			
			case PS_1024:
			SetBit(TCCR0, 0);
			ClearBit(TCCR0, 1);
			SetBit(TCCR0, 2);
			break;
			
			default:
			return Timer_Error;
			break;
		}
		break;
		
		/* Timer 2 */
		case Timer_2:
		*TCNT2 = InitialValue;
		switch (PreScaler)
		{
			case PS_1:
			SetBit  (TCCR2, 0);
			ClearBit(TCCR2, 1);
			ClearBit(TCCR2, 2);
			break;
			
			case PS_8:
			ClearBit(TCCR2, 0);
			SetBit(TCCR2, 1);
			ClearBit(TCCR2, 2);
			break;
			
			case PS_32:
			SetBit(TCCR2, 0);
			SetBit(TCCR2, 1);
			ClearBit(TCCR2, 2);
			break;
			
			case PS_64:
			ClearBit(TCCR2, 0);
			ClearBit(TCCR2, 1);
			SetBit(TCCR2, 2);
			break;
			
			case PS_128:
			SetBit(TCCR2, 0);
			ClearBit(TCCR2, 1);
			SetBit(TCCR2, 2);
			break;
			
			case PS_256:
			ClearBit(TCCR2, 0);
			SetBit(TCCR2, 1);
			SetBit(TCCR2, 2);
			break;
			
			case PS_1024:
			SetBit(TCCR2, 0);
			SetBit(TCCR2, 1);
			SetBit(TCCR2, 2);
			break;
			
			default:
			return Timer_Error;
			break;
		}
		break;
		
		default:
		return Timer_Error;
		break;
	}
	
	return Timer_OK;
}

EN_TimerError_t Timer_Stop (EN_Timers_t TimerNum)
{
	switch (TimerNum)
	{
		case Timer_0:
		ClearBit(TCCR0, 0);
		ClearBit(TCCR0, 1);
		ClearBit(TCCR0, 2);
		break;
		
		case Timer_2:
		ClearBit(TCCR2, 0);
		ClearBit(TCCR2, 1);
		ClearBit(TCCR2, 2);
		break;
		
		default:
		return Timer_Error;
		break;
	}
	return Timer_OK;
}

EN_TimerError_t Timer_Read_OvFFlag (EN_Timers_t TimerNum, uint8_t* Value)
{
	switch (TimerNum)
	{
		case Timer_0:
		*Value = ReadBit(TIFR, 0);
		break;
		
		
		case Timer_2:
		*Value = ReadBit(TIFR, 6);
		break;
		
		default:
		return Timer_Error;
		break;
	}
	return Timer_OK;
}

EN_TimerError_t Timer_Reset (EN_Timers_t TimerNum)
{
	switch (TimerNum)
	{
		case Timer_0:
		*TCNT0 = 0x00;
		SetBit(TIFR, 0);
		SetBit(TIFR, 1);
		break;
		
		case Timer_2:
		*TCNT2 = 0x00;
		SetBit(TIFR, 6);
		SetBit(TIFR, 7);
		break;
		
		default:
		return Timer_Error;
		break;
	}
	return Timer_OK;
}

/* Creating delays in ms */
void Delay(EN_Timers_t TimerNum, uint16_t Duration)
{
	// 1- Calculates Overflows and Initial Value
	// 2- Start timer with Initial Value and prescaler
	// 3- Read overflow flag
	// 4- Stop and reset timer
	// 5- Repeat until Overflow = 0
	
	
	/* This Section calculates Overflows and Initial Value of the register */
	uint8_t InitialValue;
	double Tmax;

	Tmax = 256.0 * PS_256 / 1000.0;

	if (Duration < Tmax)
	{
		OverFlows = 1;
		InitialValue = (int)((Tmax - Duration) / (PS_256/ 1000.0));
	}
	else
	{
		OverFlows = ceil(Duration / Tmax);
		//InitialValue = (int)((1 - ((Duration / Tmax) - (int)(Duration / Tmax))) * Tmax) / OverFlows;
		InitialValue = (int)(256 - (((Duration)/(PS_256/ 1000.0)) / OverFlows));
	}
	/**********************************************************************/

	for(; OverFlows > 0; OverFlows--)
	{
		Timer_Start(TimerNum, PS_256, InitialValue);
		while(!Flag)
		{
			Timer_Read_OvFFlag(TimerNum, &Flag);
		}
		Timer_Stop(TimerNum);
		Timer_Reset(TimerNum);
		Flag = 0;
	}
}


