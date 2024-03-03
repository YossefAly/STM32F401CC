/***************************************************/
/* SWC : EXTI Driver                               */
/* Author : Yossef Aly                             */
/* Version : V 1.0                                 */
/* Date : 31 Aug 2023                              */
/* Description : SWC for EXTI                      */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

void EXTI_voidInit(u8 Copy_u8PortID,u8 Copy_PinID){

    switch(Copy_u8PortID){
        case IOA:
            switch(Copy_PinID){
                case Pin0:
                /*Map EXTI0 To A0*/
                    SYSCFG_EXTICR[0]|=PAx;
                /*Set Rising Edge*/
                    SET_BIT(EXTI_RTSR,0);
                /*Disable Falling Edge*/
                    CLR_BIT(EXTI_FTSR,0);
                /*Enable Interrupts for EXTI0*/
                    SET_BIT(EXTI_IMR,0);
                /*Enable Event Trigger*/
                    SET_BIT(EXTI_EMR,0);
                    break;
                /*The Rest To do*/
            }
    }
}