/*
 * BUTTON_PROGRAM.c
 *
 *  Created on: ???/???/????
 *      Author: ??? ????
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_INTERFACE.h"
#include "../MCAL/DIO_PRIVATE.h"
#include "BUTTON_INTERFACE.h"

void BUTTON_VoidInIt (BUTTON_t* Copy_PstructButton){
	DIO_voidSetPinDirection ( Copy_PstructButton->Port ,  Copy_PstructButton->Pin , DIO_PIN_INPUT);
	DIO_voidSetPinValue (Copy_PstructButton->Port ,  Copy_PstructButton->Pin , DIO_PIN_HIGH);

}


u8 BUTTON_u8GetState (BUTTON_t* Copy_PstructButton){
	return DIO_u8GetPinValue (Copy_PstructButton->Port , Copy_PstructButton->Pin);
}










