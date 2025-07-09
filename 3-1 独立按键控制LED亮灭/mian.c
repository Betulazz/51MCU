#include <REGX52.H>

void main()
{
	P2_0=0;
	while(1)
	{
		if(P3_1==0)	//╟╢об
		{
			P2_0=0;
		}
		if(P3_1==1)	//ки©╙
		{
			P2_0=1;
		}
	}
}