/***************************************************/
/* SWC : Timers Driver                             */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 23 AUG 2023                              */
/* Description : SWC for Timers                    */
/***************************************************/

/*Includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ATIMERS_Config.h"
#include "ATIMERS_Interface.h"
#include "ATIMERS_Private.h"


/******************************************************************************/
/* Func. Name : TIM1_voidInit                                                 */
/* I/p Arguments :Nothing                                                     */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Initialize Timer1                      */
/******************************************************************************/
void TIM1_voidInit(void){
    /*Enable Auto Reload Preload*/
    SET_BIT(TIM1_CR1,7);
    /*Set Timer Direction as Upcounter*/
    CLR_BIT(TIM1_CR1,4);
    CLR_BIT(TIM1_CR1,6);
    CLR_BIT(TIM1_CR1,5);

}
/******************************************************************************/
/* Func. Name : TIM1_voidInit                                                 */
/* I/p Arguments :Prescale                                                    */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set prescaler value for Timer1         */
/******************************************************************************/
void TIM1_voidPrescale(void){
    /*Set Timer Clock=Fclk/(PSC+1)
    for 10us 8000000/(x+1),PSC=79*/
    TIM1_PSC=0;
}
/******************************************************************************/
/* Func. Name : TIM1_voidAutoReload                                           */
/* I/p Arguments :Copy_u16Reload                                              */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set Timer1 Count Value                 */
/******************************************************************************/
void TIM1_voidAutoReload(u16 Copy_u16Reload){
    TIM1_ARR=Copy_u16Reload;
}
/******************************************************************************/
/* Func. Name : TIM1_voidCompare                                              */
/* I/p Arguments :Copy_u16Reload                                              */
/* I/p Arguments :Copy_u8Channel Options:CH1,CH2,CH3,CH4                      */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Set the Timer1 Duty Cycle              */
/******************************************************************************/

void TIM1_voidCompare(u16 Copy_u16Compare,u8 Copy_u8Channel){
    switch(Copy_u8Channel){
        case CH1:
            /*Set Duty Cycle*/
            TIM1_CCR1=Copy_u16Compare;
            /*Configure Channel 1 as an output*/
            CLR_BIT(TIM1_CCMR1,0);
            CLR_BIT(TIM1_CCMR1,1);
            /*Set preload Enable*/
            SET_BIT(TIM1_CCMR1,3);
            /*Select PWM mode 1*/
            SET_BIT(TIM1_CCMR1,6);
            SET_BIT(TIM1_CCMR1,5);
            CLR_BIT(TIM1_CCMR1,4);
            /*Capture Compare Polarity Active High*/
            CLR_BIT(TIM1_CCER,1);
            break;
        case CH2:
            /*Set Duty Cycle*/
            TIM1_CCR2=Copy_u16Compare;
            /*Configure Channel 1 as an output*/
            CLR_BIT(TIM1_CCMR1,8);
            CLR_BIT(TIM1_CCMR1,9);
            /*Set preload Enable*/
            SET_BIT(TIM1_CCMR1,11);
            /*Select PWM mode 1*/
            SET_BIT(TIM1_CCMR1,14);
            SET_BIT(TIM1_CCMR1,13);
            CLR_BIT(TIM1_CCMR1,12);
            /*Capture Compare Polarity Active High*/
            CLR_BIT(TIM1_CCER,1);
            break;
        case CH3:
            break;
        case CH4:
            break;
    }
}
void TIM1_voidEnable(void){
    /*Initialize all registers*/
    SET_BIT(TIM1_EGR,0);
    SET_BIT(TIM1_EGR,1);
    /*Enable Captue/Compare 1 as an Output*/
    SET_BIT(TIM1_CCER,0);
    /*Enable Timer main Output*/
    SET_BIT(TIM1_BDTR,15);
    /*Enable Timer1*/
    SET_BIT(TIM1_CR1,0);
}
void TIM1_voidDisable(void){    
    CLR_BIT(TIM1_EGR,0);
    CLR_BIT(TIM1_CCER,0);
    CLR_BIT(TIM1_BDTR,15);
    CLR_BIT(TIM1_CR1,0);}
u16 count(void){
	return TIM1_CCR1;
}
