/***************************************************/
/* SWC : Timers Driver                             */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 23 AUG 2023                              */
/* Description : SWC for Timers                    */
/***************************************************/
/*File Guard*/
#ifndef ATIMERS_INTERFACEE_H
#define ATIMER_INTERFACE_H

void TIM1_voidInit(void);
void TIM1_voidPrescale(void);
void TIM1_voidAutoReload(u16 Copy_u16Reload);
void TIM1_voidCompare(u16 Copy_u16Compare,u8 Copy_8Channel);
void TIM1_voidEnable(void);
void TIM1_voidDisable(void);
u16 count(void);

typedef enum{
    CH1,
    CH2,
    CH3,
    CH4
}Channels;



#endif
