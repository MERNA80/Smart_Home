/*
 * LED.c
 *
 *  Created on: Sep 17, 2026
 *      Author: Mernnah Ahmed
 */
#include "../LIB/STD_type.h"
#include "../MCAL/DIO/DIO_type.h"
#include "../MCAL/DIO/DIO.h"


void LED()
{
	DIO_SetPortDirection(PORTC , Output);
	DIO_SetPortValue(PORTC , 0xff);

	DIO_SetPinDirection(PORTD , pin2 , Output);
	DIO_SetPinValue(PORTD , pin2 , High);
}
