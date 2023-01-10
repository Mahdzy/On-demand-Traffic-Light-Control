/*
* File:		Timer.h
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <math.h>
#include "../../Registers.h"
#include "../../BitManip.h"

extern uint32_t OverFlows;
extern uint8_t Flag;

typedef enum EN_TimerError_t {Timer_OK, Timer_Error} EN_TimerError_t;
typedef enum EN_Timers_t {Timer_0, Timer_1, Timer_2} EN_Timers_t;
typedef enum EN_TimerMode_t {Normal, CTC, Fast_PWM, Correct_PWM} EN_TimerMode_t;
typedef enum EN_Clock_t {Internal, External_R_Edge, External_F_Edge, Asynchronous} EN_Clock_t;
typedef enum EN_PreScaler_t {No_PS, PS_1 = 1, PS_8 =  8, PS_32 = 32, PS_64 = 64, PS_128 = 128, PS_256 = 256, PS_1024 = 1024} EN_PreScaler_t;

EN_TimerError_t Timer_Init (EN_Timers_t TimerNum, EN_TimerMode_t Mode, EN_Clock_t ClkSrc);
EN_TimerError_t Timer_Start (EN_Timers_t TimerNum, EN_PreScaler_t PreScaler, uint8_t InitialValue);
EN_TimerError_t Timer_Stop (EN_Timers_t TimerNum);
EN_TimerError_t Timer_Read_OvFFlag (EN_Timers_t TimerNum, uint8_t* Value);
EN_TimerError_t Timer_Reset (EN_Timers_t TimerNum);
void Delay (EN_Timers_t TimerNum, uint16_t Duration);

#endif /* TIMER_H_ */