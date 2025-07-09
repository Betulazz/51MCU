#ifndef __TIMER0_H__
#define __TIMER0_H__

void timer0_Init();

#endif

/*
void timer0_Routine() interrupt 1
{
	static unsigned int t0Count;
	TH0=0xFC;
	TL0=0x18;
	t0Count++;
	if(t0Count==1000)
	{
		t0Count=0;
	}
*/