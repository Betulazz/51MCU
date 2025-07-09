#include <REGX52.H>

void timer0_Init()
{
	TMOD&=0xF0;		//前四位不变后四位置零
	//M1 M0:1 0 且GATE为0 C/T为0 
	TMOD|=0x01;		//前四位不变最后一位置1
	TF0=0;
	TR0=1;
	//给定时器初值，1ms
	TH0=0xFC;
	TL0=0x18;
	ET0=1;
	EA=1;
	PT0=0;		//优先级
}