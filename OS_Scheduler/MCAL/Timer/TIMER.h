/*
 * TIMER.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../Std_Types.h"
#include "../Bit_Math.h"

#define TC1_Control_A_REG					(*((volatile uint8*)0x4F))
#define TC1_Control_B_REG					(*((volatile uint8*)0x4E))
#define TC1_Data_L_REG						(*((volatile uint8*)0x4C))
#define TC1_Data_H_REG						(*((volatile uint8*)0x4D))
#define TC1_OutputCompare_A_L_REG			(*((volatile uint8*)0x4A))
#define TC1_OutputCompare_A_H_REG			(*((volatile uint8*)0x4B))
#define TC1_OutputCompare_B_L_REG			(*((volatile uint8*)0x48))
#define TC1_OutputCompare_B_H_REG			(*((volatile uint8*)0x49))
#define TC1_Status_REG						(*((volatile uint8*)0x58))
#define TC1_INTMask_REG						(*((volatile uint8*)0x59))
#define Status_REG							(*((volatile uint8*)0x5F))

void TIMER1_init (void) ;     
uint8 TIMER1_end (void) ; 
void TIMER1_reset (void) ; 

void INT_global_Enable (void) ;
void INT_Timer_Enable (void) ;
void Timer_cb_func (void (*p_fun) (void)) ;
void __vector_9(void) __attribute__((signal));       // ISR for Timer 1 overflow

#endif /* TIMER_H_ */