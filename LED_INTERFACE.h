/*
 * LED_INTERFACE.h
 *
 *  Created on: ???/???/????
 *      Author: ??? ????
 */

#ifndef HAL_LED_INTERFACE_H_
#define HAL_LED_INTERFACE_H_
#include "../LIB/STD_TYPES.h"
typedef struct {
	u8 Port;
	u8 Pin ;
} LED_t ;

void LED_VoidInIt (LED_t* Copy_PstructLED) ;
void LED_VoidTurnOn (LED_t* Copy_PstructLED);
void LED_VoidTurnOff (LED_t* Copy_PstructLED);
void LED_VoidToggle (LED_t* Copy_PstructLED);




#endif /* HAL_LED_INTERFACE_H_ */
