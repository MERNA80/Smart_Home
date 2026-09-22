/*
 * KP.c
 *
 *  Created on: Sep 19, 2026
 *      Author: Mernna Ahmed
 */



#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_type.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/STD_type.h"

#include "KP.h"
#include "util/delay.h"

//static unit8 GSR_u8KpData [4][4] =
//{
//		{'7' , '4' , '1' , 'C'} ,
//		{'8' , '5' , '2' , '0'} ,
//		{'9' , '6' , '3' , '='} ,
//		{'/' , '*' , '-' , '+'}
//};

void KP_intitilazation (void)
{
	DIO_SetPinDirection(PORTC , pin0 , Output);
	DIO_SetPinDirection(PORTC , pin1 , Output);
	DIO_SetPinDirection(PORTC , pin2 , Output);
	DIO_SetPinDirection(PORTC , pin3 , Output);

	DIO_SetPinDirection(PORTD , pin0 , Input);
	DIO_SetPinDirection(PORTD , pin1 , Input);
	DIO_SetPinDirection(PORTD , pin2 , Input);
	DIO_SetPinDirection(PORTD , pin3 , Input);
}

uint8 Keypad_getKey(void)
{
	uint8 key = 0;
	return key;
}

