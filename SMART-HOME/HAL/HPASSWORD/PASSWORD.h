/*
 * PASSWORD.h
 *
 *  Created on: 25 Sep 2026
 *      Author: Admin
 */

#ifndef HAL_HPASSWORD_PASSWORD_H_
#define HAL_HPASSWORD_PASSWORD_H_

#include "../../LIB/STD_types.h"

#define Pass_Length   4

void PASS_voidInit  (void) ;
u8   PASS_u8Check   (u8 A_u8EnteredPass[Pass_Length]) ;

#endif /* HAL_HPASSWORD_PASSWORD_H_ */
