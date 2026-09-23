
#include "../HLCD/LCD.h"

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_types.h"

#include "../../MCAL/MDIO/DIO.h"

#include <avr/delay.h>



void LCD_Initialization (void)
{
	_delay_ms(40) ;

	MDIO_voidInitPin(LCD_DATA_PORT , DIO_PIN4 , DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_DATA_PORT , DIO_PIN5  , DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_DATA_PORT , DIO_PIN6 , DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_DATA_PORT , DIO_PIN7, DIO_OUTPUT)  ;
	MDIO_voidInitPin(LCD_RS_PORT , LCD_RS_PIN , DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_RW_PORT , LCD_RW_PIN , DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_E_PORT , LCD_E_PIN , DIO_OUTPUT)   ;

	LCD_Send_Cmd(0x02) ;
	_delay_ms(1) ;

	LCD_Send_Cmd(0x28) ;
	_delay_ms(1) ;

	LCD_Send_Cmd(0x0E) ;
	_delay_ms(1) ;

	LCD_Send_Cmd(0x01) ;
	_delay_ms(4) ;

	LCD_Send_Cmd(0x06) ;
	_delay_ms(1) ;

}


void LCD_Send_Data (u8 Data)
{
	MDIO_voidSetPinValue(LCD_RS_PORT , LCD_RS_PIN , DIO_HIGH) ;
	MDIO_voidSetPinValue(LCD_RW_PORT , LCD_RW_PIN , DIO_LOW)  ;

	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN4 , READ_BIT(Data , 4)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN5 , READ_BIT(Data , 5)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN6 , READ_BIT(Data , 6)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN7 , READ_BIT(Data , 7)) ;

	MDIO_voidSetPinValue (LCD_E_PORT , LCD_E_PIN , DIO_HIGH) ;
	_delay_ms (1) ;
	MDIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , DIO_LOW)  ;
	_delay_ms (1) ;

	MDIO_voidSetPinValue(LCD_RS_PORT , LCD_RS_PIN , DIO_HIGH) ;
	MDIO_voidSetPinValue(LCD_RW_PORT , LCD_RW_PIN , DIO_LOW)  ;

	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN4 , READ_BIT(Data , 0)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN5 , READ_BIT(Data , 1)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN6 , READ_BIT(Data , 2)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN7 , READ_BIT(Data , 3)) ;

	MDIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , DIO_HIGH) ;
	_delay_ms (1) ;
	MDIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , DIO_LOW)  ;
	_delay_ms (1) ;

}


void LCD_Send_Cmd (u8 Cmd)
{

	MDIO_voidSetPinValue(LCD_RS_PORT , LCD_RS_PIN , DIO_LOW) ;
	MDIO_voidSetPinValue(LCD_RW_PORT , LCD_RW_PIN , DIO_LOW) ;

	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN4 , READ_BIT(Cmd , 4)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN5 , READ_BIT(Cmd , 5)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN6 , READ_BIT(Cmd , 6)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN7 , READ_BIT(Cmd , 7)) ;

	MDIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , DIO_HIGH) ;
	_delay_ms (1) ;
	MDIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , DIO_LOW)  ;
	_delay_ms (1) ;

	MDIO_voidSetPinValue(LCD_RS_PORT , LCD_RS_PIN , DIO_LOW) ;
	MDIO_voidSetPinValue(LCD_RW_PORT , LCD_RW_PIN , DIO_LOW) ;

	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN4 , READ_BIT(Cmd , 0)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN5 , READ_BIT(Cmd , 1)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN6 , READ_BIT(Cmd , 2)) ;
	MDIO_voidSetPinValue(LCD_DATA_PORT , DIO_PIN7 , READ_BIT(Cmd , 3)) ;

	MDIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , DIO_HIGH) ;
	_delay_ms (1) ;
	MDIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , DIO_LOW)  ;
	_delay_ms (1) ;

}


void LCD_Send_Str (u8* str)
{
	u8 Iterator_str = 0 ;
	while (str [Iterator_str] != '\0')
	{
		LCD_Send_Data (str [Iterator_str]) ;
		Iterator_str ++ ;
	}
}


void LCD_CLearDisplay (void)
{
	LCD_Send_Cmd(0x01) ;
	_delay_ms(4) ;
}


void LCD_ShiftLeft (void)
{
	LCD_Send_Cmd(0x18) ;
	_delay_ms(1) ;
}


void LCD_ShiftRight (void)
{
	LCD_Send_Cmd(0x1C) ;
	_delay_ms(1) ;
}


void LCD_Set_Cursor (u8 Row , u8 Col)
{
	u8 u8_AC ;
	if (Row == LCD_ROW0)
	{
		u8_AC = Col ;
	}
	else if (Row == LCD_ROW1)
	{
		u8_AC = 0x40 + Col ;
	}
	LCD_Send_Cmd(u8_AC + 0x80) ;
}


