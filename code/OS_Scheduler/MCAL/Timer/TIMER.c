/*
 * TIMER.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "TIMER.h"

/*
	Configuration implemented : 
	F_CPU = 1 MHz
	prescaler = 8
	tick time = 1 ms
*/

void (*gpfun) (void) ;          // global pointer to function

// tick time = 1 ms
void TIMER1_init (void) {				     
	SET_BIT(TC1_Control_B_REG , 1) ;         //set the pre-scalar as 8   ,  freq = 1 MHz
	INT_Timer_Enable() ;
	INT_global_Enable() ;
	TC1_Data_H_REG = 0xFF ;					// delay ticks = 65535 - (delay_ms * 1000 * 1) / 8 
	TC1_Data_L_REG = 0x82 ;  
	

}
uint8 TIMER1_end (void) {
	while((TC1_Status_REG & (1<<2)) == 0);	// wait till the overflow of A flag is SET
	return 1 ; 
}
void TIMER1_reset (void) {
	TC1_Data_H_REG = 0xFF ;
	TC1_Data_L_REG = 0x82 ;
	SET_BIT (TC1_Status_REG , 2) ;   //clear timer1 overflow flag
}

void INT_global_Enable (void) {
	SET_BIT (Status_REG , 7) ;
}

void INT_Timer_Enable (void) {
	SET_BIT (TC1_INTMask_REG , 2) ;
}

void Timer_cb_func (void (*p_fun) (void)) {
	gpfun = p_fun ;
}

void __vector_9(void)         // Timer1 ISR to call the scheduler
{
	TIMER1_reset() ;
	gpfun() ;
	
}

