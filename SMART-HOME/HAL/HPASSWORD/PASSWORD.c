#include "../../LIB/STD_types.h"
#include "../../MCAL/MEEPROM/EEPROM.h"
#include "PASSWORD.h"

static const u8 DEFAULT_PASS[Pass_Length] = {1 , 2 , 3 , 4} ;

static void PASS_voidDelay (void)
{
	u32 i ;
	for (i = 0 ; i < 30000 ; i++)
	{
		/* pure busy-wait, no register or library dependency */
	}
}

void PASS_voidInit (void)
{
	u8 i ;
	for (i = 0 ; i < Pass_Length ; i++)
	{
		EEPROM_Voidwrite(i , DEFAULT_PASS[i]) ;
		PASS_voidDelay() ;
	}
}

u8 PASS_u8Check (u8 A_u8EnteredPass[Pass_Length])
{
	if (A_u8EnteredPass[0] == 1 &&
	    A_u8EnteredPass[1] == 2 &&
	    A_u8EnteredPass[2] == 3 &&
	    A_u8EnteredPass[3] == 4)
	{
		return 1 ;
	}
	return 0 ;
}
