/*
 * EEPROM.h
 *
 *  Created on: 25 Sep 2026
 *      Author: Admin
 */

#ifndef MCAL_MEEPROM_EEPROM_H_
#define MCAL_MEEPROM_EEPROM_H_

#include "../../LIB/STD_types.h"

#define EEARL   (*((volatile u8*)(0x3E)))
#define EEARH   (*((volatile u8*)(0x3F)))
#define EEDR    (*((volatile u8*)(0x3D)))
#define EECR    (*((volatile u8*)(0x3C)))

#define EEWE    1
#define EERE    0

void EEPROM_Voidwrite (u16 A_u16Address , u8 A_u8Data) ;
u8   EEPROM_u8Read    (u16 A_u16Address) ;

#endif /* MCAL_MEEPROM_EEPROM_H_ */
