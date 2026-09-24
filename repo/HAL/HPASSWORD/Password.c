/*
 * Password.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sreem
 */
#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "../../MCAL/MEEPROM/EEPROM.h"
#include "Password.h"


void PASS_voidSave(u8* A_Pass)
{
	u8 L_Counter;
	for(L_Counter = 0 ; L_Counter < 4 ; L_Counter++ )
	{
		EEPROM_Voidwrite( L_Counter , A_Pass[L_Counter] );

	}

}
u8 PASS_u8Check(u8* A_Pass)
{

	u8 L_Counter;
	u8 L_StoredPass;
	for(L_Counter =0 ; L_Counter < 4 ; L_Counter++)
	{
		L_StoredPass = EEPROM_u8Read(L_Counter);
		if (L_StoredPass != A_Pass[L_Counter])
		        {
		            return 0;
		        }
		    }

		    return 1;
}
