/*
 * Motor.h
 *
 *  Created on: 23 Sep 2026
 *      Author: Admin
 */

#ifndef HAL_HDC_MOTOR_DC_MOTOR_H_
#define HAL_HDC_MOTOR_DC_MOTOR_H_

void HDC_Motor_voidInit (u8 A_u8Pin1Port , u8 A_u8Pin1Pin , u8 A_u8Pin2Port , u8 A_u8Pin2Pin) ;
void HDC_Motor_voidStop (u8 A_u8Pin1Port , u8 A_u8Pin1Pin , u8 A_u8Pin2Port , u8 A_u8Pin2Pin) ;
void HDC_Motor_voidCW (u8 A_u8Pin1Port , u8 A_u8Pin1Pin , u8 A_u8Pin2Port , u8 A_u8Pin2Pin) ;
void HDC_Motor_voidCCW (u8 A_u8Pin1Port , u8 A_u8Pin1Pin , u8 A_u8Pin2Port , u8 A_u8Pin2Pin) ;
void HDC_Motor_voidControl (u8 A_u8State , u8 A_u8Pin1Port , u8 A_u8Pin1Pin , u8 A_u8Pin2Port , u8 A_u8Pin2Pin) ;

#endif /* HAL_HDC_MOTOR_DC_MOTOR_H_ */
