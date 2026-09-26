#ifndef SMART_HOME_APP_LCD_APP_H_
#define SMART_HOME_APP_LCD_APP_H_
#include "../LIB/STD_types.h"

void LCD_Lab_EnterPassword_mas(void);
void LCD_Lab_PasswordStar_mas(u8 A_u8Index);
void LCD_Lab_Wrong_mas(void);

void LCD_Lab_Correct_mas(void);

void LCD_Lab_Invalid_mas(void);

void LCD_Lab_Home_Statuse_mas(void);

void LCD_Lab_DisplayHomeStatus( u8 LED1_status,    u8 LED2_status,   u8 TV_status,   u8 AC_status);    // on off


#endif /* SMART_HOME_APP_LCD_APP_H_ */
