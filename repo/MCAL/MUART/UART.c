/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sreem
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "UART.h"


void MUART_voidInit (u32 A_u32BaudRata , u8 A_u8DataSize)
{
	u32 L_u32UBRR = (8000000u / (16*A_u32BaudRata)) - 1 ;
	UBRRL = (u8) L_u32UBRR ;
	CLR_BIT( UBRRH , 7) ;
	UBRRH = (u8)(L_u32UBRR>>8);
	SET_BIT(UCSRB, 4);

	SET_BIT(UCSRC, 7);

     CLR_BIT(UCSRC, 6);

     CLR_BIT(UCSRC, 5);

	 CLR_BIT(UCSRC, 4);

     CLR_BIT(UCSRC, 3);

	switch (A_u8DataSize)
		{
		case 5 :
			CLR_BIT(UCSRC , 1) ;
			CLR_BIT(UCSRC , 2) ;
			CLR_BIT(UCSRB , 2) ;
			break ;
		case 6 :
			SET_BIT(UCSRC , 1) ;
			CLR_BIT(UCSRC , 2) ;
			CLR_BIT(UCSRB , 2) ;
			break ;
		case 7 :
			CLR_BIT(UCSRC , 1) ;
			SET_BIT(UCSRC , 2) ;
			CLR_BIT(UCSRB , 2) ;
			break ;
		case 8 :
			SET_BIT(UCSRC , 1) ;
			SET_BIT(UCSRC , 2) ;
			CLR_BIT(UCSRB , 2) ;
			break ;
		}

}


u8   MUART_u8Rx     (void)
{

	while (READ_BIT(UCSRA , 7) == 0) ;
		return UDR ;


}
