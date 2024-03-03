/***********************************/
/* SWC: Scheduler                  */
/* Author: Yossef ALy             */
/* Version: V1                     */
/* Date: 11 Jun 2023               */
/***********************************/
/*File Gaurd*/
#ifndef SCH_INTERFACE_H
#define SCH_INTERFACE_H

void SCH_StartOs(void);
void SCH_voidCreateTask(u8 Copy_u8TaskPriority, u32 Copy_u32Periodicity, void(*pf)(void), u32 Copy_u32FirstDelay);


#endif