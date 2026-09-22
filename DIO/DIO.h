/*
 * DIO.h
 *
 *  Created on: Sep 16, 2026
 *      Author: Mernna Ahmed
 */

#ifndef REPO_MCAL_DIO_DIO_H_
#define REPO_MCAL_DIO_DIO_H_


#include "../../LIB/STD_type.h"
#include "DIO_type.h"

void DIO_SetPortDirection(DIO_PortID port_ID , DIO_Direction direction);

void DIO_SetPortValue(DIO_PortID port_ID , unsigned char value);

void DIO_SetPinDirection(DIO_PortID port_ID , DIO_Pin_ID PinID , DIO_Direction direction);

void DIO_SetPinValue(DIO_PortID port_ID , DIO_Pin_ID PinID , STD_LevelType value);

STD_LevelType DIO_GetPinValue (DIO_PortID port_ID , DIO_Pin_ID PinID);

#endif /* REPO_MCAL_DIO_DIO_H_ */
