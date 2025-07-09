#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;
		UART_SendByte(SBUF);
		RI=0;
	}
}

void main()
{
	UART_Init();
	while(1)
	{
		
	}
}