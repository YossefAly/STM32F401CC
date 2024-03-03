/***************************************************/
/* SWC : STK Driver                                */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 22 AUG 2023                              */
/* Description : SWC for USART                     */
/***************************************************/

/*File Guard*/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART_voidInit(u8 Copy_u8USARTx);
void USART_voidEnable(u8 Copy_u8USARTx);
void USART_voidTransmit(u8  Copy_u8str);
void USART_voidRecieve(u8*word);

typedef enum{
    USART_1,
    USART_2,
    USART_6
}USART_ID;
#define MAX_BUFFER_LENGTH

#endif
