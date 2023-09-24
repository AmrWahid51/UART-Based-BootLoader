/*
 * BIT_MATH.h

 *
 *  Created on: Aug 9, 2023
 *      Author: LENOVO
 */





#ifndef UTILS_BIT_MATH_H_
#define UTILS_BIT_MATH_H_

#define   SET_BIT(VAR,BIT)  (VAR)|= ( 1<<(BIT))  // DDRA |=(1<<pin)
#define   TOG_BIT(VAR,BIT)  (VAR)^= ( 1<<(BIT))
#define   CLR_BIT(VAR,BIT)  (VAR)&= ~(1<< (BIT))
#define   GET_BIT(VAR,BIT)   ((VAR>>(BIT)) & 1)  // =  (( VAR &(1<<BIT))>>BIT)
#define   BIT_IS_CLEAR(VAR,BIT)  !(( VAR &(1<<BIT))>>BIT)

#endif /* UTILS_COMMON_MACROS_H_ */




