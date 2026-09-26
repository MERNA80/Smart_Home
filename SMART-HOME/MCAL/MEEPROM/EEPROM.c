#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "EEPROM.h"

void EEPROM_Voidwrite (u16 A_u16Address , u8 A_u8Data)
{
	EEARH = (u8)(A_u16Address >> 8) ;
	EEARL = (u8)(A_u16Address) ;
	EEDR  = A_u8Data ;

	EECR |= (1<<2) | (1<<EEWE) ;   /* EEMWE æ EEWE Ýí ÊÚáíãÉ æÇÍÏÉ ÈÓ */
}

u8 EEPROM_u8Read (u16 A_u16Address)
{
	EEARH = (u8)(A_u16Address >> 8) ;
	EEARL = (u8)(A_u16Address) ;

	SET_BIT(EECR , EERE) ;

	return EEDR ;
}
