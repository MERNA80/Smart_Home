/*
 * EEPROM.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sreem
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "EEPROM.h"

void EEPROM_Voidwrite(u16 A_u16Address , u8 A_u8Data )
{
	EEAR = A_u16Address;
	EEDR = A_u8Data;
	SET_BIT(EECR ,2 );
	SET_BIT(EECR , 1);
	while (READ_BIT(EECR , 1) == 1) ;

}


u8 EEPROM_u8Read(u16 A_u16Address)
{
	EEAR = A_u16Address;
	SET_BIT(EECR , 0) ;
		return EEDR ;

}
