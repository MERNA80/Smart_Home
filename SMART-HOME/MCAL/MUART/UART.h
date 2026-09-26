/*
 * UART.h
 *
 *  Created on: 25 Sep 2026
 *      Author: Admin
 */

#ifndef MCAL_MUART_UART_H_
#define MCAL_MUART_UART_H_

#include "../../LIB/STD_types.h"

#define UDR     (*((volatile u8*)(0x2C)))
#define UCSRA   (*((volatile u8*)(0x2B)))
#define UCSRB   (*((volatile u8*)(0x2A)))
#define UCSRC   (*((volatile u8*)(0x40)))
#define UBRRL   (*((volatile u8*)(0x29)))
#define UBRRH   (*((volatile u8*)(0x40)))

void MUART_voidInit (u32 A_u32BaudRate , u8 A_u8DataBits) ;
void MUART_voidTx    (u8 A_u8Data) ;
u8   MUART_u8Rx      (void) ;

#endif /* MCAL_MUART_UART_H_ */
