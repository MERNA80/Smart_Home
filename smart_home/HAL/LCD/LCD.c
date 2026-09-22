/*
 * LCD.c
 *
 *  Created on: Sep 22, 2026
 *      Author: Mernna Ahmed
 */

#include <avr/delay.h>
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_type.h"
#include "../../MCAL/DIO/DIO_type.h"
#include "../../MCAL/DIO/DIO.h"

static uint8 InitStepFinish = 0;

void LCD_initilization(void)
{
	DIO_SetPortDirection(PORTA , Output);
	DIO_SetPortDirection(PORTB , Output);

	_delay_ms(30);

	LCD_Writecmd(0x20);
	LCD_Writecmd(0x20);
	LCD_Writecmd(0x80);
	_delay_ms(1);

	LCD_Writecmd(0x00);
	LCD_Writecmd(0x00);
	LCD_Writecmd(0xf0);
	_delay_ms(1);

	LCD_Writecmd(0x00);
	LCD_Writecmd(0x10);
	_delay_ms(2);

	InitStepFinish = 1;
}

void LCD_Writecmd(uint8 cmd)
{
	//cmd 0000 0000
	//    0010 0000
	DIO_SetPinValue(PORTB , pin1 ,Low);   //RS=0
	DIO_SetPinValue(PORTB , pin2 ,Low);   //RW=0

	DIO_SetPinValue(PORTA , pin4 , GETBIT(cmd , 4));
	DIO_SetPinValue(PORTA , pin5 , GETBIT(cmd , 5));
	DIO_SetPinValue(PORTA , pin6 , GETBIT(cmd , 6));
	DIO_SetPinValue(PORTA , pin7 , GETBIT(cmd , 7));

	DIO_SetPinValue(PORTB , pin3 ,High);
	_delay_ms(1);
	DIO_SetPinValue(PORTB , pin3 ,Low);

	if (InitStepFinish)
	{
		DIO_SetPinValue(PORTA , pin4 , GETBIT(cmd , 0));
		DIO_SetPinValue(PORTA , pin5 , GETBIT(cmd , 1));
		DIO_SetPinValue(PORTA , pin6 , GETBIT(cmd , 2));
		DIO_SetPinValue(PORTA , pin7 , GETBIT(cmd , 3));

		DIO_SetPinValue(PORTB , pin3 ,High);
		_delay_ms(1);
		DIO_SetPinValue(PORTB , pin3 ,Low);
	}
	_delay_ms(2);

}

void LCD_WriteData(uint8 data)
{
	    DIO_SetPinValue(PORTB , pin1 , High);   //RS=1
		DIO_SetPinValue(PORTB , pin2 , Low);   //RW=0

		DIO_SetPinValue(PORTA , pin4 , GETBIT(data , 4));
		DIO_SetPinValue(PORTA , pin5 , GETBIT(data , 5));
		DIO_SetPinValue(PORTA , pin6 , GETBIT(data , 6));
		DIO_SetPinValue(PORTA , pin7 , GETBIT(data , 7));

		DIO_SetPinValue(PORTB , pin3 ,High);
		_delay_ms(1);
		DIO_SetPinValue(PORTB , pin3 ,Low);


		DIO_SetPinValue(PORTA , pin4 , GETBIT(data , 0));
		DIO_SetPinValue(PORTA , pin5 , GETBIT(data , 1));
		DIO_SetPinValue(PORTA , pin6 , GETBIT(data , 2));
		DIO_SetPinValue(PORTA , pin7 , GETBIT(data , 3));

		DIO_SetPinValue(PORTB , pin3 ,High);
		_delay_ms(1);
		DIO_SetPinValue(PORTB , pin3 ,Low);

		_delay_ms(2);
}
