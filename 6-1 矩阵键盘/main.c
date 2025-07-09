#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

void main()
{
	unsigned char keyNumber;
	LCD_Init();	
	while(1)
	{
		keyNumber=MatrixKey();
		if(keyNumber)
		{
			LCD_ShowNum(1,1,keyNumber,2);
		}
	}
}