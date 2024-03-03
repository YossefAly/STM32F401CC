/***************************************************/
/* SWC : STK Driver                                */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 22 AUG 2023                              */
/* Description : SWC for USART                     */
/***************************************************/
/*File Gaurd*/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

//USART1 base address 0x40011000
//USART2 base address 0x40044000
//USART6 base address 0x40011400


typedef struct
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;
}USART;

#define USART1                       ((volatile USART*)0x40011000)   //USART1->
#define USART2                       ((volatile USART*)0x40044000)   //USART2->
#define USART6                       ((volatile USART*)0x40011400)   //USART6->


#endif
