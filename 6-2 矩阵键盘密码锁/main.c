#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char keyNum;
unsigned int password=0;
unsigned int count;
void main()
{
	
	LCD_Init();	
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		keyNum=MatrixKey();
		if(keyNum)
		{
			
			if(keyNum<=10)
			{
				if(count<4)
				{
					password*=10;
					password+=keyNum%10;
					LCD_ShowNum(2,1,password,4);
					count++;
				}
			}
			
			if(keyNum==11)
			{
				if(password==2345)
				{
					password=0;
					count=0;
					LCD_ShowString(1,14,"OK ");
					LCD_ShowNum(2,1,password,4);
				}
				else
				{
					password=0;
					count=0;
					LCD_ShowString(1,14,"ERR");
					LCD_ShowNum(2,1,password,4);
				}
			}
			
			if(keyNum==12)
			{
				password=0;
				count=0;
				LCD_ShowString(1,14,"   ");
				LCD_ShowNum(2,1,password,4);
			}
		}
	}
}