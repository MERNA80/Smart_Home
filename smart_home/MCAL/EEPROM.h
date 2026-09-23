/*
 * EEPROM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sreem
 */

#ifndef REPO_MCAL_MEEPROM_EEPROM_H_
#define REPO_MCAL_MEEPROM_EEPROM_H_


#define EEAR   (*(volatile u16*)(0x3E))
#define EECR   (*(volatile u8*)(0x3C))
#define EEDR   (*(volatile u8*)(0x3D))

void EEPROM_Voidwrite(u16 A_u16Address , u8 A_u8Data );
u8 EEPROM_u8Read(u16 A_u16Address);






#endif /* REPO_MCAL_MEEPROM_EEPROM_H_ */
