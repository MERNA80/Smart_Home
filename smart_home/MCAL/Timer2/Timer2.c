/*
// * Timer2.c
// *
// *  Created on: Sep 21, 2026
// *      Author: Mernna Ahmed
// */
//
#include "../../LIB/Bit_Math.h"
#include "../DIO/DIO.h"
#include "../../LIB/STD_type.h"
#include "Timer2.h"



uint32 TimerPrescaller;
volatile uint32 DesiredCounts;

void (*Timer2_ptr)(void);



void Timer2_Initil   (uint16 u16_Prescaller , uint8 u8_Mode)
{
	TimerPrescaller = u16_Prescaller;


    switch(u16_Prescaller)
    {
        case TIMER2_PRESCALLER1:
        	SETBIT(TCCR2,0);
        	CLEARBIT(TCCR2,1);
            CLEARBIT(TCCR2,2);
            break;

        case TIMER2_PRESCALLER8:
        	CLEARBIT(TCCR2,0);
            SETBIT(TCCR2,1);
            CLEARBIT(TCCR2,2);
            break;

        case TIMER2_PRESCALLER32:
            SETBIT(TCCR2,0);
            SETBIT(TCCR2,1);
            CLEARBIT(TCCR2,2);
            break;

        case TIMER2_PRESCALLER64:
        	CLEARBIT(TCCR2,0);
            CLEARBIT(TCCR2,1);
            SETBIT(TCCR2,2);
            break;

        case TIMER2_PRESCALLER128:
            SETBIT(TCCR2,0);
            CLEARBIT(TCCR2,1);
            SETBIT(TCCR2,2);
            break;

        case TIMER2_PRESCALLER256:
        	CLEARBIT(TCCR2,0);
            SETBIT(TCCR2,1);
            SETBIT(TCCR2,2);
            break;

        case TIMER2_PRESCALLER1024:
            SETBIT(TCCR2,0);
            SETBIT(TCCR2,1);
            SETBIT(TCCR2,2);
            break;
    }


    switch(u8_Mode)
    {
        case Timer2_CTC:

            SETBIT(TCCR2,3);
            CLEARBIT(TCCR2,6);
            SETBIT(TIMSK,7);
            SETBIT(SREG,7);
            break;

        case Timer2_OVF:

        	CLEARBIT(TCCR2,6);
            CLEARBIT(TCCR2,3);
            SETBIT(TIMSK,6);
            SETBIT(SREG,7);
            break;
    }
}



void Timer2_SetDesiredTime(uint32 A_u32TimeInMicro, void (*fptr)(void))
{
    uint32 CompareTime;

    Timer2_ptr = fptr;

    CompareTime = ((uint32)(OCR2 + 1) * TimerPrescaller) / 8;



    DesiredCounts =
        A_u32TimeInMicro / CompareTime;
}



void Timer2_SetComparedValue(uint8 A_u8Value)
{
    OCR2 = A_u8Value;
}


void __vector_4(void)__attribute__((signal));

void __vector_4(void)
{
    static uint32 u32Counter = 0;

    u32Counter++;

    if(u32Counter == DesiredCounts)
    {
        Timer2_ptr();

        u32Counter = 0;
    }

}


