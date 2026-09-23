#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "../../MCAL/MDIO/DIO.h"
#include "LCD.h"
#include <util/delay.h>
#include "LCD_Main.h"


void LCD_Lab_EnterPassword_mas(void)
{
	        LCD_CLearDisplay();
		    LCD_Set_Cursor(0 , 1);
	//	LCD_Send_Str("Enter The Password");
		    LCD_Send_Data('E');
		    _delay_ms(100);

		    LCD_Send_Data('n');
		    _delay_ms(100);

		    LCD_Send_Data('t');
		    _delay_ms(100);

		    LCD_Send_Data('e');
		    _delay_ms(100);

		    LCD_Send_Data('r');
		    _delay_ms(100);

		    LCD_Send_Data(' ');
		    _delay_ms(100);

		    LCD_Send_Data('P');
		    _delay_ms(100);

		    LCD_Send_Data('a');
		    _delay_ms(100);

		    LCD_Send_Data('s');
		    _delay_ms(100);

		    LCD_Send_Data('s');
		    _delay_ms(100);

		    LCD_Send_Data('w');
		    _delay_ms(100);

		    LCD_Send_Data('o');
		    _delay_ms(100);

		    LCD_Send_Data('r');
		    _delay_ms(100);

		    LCD_Send_Data('d');
		    _delay_ms(800);

		
		    LCD_Set_Cursor(1 , 5);
	//	LCD_Send_Str("_ _ _ _");
	        LCD_Send_Data('_');
	        _delay_ms(100);

	        LCD_Send_Data(' ');
			 _delay_ms(100);

		    LCD_Send_Data('_');
		    _delay_ms(100);

		    LCD_Send_Data(' ');
		    _delay_ms(100);

		    LCD_Send_Data('_');
		    _delay_ms(100);

		    LCD_Send_Data(' ');
		    _delay_ms(100);

		    LCD_Send_Data('_');
		    _delay_ms(100);

}

void LCD_Lab_PasswordStar_mas(u8 A_u8Index)
{
	LCD_Set_Cursor(1 , 5 + (A_u8Index*2));
	LCD_Send_Data('*');
}

void LCD_Lab_Wrong_mas(void)
{
	LCD_CLearDisplay();
	LCD_Set_Cursor(0 , 2);
	LCD_Send_Str("Wrong Pass!!");
}

void LCD_Lab_Correct_mas(void)
{

	LCD_CLearDisplay();
	LCD_Set_Cursor(0 , 2);
	LCD_Send_Str("Correct Pass");
}

void LCD_Lab_Invalid_mas(void)
{
	LCD_CLearDisplay();
	LCD_Set_Cursor(0 , 0);
	LCD_Send_Str("Invalid Password!");
}

void LCD_Lab_Home_Statuse_mas(void)
{
	LCD_CLearDisplay();
	LCD_Set_Cursor(0 , 3);
	LCD_Send_Str("Home Status");
	_delay_ms(900);
	LCD_CLearDisplay();
}

void LCD_Lab_DisplayHomeStatus( u8 LED1_status,    u8 LED2_status,   u8 TV_status,   u8 AC_status)
{
	LCD_CLearDisplay();

	LCD_Set_Cursor(0,1);
	LCD_Send_Str("LED1:");
	if (LED1_status == 1)
	{
		LCD_Send_Str("ON");
	}
	else
	{
		LCD_Send_Str("OFF");
	}

	LCD_Set_Cursor(0,9);
	LCD_Send_Str("LED2:");
	if (LED1_status == 1)
	{
		LCD_Send_Str("ON");
	}
	else
	{
		LCD_Send_Str("OFF");
	}

	LCD_Set_Cursor(1,1);
	LCD_Send_Str("TV:");
	if (LED1_status == 1)
	{
		LCD_Send_Str("ON");
	}
	else
	{
		LCD_Send_Str("OFF");
	}


	LCD_Set_Cursor(1,9);
	LCD_Send_Str("AC:");
	if (LED1_status == 1)
	{
		LCD_Send_Str("ON");
	}
	else
	{
		LCD_Send_Str("OFF");
	}



}
