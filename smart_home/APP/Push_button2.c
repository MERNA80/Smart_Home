/*
 * Push_button2.c
 *
 *  Created on: Sep 18, 2026
 *      Author: Menna Allah
 */

#include "../LIB/STD_type.h"
#include "../MCAL/DIO/DIO_type.h"
#include "../MCAL/DIO/DIO.h"
#include <avr/delay.h>

void Push_button2()
{
	DIO_SetPinDirection(PORTD , pin1 , Output);
	DIO_SetPinDirection(PORTD , pin2 , Output);
	DIO_SetPinDirection(PORTD , pin3 , Output);

	DIO_SetPinDirection(PORTC , pin1 , Input);
	DIO_SetPinDirection(PORTC , pin2 , Input);
	DIO_SetPinDirection(PORTC , pin3 , Input);

	while(1)
	{
		STD_LevelType Button1_value =DIO_GetPinValue(PORTC , pin1);
		STD_LevelType Button2_value =DIO_GetPinValue(PORTC , pin2);
		STD_LevelType Button3_value =DIO_GetPinValue(PORTC , pin3);

		if (Button1_value == High && Button2_value == Low && Button3_value == Low)
	    {
			DIO_SetPinValue(PORTD , pin1 , High);
			DIO_SetPinValue(PORTD , pin2 , High);
			DIO_SetPinValue(PORTD , pin3 , High);
	    }
		else if(Button1_value == Low && Button2_value == High && Button3_value == Low)
		{
			DIO_SetPinValue(PORTD , pin1 , High);
			DIO_SetPinValue(PORTD , pin2 , Low);
			DIO_SetPinValue(PORTD , pin3 , Low);
			_delay_ms(100);

			DIO_SetPinValue(PORTD , pin1 , Low);
			DIO_SetPinValue(PORTD , pin2 , High);
			DIO_SetPinValue(PORTD , pin3 , Low);
	   	    _delay_ms(100);

			DIO_SetPinValue(PORTD , pin1 , Low);
			DIO_SetPinValue(PORTD , pin2 , Low);
			DIO_SetPinValue(PORTD , pin3 , High);
	   	    _delay_ms(100);
		}
		else if(Button1_value == Low && Button2_value == Low && Button3_value == High)
		{
			DIO_SetPinValue(PORTD , pin1 , Low);   //000
			DIO_SetPinValue(PORTD , pin2 , Low);
			DIO_SetPinValue(PORTD , pin3 , Low);
			_delay_ms(1000);

			DIO_SetPinValue(PORTD , pin1 , Low);   //001
			DIO_SetPinValue(PORTD , pin2 , Low);
			DIO_SetPinValue(PORTD , pin3 , High);
			_delay_ms(1000);

			DIO_SetPinValue(PORTD , pin1 , Low);    //010
			DIO_SetPinValue(PORTD , pin2 , High);
			DIO_SetPinValue(PORTD , pin3 , Low);
	   	    _delay_ms(1000);

			DIO_SetPinValue(PORTD , pin1 , Low);   //011
			DIO_SetPinValue(PORTD , pin2 , High);
			DIO_SetPinValue(PORTD , pin3 , High);
	   	    _delay_ms(1000);

			DIO_SetPinValue(PORTD , pin1 , High);  //100
			DIO_SetPinValue(PORTD , pin2 , Low);
			DIO_SetPinValue(PORTD , pin3 , Low);
	   	    _delay_ms(1000);

			DIO_SetPinValue(PORTD , pin1 , High);   //101
			DIO_SetPinValue(PORTD , pin2 , Low);
			DIO_SetPinValue(PORTD , pin3 , High);
	   	    _delay_ms(1000);

			DIO_SetPinValue(PORTD , pin1 , High);   //110
			DIO_SetPinValue(PORTD , pin2 , High);
			DIO_SetPinValue(PORTD , pin3 , Low);
			_delay_ms(1000);

			DIO_SetPinValue(PORTD , pin1 , High);   //111
			DIO_SetPinValue(PORTD , pin2 , High);
			DIO_SetPinValue(PORTD , pin3 , High);
			_delay_ms(1000);
		}
		else
		{
			DIO_SetPinValue(PORTD , pin1 , Low);
			DIO_SetPinValue(PORTD , pin2 , Low);
			DIO_SetPinValue(PORTD , pin3 , Low);
		}
	}
}
