/***************************************************/
/* SWC : EXTI Driver                               */
/* Author : Yossef Aly                             */
/* Version : V 1.0                                 */
/* Date : 31 Aug 2023                              */
/* Description : SWC for EXTI                      */
/***************************************************/
/*File Gaurd*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void EXTI_voidInit(u8 Copy_u8PortID,u8 Copy_PinID);

#define Pin0  0
#define Pin1  1
#define Pin2  2
#define Pin3  3
#define Pin4  4
#define Pin5  5
#define Pin6  6
#define Pin7  7
#define Pin8  8
#define Pin9  9
#define Pin10 10
#define Pin11 11
#define Pin12 12
#define Pin13 13
#define Pin14 14
#define Pin15 15

#define IOA 0
#define IOB 1
#define IOC 2

#endif