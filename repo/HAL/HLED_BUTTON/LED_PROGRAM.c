/*
 * LED_PROGRAM.c
 *
 *  Created on: ???/???/????
 *      Author: ??? ????
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "../../MCAL/MDIO/DIO.h"
#include "LED_INTERFACE.h"

void LED_VoidInIt (LED_t* Copy_PstructLED) {
	MDIO_voidInitPin  ( Copy_PstructLED->Port , Copy_PstructLED->Pin ,  DIO_OUTPUT ) ;
	MDIO_voidSetPinValue ( Copy_PstructLED->Port , Copy_PstructLED->Pin ,  DIO_LOW);
}

void LED_VoidTurnOn(LED_t* Copy_PstructLED) {
	MDIO_voidSetPinValue(Copy_PstructLED->Port, Copy_PstructLED->Pin, DIO_HIGH);
}

void LED_VoidTurnOff(LED_t* Copy_PstructLED) {
	MDIO_voidSetPinValue(Copy_PstructLED->Port, Copy_PstructLED->Pin, DIO_LOW);
}

void LED_VoidToggle(LED_t* Copy_PstructLED) {
	MDIO_voidTogPin(Copy_PstructLED->Port, Copy_PstructLED->Pin);
}


