/*
 * UART.c
 *
 *  Created on: 25 Sep 2026
 *      Author: Admin
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "UART.h"

#define F_CPU 8000000UL

void MUART_voidInit (u32 A_u32BaudRate , u8 A_u8DataBits)
{
	u16 L_u16UBRR = (u16)((F_CPU / (16UL * A_u32BaudRate)) - 1) ;

	UBRRH = (u8)(L_u16UBRR >> 8) ;
	UBRRL = (u8)(L_u16UBRR) ;

	/* Enable Receiver (RXEN) and Transmitter (TXEN) */
	UCSRB = (1<<4) | (1<<3) ;

	/* URSEL=1 to write UCSRC, 8 data bits, 1 stop bit, no parity */
	UCSRC = (1<<7) | (1<<2) | (1<<1) ;
}

void MUART_voidTx (u8 A_u8Data)
{
	while (READ_BIT(UCSRA , 5) == 0) ;   /* wait for UDRE */
	UDR = A_u8Data ;
}

u8 MUART_u8Rx (void)
{
	while (READ_BIT(UCSRA , 7) == 0) ;   /* wait for RXC */
	return UDR ;
}
