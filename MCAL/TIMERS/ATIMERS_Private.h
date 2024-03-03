/***************************************************/
/* SWC : Timers Driver                             */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 23 AUG 2023                              */
/* Description : SWC for Timers                    */
/***************************************************/

/*File Guard*/
#ifndef ATIMERS_PRIVATE_H
#define ATIMER_PRIVATE_H

//Timer1 Base Address 0x40010000
#define  TIM1_CR1    *((volatile u32*)0x40010000)
#define  TIM1_EGR    *((volatile u32*)0x40010014)
#define  TIM1_CCMR1  *((volatile u32*)0x40010018)
#define  TIM1_CCER   *((volatile u32*)0x40010020)
#define  TIM1_CNT    *((volatile u32*)0x40010024)
#define  TIM1_PSC    *((volatile u32*)0x40010028)
#define  TIM1_ARR    *((volatile u32*)0x4001002C)
#define  TIM1_RCR    *((volatile u32*)0x40010030)
#define  TIM1_CCR1   *((volatile u32*)0x40010034)
#define  TIM1_CCR2   *((volatile u32*)0x40010038)
#define  TIM1_CCR3   *((volatile u32*)0x4001003C)
#define  TIM1_CCR4   *((volatile u32*)0x40010040)
#define  TIM1_BDTR   *((volatile u32*)0x40010044)

#endif