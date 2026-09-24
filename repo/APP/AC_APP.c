/*
 * AC_APP.c
 *
 *  Created on: Sep 24, 2026
 *      Author: Person 4 (Temperature & AC)
 */

#include "../LIB/STD_types.h"

#include "../HAL/HLM35/LM35.h"

#include "AC_APP.h"

static u8 G_u8Temp = 0 ;
static u8 G_u8Mode = AC_MODE_STOP ;

void AC_App_voidInit (void)
{
	HLM35_voidInit() ;
}

void AC_App_voidUpdate (u8 A_u8ACStatus)
{
	if (A_u8ACStatus == 0)              /* AC OFF -> everything disabled */
	{
		G_u8Mode = AC_MODE_STOP ;
		return ;
	}

	G_u8Temp = HLM35_u8GetTemperature() ;

	if      (G_u8Temp < AC_HEATING_TEMP) G_u8Mode = AC_MODE_HEATING ;
	else if (G_u8Temp > AC_COOLING_TEMP) G_u8Mode = AC_MODE_COOLING ;
	else                                 G_u8Mode = AC_MODE_STOP ;
}

u8 AC_App_u8GetMode (void)
{
	return G_u8Mode ;
}

u8 AC_App_u8GetTemperature (void)
{
	return G_u8Temp ;
}
