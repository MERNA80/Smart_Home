
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LED_INTERFACE.h"
#include "../MCAL/DIO_INTERFACE.h"
#include "../MCAL/DIO_PRIVATE.h"
#include "DEVICES_APP.h"
#include <util/delay.h>
#include "../HAL/BUTTON_INTERFACE.h"
#define F_CPU 8000000UL

static LED_t  DEVICES_LED[4] ={
	{DIO_PORTC , DIO_PIN0 }	,
	{DIO_PORTC , DIO_PIN1 }	,
	{DIO_PORTC , DIO_PIN2 },
	{DIO_PORTC , DIO_PIN3 }	,

	};

static BUTTON_t  DEVICES_BUTTONS[4]={
	{DIO_PORTB , DIO_PIN0 }	,
	{DIO_PORTB , DIO_PIN1 }	,
	{DIO_PORTB , DIO_PIN2 },
	{DIO_PORTB , DIO_PIN3 }	,

	};

static u8 g_u8DevicesStatus = 0x00;

void Devices_App_voidInit(void) {
    for (u8 i = 0; i < 4; i++) {
    	LED_VoidInIt(&DEVICES_LED[i]);
    	BUTTON_VoidInIt(&DEVICES_BUTTONS[i]);
    }
}

void Devices_App_voidUpdate(void) {
    for (u8 i = 0; i < 4; i++) {
        if (BUTTON_u8GetState(&DEVICES_BUTTONS[i]) == BUTTON_PRESSED) {
            _delay_ms(30);
            if (BUTTON_u8GetState(&DEVICES_BUTTONS[i]) == BUTTON_PRESSED) {


                LED_VoidToggle(&DEVICES_LED[i]);

                TOG_BIT(g_u8DevicesStatus, i);


                while (BUTTON_u8GetState(&DEVICES_BUTTONS[i]) == BUTTON_PRESSED);
            }
        }
    }
}


u8 Devices_App_u8GetDeviceStatus(u8 Copy_u8DeviceNum) {
    if (Copy_u8DeviceNum < 4) {
        return GET_BIT(g_u8DevicesStatus, Copy_u8DeviceNum);
    }
    return 0;
}














