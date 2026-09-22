/*
 * DIO_type.h
 *
 *  Created on: Sep 16, 2026
 *      Author: Mernna Ahmed
 */

#ifndef REPO_MCAL_DIO_DIO_TYPE_H_
#define REPO_MCAL_DIO_DIO_TYPE_H_


typedef enum
{
	Input ,
	Output
}DIO_Direction;

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}DIO_PortID;



typedef enum
{
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
}DIO_Pin_ID;



#endif /* REPO_MCAL_DIO_DIO_TYPE_H_ */
