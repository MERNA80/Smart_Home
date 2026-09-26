#include "LIB/STD_types.h"

/* APP */
#include "APP/AC_APP.h"
#include "APP/DEVICES_APP.h"
#include "APP/LCD_APP.h"

/* HAL */
#include "HAL/HLCD/LCD.h"
#include "HAL/HPASSWORD/PASSWORD.h"

/* MCAL */
#include "MCAL/MUART/UART.h"
#include "MCAL/MADC/ADC.h"

#include <util/delay.h>


#define PASSWORD_SIZE 4

#define DEVICE_LED1  0
#define DEVICE_LED2  1
#define DEVICE_TV    2
#define DEVICE_AC    3


int main(void)
{
    /* =========================
       Variables
       ========================= */

    u8 Local_u8Password[PASSWORD_SIZE];

    u8 Local_u8Data;
    u8 Local_u8Index;

    u8 Local_u8PasswordResult;

    u8 Local_u8LED1Status;
    u8 Local_u8LED2Status;
    u8 Local_u8TVStatus;
    u8 Local_u8ACStatus;

    /* Previous states, to detect real changes only */
    u8 Prev_u8LED1Status = 0xFF;
    u8 Prev_u8LED2Status = 0xFF;
    u8 Prev_u8TVStatus   = 0xFF;
    u8 Prev_u8ACStatus   = 0xFF;


    /* =========================
       Initialization
       ========================= */

    LCD_Initialization();

    MUART_voidInit(9600, 8);

    PASS_voidInit();

    MADC_voidInit();

    Devices_App_voidInit();

    AC_App_voidInit();


    /* =========================
       Enter Password
       ========================= */

    LCD_Lab_EnterPassword_mas();


    /* =========================
       Receive Password
       ========================= */

    Local_u8Index = 0;

    while(Local_u8Index < PASSWORD_SIZE)
    {
        Local_u8Data = MUART_u8Rx();

        if((Local_u8Data >= '0') &&
           (Local_u8Data <= '9'))
        {
            Local_u8Password[Local_u8Index] =
                    Local_u8Data - '0';

            LCD_Lab_PasswordStar_mas(Local_u8Index);

            Local_u8Index++;
        }
    }


    /* =========================
       Check Password
       ========================= */

    Local_u8PasswordResult =
            PASS_u8Check(Local_u8Password);


    /* =========================
       Wrong Password
       ========================= */

    if(Local_u8PasswordResult == 0)
    {
        LCD_Lab_Wrong_mas();

        while(1)
        {
            /* Stop program */
        }
    }


    /* =========================
       Correct Password
       ========================= */

    LCD_Lab_Correct_mas();

    LCD_Lab_Home_Statuse_mas();


    /* =========================
       Smart Home
       ========================= */

    while(1)
    {
        Devices_App_voidUpdate();

        Local_u8LED1Status =
                Devices_App_u8GetDeviceStatus(DEVICE_LED1);

        Local_u8LED2Status =
                Devices_App_u8GetDeviceStatus(DEVICE_LED2);

        Local_u8TVStatus =
                Devices_App_u8GetDeviceStatus(DEVICE_TV);

        Local_u8ACStatus =
                Devices_App_u8GetDeviceStatus(DEVICE_AC);


        AC_App_voidUpdate(Local_u8ACStatus);


        /*
         * Update LCD ONLY if something actually changed
         */
        if( (Local_u8LED1Status != Prev_u8LED1Status) ||
            (Local_u8LED2Status != Prev_u8LED2Status) ||
            (Local_u8TVStatus   != Prev_u8TVStatus)   ||
            (Local_u8ACStatus   != Prev_u8ACStatus) )
        {
            LCD_Lab_DisplayHomeStatus(
                    Local_u8LED1Status,
                    Local_u8LED2Status,
                    Local_u8TVStatus,
                    Local_u8ACStatus
            );

            Prev_u8LED1Status = Local_u8LED1Status;
            Prev_u8LED2Status = Local_u8LED2Status;
            Prev_u8TVStatus   = Local_u8TVStatus;
            Prev_u8ACStatus   = Local_u8ACStatus;
        }

        _delay_ms(20);
    }
}
