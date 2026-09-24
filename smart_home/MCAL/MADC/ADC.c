/*
 * ADC.c
 *
 *  Created on: Sep 24, 2026
 *      Author: Person 4 (Temperature & AC)
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"

#include "ADC.h"

void MADC_voidInit (void)
{
	ADMUX  = 0x40 ;   /* AVCC (5V) reference, right adjust */
	ADCSRA = 0x86 ;   /* Enable ADC, prescaler 64 -> 8MHz/64 = 125kHz */
}

u16 MADC_u16ReadChannel (u8 A_u8Channel)
{
	ADMUX = (ADMUX & 0xE0) | (A_u8Channel & 0x07) ;   /* select channel */

	SET_BIT(ADCSRA , 6) ;                      /* start conversion */
	while (READ_BIT(ADCSRA , 6) == 1) ;        /* wait until done  */

	return ADCL | ((u16)ADCH << 8) ;           /* ADCL must be read first */
}
