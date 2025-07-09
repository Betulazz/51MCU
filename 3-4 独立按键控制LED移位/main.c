#include <REGX52.H>

void Delay(unsigned int xms)		
{
	unsigned char i, j;
	
	while(xms)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	unsigned char LEDNum=0;
	
	P2=~0x01;
	
	while(1)
	{
		//¿ØÖÆ×óÒÆ
		if(P3_1==0)
		{
			Delay(30);
			while(P3_1==0)
			Delay(30);
			
			if(LEDNum==7)
			{
				LEDNum=0;
			}
			else
			{
				LEDNum++;
			}
			P2=~(0x01<<LEDNum);
		}
		//¿ØÖÆÓÒÒÆ
		if(P3_0==0)
		{
			Delay(30);
			while(P3_0==0)
			Delay(30);
			
			if(LEDNum==0)
			{
				LEDNum=7;
			}
			else
			{
				LEDNum--;
			}
			P2=~(0x01<<LEDNum);			
		}
	}
}