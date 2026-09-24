#ifndef SMART_HOME_APP_LCD_APP_H_
#define SMART_HOME_APP_LCD_APP_H_


void LCD_Lab_EnterPassword_mas(void);                // LCD  لجمله الاولي اللي هتظهر علي ال

void LCD_Lab_PasswordStar_mas(u8 A_u8Index);         // * هيعدي علي كل اندكس في الباسوورد ويبدله ب

void LCD_Lab_Wrong_mas(void);                        // رسالة الباسوورد الغلط

void LCD_Lab_Correct_mas(void);                     // رسالة الباسوورد الصح

void LCD_Lab_Invalid_mas(void);                     // لو الباسوور مش ارقام

void LCD_Lab_Home_Statuse_mas(void);

void LCD_Lab_DisplayHomeStatus( u8 LED1_status,    u8 LED2_status,   u8 TV_status,   u8 AC_status);    // on off


#endif /* SMART_HOME_APP_LCD_APP_H_ */
