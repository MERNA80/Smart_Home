/*
 * Bit_Math.h
 *
 *  Created on: Sep 19, 2026
 *      Author: Mernna ahmed
 */

#ifndef REPO_LIB_BIT_MATH_H_
#define REPO_LIB_BIT_MATH_H_

#define SETBIT(port_ID , PinID)  (port_ID) |=  ( 1 << (PinID) )
#define CLEARBIT(port_ID , PinID)  (port_ID) &= ~( 1 << (PinID) )
#define TOGGLEBIT(port_ID , PinID)  (port_ID) ^=  ( 1 << (PinID) )
#define GETBIT(port_ID , PinID)  (((port_ID) >> (PinID)) & 0x01)




#endif /* REPO_LIB_BIT_MATH_H_ */
