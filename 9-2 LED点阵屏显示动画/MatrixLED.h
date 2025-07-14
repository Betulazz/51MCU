#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__

void _74HC585_WriteByte(unsigned char byte);
void MatrixLED_Init();
void MatrixLED_ShowColumn(unsigned char column,unsigned char val);

#endif