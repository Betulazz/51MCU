#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.h>
unsigned int keyNum,LEDMode;
void main()
{
	timer0_Init();
	P2=0xFE;
	while(1)
	{
		keyNum=key();
		if(keyNum)
		{
			if(keyNum==1)
			{
				LEDMode++;
				if(LEDMode==2)
					LEDMode=0;
			}
		}
	}	
}

void timer0_Routine() interrupt 1
{
	static unsigned int t0Count;
	TH0=0xFC;
	TL0=0x18;
	t0Count++;
	if(t0Count==500)
	{
		t0Count=0;
		if(LEDMode==0)
			P2=_crol_(P2,1);
		if(LEDMode==1)
			P2=_cror_(P2,1);
	}
}