
#ifndef HAL_HLCD_LCD_H_
#define HAL_HLCD_LCD_H_

#include "../../LIB/STD_types.h"

#define LCD_DATA_PORT  DIO_PORTA

#define LCD_RS_PORT    DIO_PORTB
#define LCD_RS_PIN     DIO_PIN0

#define LCD_ROW0       0
#define LCD_ROW1       1

#define LCD_RW_PORT    DIO_PORTB
#define LCD_RW_PIN     DIO_PIN1

#define LCD_E_PORT     DIO_PORTB
#define LCD_E_PIN      DIO_PIN2



void LCD_Initialization (void) ;
void LCD_Send_Data (u8 Data)   ;
void LCD_Send_Cmd (u8 Cmd)     ;
void LCD_Send_Str (u8* str)    ;
void LCD_CLearDisplay (void)   ;
void LCD_ShiftLeft (void)      ;
void LCD_ShiftRight (void)     ;
void LCD_Set_Cursor (u8 Row , u8 Col) ;

#endif /* REPO_HAL_LCD_LCD_H_ */
