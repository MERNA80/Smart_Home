/*
 * LED_PROGRAM.c
 *
 *  Created on: ???/???/????
 *      Author: ??? ????
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_INTERFACE.h"
#include "LED_INTERFACE.h"

void LED_VoidInIt (LED_t* Copy_PstructLED) {
	DIO_voidSetPinDirection ( Copy_PstructLED->Port , Copy_PstructLED->Pin ,  DIO_PIN_OUTPUT ) ;
	DIO_voidSetPinValue ( Copy_PstructLED->Port , Copy_PstructLED->Pin ,  DIO_PIN_LOW);
}

void LED_VoidTurnOn(LED_t* Copy_PstructLED) {
    DIO_voidSetPinValue(Copy_PstructLED->Port, Copy_PstructLED->Pin, DIO_PIN_HIGH);
}

void LED_VoidTurnOff(LED_t* Copy_PstructLED) {
    DIO_voidSetPinValue(Copy_PstructLED->Port, Copy_PstructLED->Pin, DIO_PIN_LOW);
}

void LED_VoidToggle(LED_t* Copy_PstructLED) {
    DIO_voidTogglePinValue(Copy_PstructLED->Port, Copy_PstructLED->Pin);
}


