/*
 * OS_private.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

/* 
	TCB parameters : 
	1- First delay >> when the task is arrived
	2- Periodicity >> interval(number of ticks) after which the task will be executed periodically
	3- Base address of the task 
*/

typedef struct {
	uint32 TCB_First_Delay ;        
	uint32 TCB_Periodicity ; 
	void (*TCB_p_task) (void) ;
} TCB ;

/* Protection for scheduler function */
static void OS_Scheduler (void) ;



#endif /* OS_PRIVATE_H_ */