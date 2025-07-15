#ifndef __DS1302_H__
#define __DS1302_H__

extern char DS1302_Time[];

void DS1302_Init();
void DS1302_WriteByte(unsigned char command,unsigned char val);
unsigned char DS1302_ReadByte(unsigned char command);
void DS1302_SetTime();	
void DS1302_ReadTime();	
	
#endif