/*
 * LM35.h
 *
 *  Created on: Sep 24, 2026
 *      Author: Person 4 (Temperature & AC)
 */

#ifndef HAL_HLM35_LM35_H_
#define HAL_HLM35_LM35_H_

#include "../../LIB/STD_types.h"

#define LM35_ADC_CHANNEL   3   /* PA3 */

void HLM35_voidInit         (void) ;
u8   HLM35_u8GetTemperature (void) ;

#endif /* HAL_HLM35_LM35_H_ */
