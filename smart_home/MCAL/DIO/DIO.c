/*
 * DIO.c
 *
 *  Created on: Sep 16, 2026
 *      Author: Mernna Ahmed
 */
//#include "DIO.h"

#include "DIO_REG.h"
#include "DIO_type.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_type.h"

void DIO_SetPortDirection (DIO_PortID port_ID , DIO_Direction direction)
 {
	if (Output == direction)
	{
		switch(port_ID)
		{
			case PORTA: DDRA_REG = 0xff; break;
			case PORTB: DDRB_REG = 0xff; break;
			case PORTC: DDRC_REG = 0xff; break;
			case PORTD: DDRD_REG = 0xff; break;
		}
	}
	else if(Input == direction)
	{
		switch(port_ID)
		{
			case PORTA: DDRA_REG  = 0x00; break;
			case PORTB: DDRB_REG  = 0x00; break;
			case PORTC: DDRC_REG  = 0x00; break;
			case PORTD: DDRD_REG  = 0x00; break;
		}
	}
 }


void DIO_SetPortValue     (DIO_PortID port_ID , unsigned char value)
{
		switch (port_ID)
		{
			case PORTA : PORTA_REG = value ; break;
			case PORTB : PORTB_REG = value ; break;
			case PORTC : PORTC_REG = value ; break;
			case PORTD : PORTD_REG = value ; break;
		}
}


void DIO_SetPinDirection  (DIO_PortID port_ID , DIO_Pin_ID PinID , DIO_Direction direction)
{
	if (port_ID <= PORTD && PinID <= pin7 )
	{
		if(direction == Output)
		{
			switch (port_ID)
			{
				case PORTA : SETBIT (DDRA_REG , PinID) ;break;
				case PORTB : SETBIT (DDRB_REG , PinID) ;break;
				case PORTC : SETBIT (DDRC_REG , PinID) ;break;
				case PORTD : SETBIT (DDRD_REG , PinID) ;break;
			}
		}
		else if (direction == Input)
		{
			switch (port_ID)
			{
				case PORTA : CLEARBIT (DDRA_REG , PinID) ;break;
				case PORTB : CLEARBIT (DDRB_REG , PinID) ;break;
				case PORTC : CLEARBIT (DDRC_REG , PinID) ;break;
				case PORTD : CLEARBIT (DDRD_REG , PinID) ;break;
			}
		}
	}
}


void DIO_SetPinValue      (DIO_PortID port_ID , DIO_Pin_ID PinID , STD_LevelType value)
{
	if (port_ID <= PORTD && PinID <= pin7)
	{
		if (value == High)
		{
			switch (port_ID)
			{
				case PORTA: SETBIT(PORTA_REG , PinID) ;break;
				case PORTB: SETBIT(PORTB_REG , PinID) ;break;
				case PORTC: SETBIT(PORTC_REG , PinID) ;break;
				case PORTD: SETBIT(PORTD_REG , PinID) ;break;
			}
		}
		else if (value == Low)
		{
			switch (port_ID)
			{
				case PORTA: CLEARBIT(PORTA_REG , PinID) ;break;
				case PORTB: CLEARBIT(PORTB_REG , PinID) ;break;
				case PORTC: CLEARBIT(PORTC_REG , PinID) ;break;
				case PORTD: CLEARBIT(PORTD_REG , PinID) ;break;
			}
		}
	}
}


STD_LevelType DIO_GetPinValue (DIO_PortID port_ID , DIO_Pin_ID PinID )
{
	STD_LevelType PinValue;
	if (port_ID <= PORTD && PinID <= pin7)
	{
		switch(port_ID)
		{
			case PORTA: PinValue = GETBIT(PINA_REG , PinID) ;break;
			case PORTB: PinValue = GETBIT(PINB_REG , PinID) ;break;
			case PORTC: PinValue = GETBIT(PINC_REG , PinID) ;break;
			case PORTD: PinValue = GETBIT(PIND_REG , PinID) ;break;
		}
	}
	return PinValue;
}

