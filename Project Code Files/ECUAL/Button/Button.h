/*
* File:		Button.h
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/GPIO/GPIO.h"

typedef enum EN_ButtonError_t {Button_OK, Button_Error} EN_ButtonError_t;
typedef enum EN_ButtonState_t {Pressed, Unpressed} EN_ButtonState_t;

EN_ButtonError_t Button_Init(EN_PortNo_t ButtonPort, uint8_t ButtonPin);
EN_ButtonError_t Button_Read(EN_PortNo_t ButtonPort, uint8_t ButtonPin, uint8_t* ButtonState);

#endif /* BUTTON_H_ */