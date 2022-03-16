/*
 * OS_program.c
 *
 *  Author: Mahmoud Ayoub
 */ 

#include "../MCAL/Timer/TIMER.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

/* Create array of structures for TCB required for each task */
TCB TCB_Tasks [NUMBER_OF_TASKS] ;

void OS_Init (void) {
	Timer_cb_func(OS_Scheduler) ;
}

void OS_CreateTask (uint8 periority , uint32 periodicity , uint32 first_delay , void (*p_task) (void)) {
	TCB_Tasks[periority].TCB_Periodicity = periodicity ; 
	TCB_Tasks[periority].TCB_First_Delay = first_delay ;
	TCB_Tasks[periority].TCB_p_task = p_task ;
} 

/* Non-Preemptive scheduler and priority based scheduling algorithm */
/* Scheduler execute Tasks periodically */
static void OS_Scheduler (void) {
	uint8 counter = 0 ; 
	for (counter=0 ; counter<NUMBER_OF_TASKS ; counter++) {
		if (TCB_Tasks[counter].TCB_First_Delay == 0) {
			// Call the Task
			TCB_Tasks[counter].TCB_p_task() ; 
			
			// Update the first delay again so that the task can be invoked periodically 
			TCB_Tasks[counter].TCB_First_Delay = TCB_Tasks[counter].TCB_Periodicity - 1 ; 
		}
		else {
			// Decrement the first delay by one tick
			TCB_Tasks[counter].TCB_First_Delay -- ; 
		}
	}
}

void OS_Start (void) {
	TIMER1_init() ;
}