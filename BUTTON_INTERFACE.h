/*
 * BUTTON_INTERFACE.h
 *
 *  Created on: ???/???/????
 *      Author: ??? ????
 */

#ifndef HAL_BUTTON_INTERFACE_H_
#define HAL_BUTTON_INTERFACE_H_

#include "../LIB/STD_TYPES.h"
#define BUTTON_RELEASED 1
#define BUTTON_PRESSED 0


typedef struct {
u8	Port;
u8 Pin;

}BUTTON_t;


void BUTTON_VoidInIt (BUTTON_t* Copy_PstructButton);
u8 BUTTON_u8GetState (BUTTON_t* Copy_PstructButton);


#endif /* HAL_BUTTON_INTERFACE_H_ */
