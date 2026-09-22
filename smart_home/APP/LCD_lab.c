/*
 * LCD_lab.c
 *
 *  Created on: Sep 22, 2026
 *      Author: Mernna Ahmed
 */
#include <avr/delay.h>

void LCD_LAP()
{
	LCD_initilization();
	LCD_WriteData('M');
	LCD_WriteData('E');
	LCD_WriteData('R');
	LCD_WriteData('N');
	LCD_WriteData('A');
	_delay_ms(3000);
	LCD_Writecmd(0x01);
}
