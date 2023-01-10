/*
 * File:	main.c
 * Project:	On demand Traffic Light Control
 * Author:	Abdelrahman Almahdy
 */ 


#include "Application/Application.h"

int main(void)
{
	App_Init();

	while(1)
	{
		App_Start();
	}
	
	return 0;
}

