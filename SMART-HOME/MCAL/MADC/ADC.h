/*
 * ADC.h
 *
 *  Created on: Sep 24, 2026
 *      Author: Person 4 (Temperature & AC)
 */

#ifndef MCAL_MADC_ADC_H_
#define MCAL_MADC_ADC_H_

#include "../../LIB/STD_types.h"

#define ADMUX    (*((volatile u8*)(0x27)))
#define ADCSRA   (*((volatile u8*)(0x26)))
#define ADCH     (*((volatile u8*)(0x25)))
#define ADCL     (*((volatile u8*)(0x24)))

#define ADC_CHANNEL0   0

void MADC_voidInit       (void) ;
u16  MADC_u16ReadChannel (u8 A_u8Channel) ;

#endif /* MCAL_MADC_ADC_H_ */
