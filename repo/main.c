//
////#include "LIB/STD_types.h"
////#include "LIB/BitMath.h"
////#include "MCAL/MEEPROM/EEPROM.h"
////#include "MCAL/MUART/UART.h"
////#include "HAL/HPASSWORD/Password.h"
////#include "APP/LCD_APP.h"
////#include "HAL/HLCD/LCD.h"
////#include <util/delay.h>
////
//////
//////
//////
//////void main()
//////{
//////
////// u8 L_u8EnterPass[4];
////// LCD_Initializtion();
////// MUART_voidInit();
//////
//////
//////
//////
//////
//////  while(1){
//////
//////      for(u8 i=0 ; i < 4 ; i++)
//////      {
//////
//////    	  L_u8EnterPass[4] = MUART_u8Rx();   /*enter pass*/
//////
//////    	   }
//////
//////       if(PASS_u8Check(L_u8EnterPass) == 1)     /*CHECK PASS*/
//////       {
//////    	   LCD_Lab_Correct_mas();
//////
//////
//////       }
//////       else
//////       {
//////
//////    	   LCD_Lab_Wrong_mas();
//////
//////       }
//////
//////  }
//////
//////
//////}
////int main(void)
////{
////    u8 L_u8EnterPass[4];
////
////    // 1. التهيئات الأساسية
////    LCD_Initialization();
////    MUART_voidInit();
////
////    while(1)
////    {
////        // 2. طباعة طلب إدخال كلمة السر
////        LCD_Lab_EnterPassword_mas(); //[span_0](start_span)[span_0](end_span)[span_1](start_span)[span_1](end_span)
////
////        // 3. استقبال 4 أرقام/أحرف وتبديل العرض بنجوم
////        for(u8 i = 0; i < 4; i++)
////        {
////            L_u8EnterPass[i] = MUART_u8Rx(); // تخزين الرمز المستقبل[span_2](start_span)[span_2](end_span)
////            LCD_Lab_PasswordStar_mas(i);     // طباعة نجمة على الشاشة في الموقع i[span_3](start_span)[span_3](end_span)
////        }
////
////        // 4. التحقق من مطابقة كلمة السر
////        if(PASS_u8Check(L_u8EnterPass) == 1) //[span_4](start_span)[span_4](end_span)[span_5](start_span)[span_5](end_span)
////        {
////            LCD_Lab_Correct_mas(); // طباعة رسالة النجاح[span_6](start_span)[span_6](end_span)[span_7](start_span)[span_7](end_span)
////        }
////        else
////        {
////            LCD_Lab_Wrong_mas();   // طباعة رسالة الخطأ[span_8](start_span)[span_8](end_span)[span_9](start_span)[span_9](end_span)
////        }
////    }
////
////    return 0;
////}
//#include "LIB/STD_types.h"
//#include "MCAL/MUART/UART.h"
//#include "MCAL/MEEPROM/EEPROM.h"
//#include "HAL/HLCD/LCD.h"
//#include "HAL/HPASSWORD/PASSWORD.h"
//#include "APP/LCD_APP.h"
//#include "APP/DEVICES_APP.h"
//#include "APP/AC_APP.h"
//
///* Define Default Password in EEPROM if not saved (e.g. '1', '2', '3', '4') */
//static void Init_EEPROM_Password(void)
//{
//    u8 default_pass[Pass_Length] = {'1', '2', '3', '4'};
//    for(u8 i = 0; i < Pass_Length; i++)
//    {
//        /* Read to check if already written, otherwise set default */
//        if(EEPROM_u8Read(i) == 0xFF)
//        {
//            EEPROM_Voidwrite(i, default_pass[i]);
//        }
//    }
//}
//
//int main(void)
//{
//    u8 entered_pass[Pass_Length];
//    u8 digit_count = 0;
//    u8 is_authenticated = 0;
//    u8 rx_byte = 0;
//
//    /* Initialize Peripherals & Applications */
//    MUART_voidInit(9600, 8);
//    LCD_Initialization();
//    Init_EEPROM_Password();
//
//    /* Display Initial Password Prompt */
//    LCD_Lab_EnterPassword_mas();
//
//    /* Step 1: Authentication Loop via UART */
//    while(!is_authenticated)
//    {
//        rx_byte = MUART_u8Rx();
//
//        /* Process digit input */
//        if(rx_byte >= '0' && rx_byte <= '9')
//        {
//            entered_pass[digit_count] = rx_byte;
//            LCD_Lab_PasswordStar_mas(digit_count);
//            digit_count++;
//
//            if(digit_count == Pass_Length)
//            {
//                /* Check password stored in EEPROM */
//                if(PASS_u8Check(entered_pass) == 1)
//                {
//                    LCD_Lab_Correct_mas();
//                    is_authenticated = 1;
//                }
//                else
//                {
//                    LCD_Lab_Wrong_mas();
//                    digit_count = 0; /* Reset for retry */
//                    LCD_Lab_EnterPassword_mas();
//                }
//            }
//        }
//        else
//        {
//            LCD_Lab_Invalid_mas();
//            digit_count = 0;
//            LCD_Lab_EnterPassword_mas();
//        }
//    }
//
//    /* Step 2: Initialize Home System after Successful Auth */
//    LCD_Lab_Home_Statuse_mas();
//    Devices_App_voidInit();
//    AC_App_voidInit();
//
//    /* Step 3: Main System Control Loop */
//    while(1)
//    {
//        /* Process Push Buttons and Update LED1, LED2, TV statuses */
//        Devices_App_voidUpdate();
//
//        /* Fetch statuses for LCD Display */
//        u8 led1_stat = Devices_App_u8GetDeviceStatus(0);
//        u8 led2_stat = Devices_App_u8GetDeviceStatus(1);
//        u8 tv_stat   = Devices_App_u8GetDeviceStatus(2);
//        u8 ac_stat   = Devices_App_u8GetDeviceStatus(3);
//
//        /* Update AC logic (LM35 + DC Motor Control) based on AC status */
//        AC_App_voidUpdate(ac_stat);
//
//        /* Render System Status on LCD Screen */
//        LCD_Lab_DisplayHomeStatus(led1_stat, led2_stat, tv_stat, ac_stat);
//    }
//
//    return 0;
//}
#include "LIB/STD_types.h"

/* APP */
#include "APP/AC_APP.h"
#include "APP/DEVICES_APP.h"
#include "APP/LCD_APP.h"
#include "HAL/HLCD/LCD.h"

/* HAL */
#include "HAL/HLCD/LCD.h"
#include "HAL/HPASSWORD/PASSWORD.h"

/* MCAL */
#include "MCAL/MUART/UART.h"
#include "MCAL/MADC/ADC.h"


#define PASSWORD_SIZE 4

#define DEVICE_LED1  1
#define DEVICE_LED2  2
#define DEVICE_TV    3
#define DEVICE_AC    4


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


    /* =========================
       Initialization
       ========================= */

    LCD_Initialization();

    MUART_voidInit(9600, 8);

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
        /*
         * Wait for one character
         */
        Local_u8Data = MUART_u8Rx();


        /*
         * Check if received character
         * is a number
         */
        if((Local_u8Data >= '0') &&
           (Local_u8Data <= '9'))
        {
            /*
             * Convert ASCII to number
             *
             * '1' -> 1
             * '2' -> 2
             */
            Local_u8Password[Local_u8Index] =
                    Local_u8Data - '0';


            /*
             * Display *
             */
            LCD_Lab_PasswordStar_mas(Local_u8Index);


            /*
             * Next digit
             */
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
            /*
             * Stop program
             */
        }
    }


    /* =========================
       Correct Password
       ========================= */

    LCD_Lab_Correct_mas();


    /*
     * Display Smart Home
     */
    LCD_Lab_Home_Statuse_mas();


    /* =========================
       Smart Home
       ========================= */

    while(1)
    {
        /*
         * Read buttons
         * and change device states
         */
        Devices_App_voidUpdate();


        /*
         * Get NEW states
         */
        Local_u8LED1Status =
                Devices_App_u8GetDeviceStatus(DEVICE_LED1);

        Local_u8LED2Status =
                Devices_App_u8GetDeviceStatus(DEVICE_LED2);

        Local_u8TVStatus =
                Devices_App_u8GetDeviceStatus(DEVICE_TV);

        Local_u8ACStatus =
                Devices_App_u8GetDeviceStatus(DEVICE_AC);


        /*
         * Update AC
         */
        AC_App_voidUpdate(Local_u8ACStatus);


        /*
         * Display current states
         */
        LCD_Lab_DisplayHomeStatus(
                Local_u8LED1Status,
                Local_u8LED2Status,
                Local_u8TVStatus,
                Local_u8ACStatus
        );
    }
}
