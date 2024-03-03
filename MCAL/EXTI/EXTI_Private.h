/***************************************************/
/* SWC : EXTI Driver                               */
/* Author : Yossef Aly                             */
/* Version : V 1.0                                 */
/* Date : 31 Aug 2023                              */
/* Description : SWC for EXTI                      */
/***************************************************/
/*File Gaurd*/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//Base Address 0x40013C00

#define EXTI_IMR        *((volatile u32*)0x40013C00)
#define EXTI_EMR        *((volatile u32*)0x40013C04)
#define EXTI_RTSR       *((volatile u32*)0x40013C08)
#define EXTI_FTSR       *((volatile u32*)0x40013C0C)
#define EXTI_SWIER      *((volatile u32*)0x40013C10)
#define EXTI_PR         *((volatile u32*)0x40013C14)

//Base Address 0x4001 3800

#define SYSCFG_EXTICR    ((volatile u32*)0x40013808)

#define EXTI0  0
#define EXTI1  4
#define EXTI2  8
#define EXTI3  12
#define EXTI4  0
#define EXTI5  4
#define EXTI6  8
#define EXTI7  12
#define EXTI8  0
#define EXTI9  4
#define EXTI10 8
#define EXTI11 12
#define EXTI12 0
#define EXTI13 4
#define EXTI14 8
#define EXTI15 12
#define PAx 0b0000
#define PBx 0b0001
#define PCx 0b0010

#endif