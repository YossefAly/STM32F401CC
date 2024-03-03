/***************************************************/
/* SWC : STK Driver                                */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 22 AUG 2023                              */
/* Description : SWC for USART                     */
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"

static void (*GpF)(u8*) = NULL;
u8* Global_V;
/******************************************************************************/
/* Func. Name : USART_voidInit                                                */
/* I/p Arguments : Copy_u8USARTx Options:USART1,USART2,USART6                 */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Initialize the USART                   */
/******************************************************************************/
void USART_voidInit(u8 Copy_u8USARTx){
    switch(Copy_u8USARTx){
        case USART_1:
            /* Select oversampling by 16 mode */
            CLR_BIT(USART1->CR1,15);

            /* Select one sample bit method */
            SET_BIT(USART1->CR3,11);

            /* Select 1 Start bit, 9 Data bits, n Stop bit */
            SET_BIT(USART1->CR1,12);

            /* Select 1 stop bit */
            CLR_BIT(USART1->CR2,12);
            CLR_BIT(USART1->CR2,13);
            /* Enable parity control */
            SET_BIT(USART1->CR1,10);

            /* Select odd parity */
            SET_BIT(USART1->CR1,1);

            /* Set baud rate = 115200 Bps
            * USARTDIV = Fck / (16 * baud_rate)
            *          = 8000000 / (16 * 115200) = 4.34
            *
            * DIV_Fraction = 16 * 0.34 = 5.44 = 5
            * DIV_Mantissa = 4
            *
            * BRR          = 0x45 */
            USART1->BRR = 0x45;
            break;
        case USART_2:
                        /* Select oversampling by 16 mode */
            CLR_BIT(USART2->CR1,15);

            /* Select one sample bit method */
            SET_BIT(USART2->CR3,11);

            /* Select 1 Start bit, 9 Data bits, n Stop bit */
            SET_BIT(USART2->CR1,12);

            /* Select 1 stop bit */
            CLR_BIT(USART2->CR2,12);
            CLR_BIT(USART2->CR2,13);
            /* Enable parity control */
            SET_BIT(USART2->CR1,10);

            /* Select odd parity */
            SET_BIT(USART2->CR1,1);

            /* Set baud rate = 115200 Bps
            * USARTDIV = Fck / (16 * baud_rate)
            *          = 8000000 / (16 * 115200) = 4.34
            *
            * DIV_Fraction = 16 * 0.34 = 5.44 = 5
            * DIV_Mantissa = 4
            *
            * BRR          = 0x45 */
            USART2->BRR = 0x45;
            break;
                case USART_6:
            /* Select oversampling by 16 mode */
            CLR_BIT(USART6->CR1,15);

            /* Select one sample bit method */
            SET_BIT(USART6->CR3,11);

            /* Select 1 Start bit, 9 Data bits, n Stop bit */
            SET_BIT(USART6->CR1,12);

            /* Select 1 stop bit */
            CLR_BIT(USART6->CR2,12);
            CLR_BIT(USART6->CR2,13);
            /* Enable parity control */
            SET_BIT(USART6->CR1,10);

            /* Select odd parity */
            SET_BIT(USART6->CR1,1);

            /* Set baud rate = 115200 Bps
            * USARTDIV = Fck / (16 * baud_rate)
            *          = 8000000 / (16 * 115200) = 4.34
            *
            * DIV_Fraction = 16 * 0.34 = 5.44 = 5
            * DIV_Mantissa = 4
            *
            * BRR          = 0x45*/
            USART6->BRR = 0x45;
            break;
    }
}

/******************************************************************************/
/* Func. Name : USART_voidEnable                                              */
/* I/p Arguments : Copy_u8USARTx Options:USART1,USART2,USART6                 */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Enable the USART RX,TX                 */
/******************************************************************************/
void USART_voidEnable(u8 Copy_u8USARTx){
    switch(Copy_u8USARTx){
        case USART_1:
            /* Enable USART1 */
            SET_BIT(USART1->CR1,13);
            /* Enable transmitter */
            SET_BIT(USART1->CR1,3);
             /* Enable receiver */
            SET_BIT(USART1->CR1,2);
            /*Enable Receive Interrupt*/
            SET_BIT(USART1->CR1,5);
            break;
        case USART_2:  
            /* Enable USART2 */
            SET_BIT(USART2->CR1,13);
            /* Enable transmitter */
            SET_BIT(USART2->CR1,3);
             /* Enable receiver */
            SET_BIT(USART2->CR1,2);
            break;
         case USART_6:
             /* Enable USART6 */
            SET_BIT(USART6->CR1,13);
            /* Enable transmitter */
            SET_BIT(USART6->CR1,3);
             /* Enable receiver */
            SET_BIT(USART6->CR1,2);
            break;
            }
}

/******************************************************************************/
/* Func. Name : USART_voidStrTransmit                                         */
/* I/p Arguments : Copy_u8str Options: Sended message                         */
/* I/p Arguments : Copy_u8size Options:Size of Sended message                 */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Send message through UASRT             */
/******************************************************************************/

void USART_voidTransmit(u8 Copy_u8str){

      /* Check USART status register */
      while(!(USART1->SR & GET_BIT(USART1->SR,7)))
      {
        /* Wait for transmission buffer empty flag */
      }
      USART1->DR=(Copy_u8str&0xff);
}

/******************************************************************************/
/* Func. Name : USART_voidStrRecieve                                          */
/* I/p Arguments :Nothing                                                     */
/* Return : Nothing                                                           */
/* Desc. : This Api allows the user to Recieve message through UASRT          */
/******************************************************************************/

void USART_voidRecieve(u8* chara){
	 u8 i = 0;
	    char receivedChar;

	    while (i < 10 - 1) {
	        while (!(USART1->SR&GET_BIT(USART1->SR,5))); // Wait until data is received
	        receivedChar = USART1->DR & 0xFF;

	        if (receivedChar == '\r' || receivedChar == '\n') {
	            break; // Stop receiving if Enter key is pressed
	        }

	        chara[i] = receivedChar;
	        i++;
	    }

	    chara[i] = '\0'; // Null-terminate the received word
	}
void USART_voidRecieveInt(void (*LpF)(u8* Char)){
	GpF=LpF;
}
void USART1_IRQHandler(void){
	GpF(Global_V);
}
