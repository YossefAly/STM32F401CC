/***********************************/
/* SWC: Scheduler                  */
/* Author: Yossef Aly              */
/* Version: V1                     */
/* Date: 11 Jun 2023               */
/***********************************/
/*File Gaurd*/
#ifndef SCH_PRIVATE_H
#define SCH_PRIVATE_H

typedef struct
{
    void (*Pf)(void);
    u32 Periodicity;
    u32 FirstDelay;
}TCB_t;

TCB_t Tasks_Arr[NO_OF_TASKS] = {NULL};

static void Private_Scheduler(void);


#endif