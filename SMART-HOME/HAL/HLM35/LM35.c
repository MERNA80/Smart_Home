/*
 * LM35.c
 *
 *  Created on: Sep 24, 2026
 *      Author: Person 4 (Temperature & AC)
 */

#include "../../LIB/STD_types.h"

#include "../../MCAL/MADC/ADC.h"

#include "LM35.h"

void HLM35_voidInit (void)
{
	MADC_voidInit() ;
}

u8 HLM35_u8GetTemperature (void)
{
	u16 L_u16Digital = MADC_u16ReadChannel(LM35_ADC_CHANNEL) ;

	/* mV = Digital * 5000 / 1024 , Temp = mV / 10 (u32 to avoid overflow, +512 to round) */
	return (u8)(((u32)L_u16Digital * 500 + 512) / 1024) ;
}
