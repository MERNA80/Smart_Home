/*
 * seven_segment.c
 *
 *  Created on: Sep 18, 2026
 *      Author: Mernna ahmed
 */

#include "../../LIB/STD_type.h"
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO_type.h"
#include "../../MCAL/DIO/DIO.h"

void Seven_segment_Initialization()
{
	DIO_SetPinDirection(PORTA , pin4 , Output);   //A
	DIO_SetPinDirection(PORTA , pin5 , Output);   //B
	DIO_SetPinDirection(PORTA , pin6 , Output);   //C
	DIO_SetPinDirection(PORTA , pin7 , Output);   //D

	DIO_SetPinDirection(PORTB , pin2 , Output);
	DIO_SetPinDirection(PORTB , pin1 , Output);
}



void Seven_segment_Write_Number(unsigned char number)
{
	if (number < 10)
	{
		//3  0000 0011
        //        DBCA
		DIO_SetPinValue(PORTA , pin4 , GETBIT(number , 0));  //A
		DIO_SetPinValue(PORTA , pin5 , GETBIT(number , 1));  //B
		DIO_SetPinValue(PORTA , pin6 , GETBIT(number , 2));  //C
		DIO_SetPinValue(PORTA , pin7 , GETBIT(number , 3));  //D
	}

}



void Seven_segment_Enable1()
{
	DIO_SetPinValue(PORTB , pin2 , High);
}

void Seven_segment_Enable2()
{
	DIO_SetPinValue(PORTB , pin1 , High);
}

void Seven_segment_Disable1()
{
	DIO_SetPinValue(PORTB , pin2 , Low);
}

void Seven_segment_Disable2()
{
	DIO_SetPinValue(PORTB , pin1 , Low);
}
