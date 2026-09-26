/*
 * Bit_Math.h
 *
 *  Created on: Sep 19, 2026
 *      Author: Mernna ahmed
 */

#ifndef REPO_LIB_BIT_MATH_H_
#define REPO_LIB_BIT_MATH_H_

#define SET_BIT(reg , bit)  ((reg)|=(1<<(bit)))
#define TOG_BIT(reg , bit)  ((reg)^=(1<<(bit)))
#define CLR_BIT(reg , bit)  ((reg)&=(~(1<<(bit))))
#define READ_BIT(reg , bit) (((reg)&(1<<(bit)))>>(bit))



#endif /* REPO_LIB_BIT_MATH_H_ */
