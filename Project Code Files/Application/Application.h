/*
* File:		Application.h
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/Button/Button.h"
#include "../ECUAL/LED/LED.h"

typedef enum EN_Mode_t {NormaLGreen, NormaLYellow, NormaLRed, Pedestrian } EN_Mode_t;
typedef enum EN_Light_t {Green, Yellow, Red} EN_Light_t;
typedef enum EN_PedestrianState_t {Running, NotRunning} EN_PedestrianState_t;

void App_Init(void);
void App_Start(void);

#endif /* APPLICATION_H_ */