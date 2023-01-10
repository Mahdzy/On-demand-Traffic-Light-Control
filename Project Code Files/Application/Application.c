/*
* File:		Application.c
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
 */ 

#include "Application.h"

EN_Mode_t Modes[4] = {NormaLGreen, NormaLYellow, NormaLRed, NormaLYellow}; // Array of Traffic light modes
uint8_t NextMode = 0; // Stores the next mode to be executed
uint8_t CurrentLight = 0; // Controls NextMode
uint8_t PedestrianState = NotRunning; // Stores the State of the Pedestrian mode

void App_Init(void)
{
	/* Initiating Button with INT0 Pin */
	Button_Init(D, 2); // 
	
	/* Initiating LEDs for Port A and B with Pins 0, 1 an 2 */
	for(uint8_t Port = 0; Port < 2; Port++)
	{
		for(uint8_t Pin = 0; Pin < 3; Pin++)
		{
			LED_Init(Port, Pin);
		}
	}
	
	/* Initiating Timer 0 and Timer 2 */
	Timer_Init(Timer_0, Normal, Internal); // Initiating
	Timer_Init(Timer_2, Normal, Internal); // Initiating 
	
	/* Enabling Global Interrupts and Initiating External Interrupt 0 */
	GlobalInt_En();
	ExtInt_Init(Int_0, R_Edge);
	
	/* Sending addresses of mode and state to INT0 ISR */
	GetState(&NextMode, &CurrentLight, &PedestrianState);
}

void App_Start(void)
{
	// 1- Starts with normal mode
	// 2- If request is triggered check if current light is
	// Green: Turns Pedestrian red light until cars green light is off, then blinks both cars and pedestrian yellow lights for five sec, then turns on cars red light and turns off pedestrian green light
	// Yellow: Blinks both cars and pedestrian yellow lights for five sec, then turns on cars red light and turns off pedestrian green light
	// Red: Keeps on cars red light and turns off pedestrian green light
	// 3- Blinks cars yellow light for five sec
	// 4- Returns to Normal mode
	
	switch(NextMode)
	{
		/* Normal Green Mode*/
		case NormaLGreen:
		CurrentLight = (CurrentLight + 1) % 4;
		NextMode = Modes[CurrentLight];
		LED_On(A, Green);
		Delay(Timer_0, 5000);
		LED_Off(A, Green);
		break;
		
		/* Normal Yellow Mode*/
		case NormaLYellow:
		CurrentLight = (CurrentLight + 1) % 4;
		NextMode = Modes[CurrentLight];
		LED_Blink(A, Yellow, 250, 5000);
		LED_Off(A, Yellow);
		break;
		
		/* Normal Red Mode*/
		case NormaLRed:
		CurrentLight = (CurrentLight + 1) % 4;
		NextMode = Modes[CurrentLight];
		LED_On(A, Red);
		Delay(Timer_0, 5000);
		LED_Off(A, Red);
		break;
		
		/* Pedestrian Mode*/
		case Pedestrian:
		if (CurrentLight == 3)
		{
			LED_On(A, Red);
			LED_On(B, Green);
			Delay(Timer_0, 5000);
			LED_Off(A, Red);
			LED_Off(B, Green);
		}
		else if (CurrentLight == 2)
		{	
			Two_LEDs_Blink(A, Yellow, B, Yellow, 250, 5000);
			LED_Off(A, Yellow);
			LED_Off(B, Yellow);
			LED_On(A, Red);
			LED_On(B, Green);
			Delay(Timer_0, 5000);
			LED_Off(A, Red);
			LED_Off(B, Green);
		}
		else if (CurrentLight == 1)
		{
			LED_Off(B, Red);
			Two_LEDs_Blink(A, Yellow, B, Yellow, 250, 5000);
			LED_Off(A, Yellow);
			LED_Off(B, Yellow);
			LED_On(A, Red);
			LED_On(B, Green);
			Delay(Timer_0, 5000);
			LED_Off(A, Red);
			LED_Off(B, Green);
		}
		
		LED_Blink(A, Yellow, 250, 5000);
		LED_Off(A, Yellow);
		NextMode = NormaLGreen;
		CurrentLight = 0;
		PedestrianState = NotRunning;
		break;
	}
}