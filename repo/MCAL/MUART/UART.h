/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sreem
 */




#ifndef MCAL_MUART_UART_H_
#define MCAL_MUART_UART_H_

#define UDR        (*(volatile u8*)(0x2C))
#define UCSRA      (*(volatile u8*)(0x2B))
#define UCSRB      (*(volatile u8*)(0x2A))
#define UCSRC      (*(volatile u8*)(0x40))
#define UBRRL      (*(volatile u8*)(0x29))
#define UBRRH      (*(volatile u8*)(0x40))

void MUART_voidInit (u32 A_u32BaudRata , u8 A_u8DataSize) ;
u8   MUART_u8Rx     (void) ;

#endif /* REPO_MCAL_MUART_UART_H_ */
