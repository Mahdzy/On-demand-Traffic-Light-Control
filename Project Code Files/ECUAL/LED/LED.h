/*
* File:		LED.h
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/Timer/Timer.h"

extern uint16_t Counter;

typedef enum EN_LEDError_t {LED_OK, LED_Error} EN_LEDError_t;

EN_LEDError_t LED_Init(EN_PortNo_t LEDPort, uint8_t LEDPin);
EN_LEDError_t LED_On(EN_PortNo_t LEDPort, uint8_t LEDPin);
EN_LEDError_t LED_Off(EN_PortNo_t LEDPort, uint8_t LEDPin);
EN_LEDError_t LED_Toggle(EN_PortNo_t LEDPort, uint8_t LEDPin);
EN_LEDError_t LED_Blink(EN_PortNo_t LEDPort, uint8_t LEDPin, uint16_t PlinkTime, uint16_t TotalTime);
EN_LEDError_t Two_LEDs_Blink(EN_PortNo_t LEDPort1, uint8_t LEDPin1, EN_PortNo_t LEDPort2, uint8_t LEDPin2, uint16_t PlinkTime, uint16_t TotalTime);

EN_LEDError_t LED_Blink2(EN_PortNo_t LEDPort, uint8_t LEDPin, uint16_t PlinkTime, uint16_t TotalTime);

#endif /* LED_H_ */