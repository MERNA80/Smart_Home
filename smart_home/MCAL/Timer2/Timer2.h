/*
 * Timer2.h
 *
 *  Created on: Sep 21, 2026
 *      Author: Mernna Ahmed
 */

#ifndef REPO_MCAL_TIMER2_TIMER2_H_
#define REPO_MCAL_TIMER2_TIMER2_H_

#include "../../LIB/STD_type.h"

#define TIMER2_PRESCALLER1    1
#define TIMER2_PRESCALLER8    8
#define TIMER2_PRESCALLER32   32
#define TIMER2_PRESCALLER64   64
#define TIMER2_PRESCALLER128  128
#define TIMER2_PRESCALLER256  256
#define TIMER2_PRESCALLER1024 1024

#define Timer2_OVF               1
#define Timer2_PWM_Phase_Correct 2
#define Timer2_CTC               3
#define Timer2_Fast_PWM          4

#define TCCR2   (*(volatile uint8*)(0x45))
#define TCNT2   (*(volatile uint8*)(0x44))
#define OCR2    (*(volatile uint8*)(0x43))
#define TIMSK   (*(volatile uint8*)(0x59))
#define SREG    (*(volatile uint8*)(0x5F))

void Timer2_Initil(uint16 u16_Prescaller , uint8 u8_Mode);

void Timer2_SetDesiredTime   (uint32 A_u32TimeInMiocro , void (*fptr)(void)) ;

void Timer2_SetComparedValue (uint8 u8_value);  //OCR0


#endif /* REPO_MCAL_TIMER2_TIMER2_H_ */
