#include <REGX52.H>
#include "LCD1602.h"
#include "Timer0.h"
unsigned int sec,min,hour;
void main()
{
	timer0_Init();
	LCD_Init();
	LCD_ShowString(1,1,"CLOCK:");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
	}
}


void timer0_Routine() interrupt 1
{
	static unsigned int t0Count;
	TH0=0xFC;
	TL0=0x18;
	t0Count++;
	if(t0Count==1000)
	{
		t0Count=0;
		sec++;
		if(sec==60)
		{
			sec=0;
			min++;
			if(min==60)
			{
				min=0;
				hour++;
				if(hour==24)
				{
					hour=0;
				}
			}
		}
	}
}