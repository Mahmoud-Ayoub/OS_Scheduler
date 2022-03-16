# OS_Scheduler
Simple non-preemptive OS scheduler for embedded applications.

## Description : 
This is the implementation of a non-preemptive priority based OS scheduler which manages multitasking on a specific hardware architecture. 
This scheduler executes periodic tasks based on its assigned periority and periodicity.

## Supported BSP :
ATmega32 MCU

## How to use : 
- Configure the number of tasks in *OS_config.h*
- Design the required tasks 
- Call **OS_init** API 
- Create an instance of a task by calling **OS_CreateTask** API giving it the required parameters
- Call **OS_Start** API  
