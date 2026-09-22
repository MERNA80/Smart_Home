///*
// * seven-Segment.c
// *
// *  Created on: Sep 18, 2026
// *      Author: Mernna Ahmed
// */
//
//#include <avr/delay.h>
//
//void sev_Seg(unsigned char number)
//{
//	Seven_segment_Initialization();
//	while(1)
//	{
//		if(number <100)
//		{// 48 /10   4
//			unsigned char right = number % 10;
//			unsigned char left = number / 10;
//
//			Seven_segment_Disable1();
//			Seven_segment_Disable2();
//
//			Seven_segment_Write_Number(left);
//			Seven_segment_Enable1();
//			_delay_ms(10);
//			Seven_segment_Disable1();
//			Seven_segment_Write_Number(right);
//			Seven_segment_Enable2();
//			_delay_ms(10);
//		}
//	}
//}
