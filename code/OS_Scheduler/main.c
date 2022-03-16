/*
 * OS_Scheduler.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include "./MCAL/Timer/TIMER.h"
#include "./HAL/LED/LED.h"
#include "./OS/OS_interface.h"

void Init_Task (void) ; 
void Task1_Green_LED (void) ; 
void Task2_Yellow_LED (void) ;
void Task3_Red_LED (void) ;

int main(void)
{
	/* Initialization */ 
	OS_Init() ; 
    
	/* Create Tasks */
	OS_CreateTask(0 , 0 , 0 , Init_Task) ; 
    OS_CreateTask(1 , 1000 , 0 , Task1_Green_LED) ; 
	OS_CreateTask(2 , 2000 , 0 , Task2_Yellow_LED) ; 
	OS_CreateTask(3 , 3000 , 0 , Task3_Red_LED) ; 
	
	/* Start the Scheduler */
	OS_Start() ; 
	
    while(1)
    {
	   
    }
}
void Init_Task (void) {
	LED_init(portA , 2) ;
	LED_init(portA , 1) ;
	LED_init(portA , 0) ;
}

void Task1_Green_LED (void) {
	LED_TOGGLE(portA , 2) ; 
}

void Task2_Yellow_LED (void) {
	LED_TOGGLE(portA , 1) ;
}

void Task3_Red_LED (void) {
	LED_TOGGLE(portA , 0) ;
}
