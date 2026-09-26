/*
 * AC_APP.c
 *
 *  Created on: Sep 24, 2026
 *      Author: Person 4 (Temperature & AC)
 */

#include "../LIB/STD_types.h"

#include "../HAL/HLM35/LM35.h"
#include "../HAL/HDC_MOTOR/MOTOR.h"
#include "../MCAL/MDIO/DIO.h"

#include "AC_APP.h"

#define MOTOR_IN1_PORT   DIO_PORTD
#define MOTOR_IN1_PIN    DIO_PIN5
#define MOTOR_IN2_PORT   DIO_PORTD
#define MOTOR_IN2_PIN    DIO_PIN6

static u8 G_u8Temp = 0 ;
static u8 G_u8Mode = AC_MODE_STOP ;

void AC_App_voidInit (void)
{
	HLM35_voidInit() ;
	HDC_Motor_voidInit(MOTOR_IN1_PORT, MOTOR_IN1_PIN, MOTOR_IN2_PORT, MOTOR_IN2_PIN) ;
}

void AC_App_voidUpdate (u8 A_u8ACStatus)
{
	if (A_u8ACStatus == 0)              /* AC OFF -> everything disabled */
	{
		G_u8Mode = AC_MODE_STOP ;
		HDC_Motor_voidControl(AC_MODE_STOP, MOTOR_IN1_PORT, MOTOR_IN1_PIN, MOTOR_IN2_PORT, MOTOR_IN2_PIN) ;
		return ;
	}

	G_u8Temp = HLM35_u8GetTemperature() ;

	if      (G_u8Temp < AC_HEATING_TEMP) G_u8Mode = AC_MODE_HEATING ;
	else if (G_u8Temp > AC_COOLING_TEMP) G_u8Mode = AC_MODE_COOLING ;
	else                                 G_u8Mode = AC_MODE_STOP ;

	HDC_Motor_voidControl(G_u8Mode, MOTOR_IN1_PORT, MOTOR_IN1_PIN, MOTOR_IN2_PORT, MOTOR_IN2_PIN) ;
}

u8 AC_App_u8GetMode (void)
{
	return G_u8Mode ;
}

u8 AC_App_u8GetTemperature (void)
{
	return G_u8Temp ;
}
