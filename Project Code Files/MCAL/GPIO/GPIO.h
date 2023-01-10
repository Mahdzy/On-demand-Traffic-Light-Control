/*
 * File:	GPIO.h
 * Project:	On demand Traffic Light Control
 * Author:	Abdelrahman Almahdy
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "../../Registers.h"
#include "../../BitManip.h"
#include "../Interrupts/Interrupts.h"
#include "../Timer/Timer.h"

typedef enum EN_GPIOState_t {GPIO_OK, Init_Error, Write_Error, Read_Error, Toggle_Error} EN_GPIOState_t;
typedef enum EN_PortNo_t {A, B, C, D} EN_PortNo_t;
typedef enum EN_PortDirection_t {Input, Output} EN_PortDirection_t;
typedef enum EN_Value_t {Low, High} EN_Value_t;
	 
EN_GPIOState_t GPIO_Init (EN_PortNo_t Port, uint8_t Pin, EN_PortDirection_t Direction);
EN_GPIOState_t GPIO_Write (EN_PortNo_t Port, uint8_t Pin, uint8_t Value);
EN_GPIOState_t GPIO_Toggle (EN_PortNo_t Port, uint8_t Pin);
EN_GPIOState_t GPIO_Read (EN_PortNo_t Port, uint8_t Pin, uint8_t* Reading);
void GetState(uint8_t* Ptr1, uint8_t* Ptr2, uint8_t* Ptr3);
void GetCounter(uint16_t* Ptr);

#endif /* GPIO_H_ */