#include <REGX52.H>
#include "Delay.h"
sbit RCK=P3^5;		//上升沿锁存
sbit SCK=P3^6;		//上升沿移位
sbit SER=P3^4;

#define MATRIX_LED_PORT P0

void _74HC585_WriteByte(unsigned char byte)
{
	unsigned int i;
	for(i=0;i<8;i++)
	{
		SER=byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}

void MatrixLED_ShowColumn(unsigned char column,unsigned char val)
{
	_74HC585_WriteByte(val);
	MATRIX_LED_PORT=~(0x80>>column);
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}