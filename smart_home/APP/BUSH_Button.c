/*
 * BUSH_Button.c
 *
 *  Created on: Sep 18, 2026
 *      Author: Mernna AHmed
 */

#include "../LIB/STD_type.h"
#include "../MCAL/DIO/DIO_type.h"
#include "../MCAL/DIO/DIO.h"

void Push_button()
{
	DIO_SetPinDirection(PORTC , pin2 , Input);
	DIO_SetPinDirection(PORTD , pin3 , Output);
	while (1)
	{
//		DIO_value Pin_value =DIO_GetPinValue(PORTC , pin2);   or
//		if (Pin_value == High)
		if (DIO_GetPinValue(PORTC , pin2) == High)
		{
			DIO_SetPinValue(PORTD , pin3 , High);
		}
		else if (DIO_GetPinValue(PORTC , pin2) == Low)
		{
			DIO_SetPinValue(PORTD , pin3 , Low);
		}
	}

}
