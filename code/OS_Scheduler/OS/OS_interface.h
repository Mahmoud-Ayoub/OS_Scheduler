/*
 * OS_interface.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

void OS_Init (void) ; 
void OS_CreateTask (uint8 periority , uint32 periodicity , uint32 first_delay , void (*p_task) (void)) ;
void OS_Start (void) ; 



#endif /* OS_INTERFACE_H_ */