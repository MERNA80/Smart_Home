
#define F_CPU 8000000UL

#include "LIB/STD_types.h"
#include "LIB/BitMath.h"

#include "MCAL/MDIO/DIO.h"
#include "MCAL/MUART/UART.h"
#include "HAL/HLCD/LCD.h"
#include "HAL/HMOTOR/Motor.h"

#include "APP/AC_APP.h"
#include "APP/DEVICES_APP.h"
#include "APP/LCD_APP.h"
#include "HAL/HPASSWORD/Password.h"

#include "util/delay.h"

#define MOTOR_PORT_IN1  DIO_PORTD
#define MOTOR_PIN_IN1   DIO_PIN2
#define MOTOR_PORT_IN2  DIO_PORTD
#define MOTOR_PIN_IN2   DIO_PIN3

int main(void)
{
    u8 L_u8EnteredPass[Pass_Length];
    u8 L_u8PassIndex = 0;
    u8 L_u8ReceivedChar = 0;
    u8 L_u8SystemUnlocked = 0;
    u8 L_u8ACState = 0;
    u8 L_u8ACMode = 0;

    u8 L_u8Led1 = 0, L_u8Led2 = 0, L_u8TV = 0, L_u8AC = 0;
    u8 L_u8PrevLed1 = 0, L_u8PrevLed2 = 0, L_u8PrevTV = 0, L_u8PrevAC = 0;

    LCD_Initialization();
    MUART_voidInit(9600, 8);
    Devices_App_voidInit();
    AC_App_voidInit();
    HDC_Motor_voidInit(MOTOR_PORT_IN1, MOTOR_PIN_IN1, MOTOR_PORT_IN2, MOTOR_PIN_IN2);

    LCD_Lab_EnterPassword_mas();

    while (1)
    {
        if (L_u8SystemUnlocked == 0)
        {
            L_u8ReceivedChar = MUART_u8Rx();

            if (L_u8ReceivedChar >= '0' && L_u8ReceivedChar <= '9')
            {
                L_u8EnteredPass[L_u8PassIndex] = L_u8ReceivedChar - '0';
                LCD_Lab_PasswordStar_mas(L_u8PassIndex);
                L_u8PassIndex++;

                if (L_u8PassIndex == Pass_Length)
                {
                    if (PASS_u8Check(L_u8EnteredPass) == 1)
                    {
                        LCD_Lab_Correct_mas();
                        _delay_ms(1000);

                        LCD_CLearDisplay();
                        LCD_Set_Cursor(0, 0);
                        LCD_Send_Str("Smart Home");
                        LCD_Set_Cursor(1, 4);
                        LCD_Send_Str("Project");
                        _delay_ms(1500);

                        L_u8SystemUnlocked = 1;
                        LCD_Lab_Home_Statuse_mas();

                        L_u8Led1 = Devices_App_u8GetDeviceStatus(0);
                        L_u8Led2 = Devices_App_u8GetDeviceStatus(1);
                        L_u8TV   = Devices_App_u8GetDeviceStatus(2);
                        L_u8AC   = Devices_App_u8GetDeviceStatus(3);

                        LCD_Lab_DisplayHomeStatus(L_u8Led1, L_u8Led2, L_u8TV, L_u8AC);

                        L_u8PrevLed1 = L_u8Led1;
                        L_u8PrevLed2 = L_u8Led2;
                        L_u8PrevTV   = L_u8TV;
                        L_u8PrevAC   = L_u8AC;
                    }
                    else
                    {
                        LCD_Lab_Wrong_mas();
                        _delay_ms(1500);
                        L_u8PassIndex = 0;
                        LCD_Lab_EnterPassword_mas();
                    }
                }
            }
        }
        else
        {
            Devices_App_voidUpdate();

            L_u8Led1 = Devices_App_u8GetDeviceStatus(0);
            L_u8Led2 = Devices_App_u8GetDeviceStatus(1);
            L_u8TV   = Devices_App_u8GetDeviceStatus(2);
            L_u8AC   = Devices_App_u8GetDeviceStatus(3);

            if (L_u8Led1 != L_u8PrevLed1 || L_u8Led2 != L_u8PrevLed2 ||
                L_u8TV   != L_u8PrevTV   || L_u8AC   != L_u8PrevAC)
            {
                LCD_Lab_DisplayHomeStatus(L_u8Led1, L_u8Led2, L_u8TV, L_u8AC);

                L_u8PrevLed1 = L_u8Led1;
                L_u8PrevLed2 = L_u8Led2;
                L_u8PrevTV   = L_u8TV;
                L_u8PrevAC   = L_u8AC;
            }

            AC_App_voidUpdate(L_u8AC);
            L_u8ACMode = AC_App_u8GetMode();

            if (L_u8AC == 1)
            {
                if (L_u8ACMode == AC_MODE_HEATING)
                {
                    HDC_Motor_voidCW(MOTOR_PORT_IN1, MOTOR_PIN_IN1, MOTOR_PORT_IN2, MOTOR_PIN_IN2);
                }
                else if (L_u8ACMode == AC_MODE_COOLING)
                {
                    HDC_Motor_voidCCW(MOTOR_PORT_IN1, MOTOR_PIN_IN1, MOTOR_PORT_IN2, MOTOR_PIN_IN2);
                }
                else
                {
                    HDC_Motor_voidStop(MOTOR_PORT_IN1, MOTOR_PIN_IN1, MOTOR_PORT_IN2, MOTOR_PIN_IN2);
                }
            }
            else
            {
                HDC_Motor_voidStop(MOTOR_PORT_IN1, MOTOR_PIN_IN1, MOTOR_PORT_IN2, MOTOR_PIN_IN2);
            }
        }
    }

    return 0;
}
