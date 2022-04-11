#include "ap.h"


void apInit()
{
	//lcdBegin(_DEF_LCD1);
	//lcdBegin(_DEF_LCD2);
	
 
	//uartOpen(_DEF_UART1, 38400);
	cliOpen(_DEF_UART1, 38400);

	//imuBegin(50);
}


void apMain()
{
	uint32_t pre_time = millis();
	uint32_t loop_us = 0;

	float *rpy;

	while(1)	
	{
		/*
		if (millis() - pre_time >= 500)
		{
			uartPrintf(_DEF_UART1, "%ld\n", micros());
			pre_time = millis();
		}
		*/


		//imuUpdate();
		//rpy = imuGetRPY();
		//uartPrintf(_DEF_UART1, "%ld, %ld, %ld\n", (int)rpy[0], (int)rpy[1], (int)rpy[2]);

		cliMain();
	}
}
