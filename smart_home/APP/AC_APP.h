/*
 * AC_APP.h
 *
 *  Created on: Sep 24, 2026
 *      Author: Person 4 (Temperature & AC)
 */

#ifndef APP_AC_APP_H_
#define APP_AC_APP_H_

#include "../LIB/STD_types.h"

/* Same values used by HDC_Motor_voidControl() */
#define AC_MODE_STOP      0
#define AC_MODE_HEATING   1   /* Motor CW  */
#define AC_MODE_COOLING   2   /* Motor CCW */

#define AC_HEATING_TEMP   20  /* below it -> heating */
#define AC_COOLING_TEMP   25  /* above it -> cooling */

void AC_App_voidInit         (void) ;
void AC_App_voidUpdate       (u8 A_u8ACStatus) ;
u8   AC_App_u8GetMode        (void) ;
u8   AC_App_u8GetTemperature (void) ;

#endif /* APP_AC_APP_H_ */
