/***********************************/
/* SWC: Scheduler                  */
/* Author: Yossef Aly              */
/* Version: V1                     */
/* Date: 11 Jun 2023               */
/***********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../../MCAL/STK/STK_Interface.h"

#include "SCH_Interface.h"
#include "SCH_Config.h"
#include "SCH_Private.h"

void SCH_StartOs(void)
{
    /*STK Init*/
    STK_voidInit();

    /*Interrupt occurs every 1 ms*/
    STK_voidSetIntervalPeriodic(1000, Private_Scheduler);
}

void SCH_voidCreateTask(u8 Copy_u8TaskPriority, u32 Copy_u32Periodicity, void(*pf)(void), u32 Copy_u32FirstDelay)
{
    /*I/P Validation*/
    if(Copy_u8TaskPriority > NO_OF_TASKS)
    {
        /*Do Nothing*/
    }
    else
    {
        Tasks_Arr[Copy_u8TaskPriority].Periodicity  = Copy_u32Periodicity;
        Tasks_Arr[Copy_u8TaskPriority].FirstDelay   = Copy_u32FirstDelay;
        Tasks_Arr[Copy_u8TaskPriority].Pf           = pf;
    }
}

static void Private_Scheduler(void)
{
    u8 Local_u8Counter;
    for(Local_u8Counter = 0; Local_u8Counter < NO_OF_TASKS; Local_u8Counter++)
    {
        if((Tasks_Arr[Local_u8Counter].FirstDelay == 0) && Tasks_Arr[Local_u8Counter].Pf != NULL)
        {
            Tasks_Arr[Local_u8Counter].Pf();
            Tasks_Arr[Local_u8Counter].FirstDelay = Tasks_Arr[Local_u8Counter].Periodicity - 1;
        }
        else
        {
            Tasks_Arr[Local_u8Counter].FirstDelay--;
        }
    }
}
