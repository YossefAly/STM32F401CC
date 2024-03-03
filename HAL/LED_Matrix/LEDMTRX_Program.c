#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "LEDMTRX_Interface.h"
#include "LEDMTRX_Config.h"
#include "LEDMTRX_Private.h"

void HLEDMAT_voidInit(void)
{
	/*Set Mode For Row --> Output*/
	GPIO_voidSetPinMode(HLEDMAT_ROW0,OUTPUT) ;
	GPIO_voidSetPinMode(HLEDMAT_ROW1,OUTPUT) ;
	GPIO_voidSetPinMode(HLEDMAT_ROW2,OUTPUT) ;
	GPIO_voidSetPinMode(HLEDMAT_ROW3,OUTPUT) ;
	GPIO_voidSetPinMode(HLEDMAT_ROW4,OUTPUT) ;
	GPIO_voidSetPinMode(HLEDMAT_ROW5,OUTPUT) ;
	GPIO_voidSetPinMode(HLEDMAT_ROW6,OUTPUT) ;
	GPIO_voidSetPinMode(HLEDMAT_ROW7,OUTPUT) ;

	/*Set Mode For Col --> Output*/
	MGPIO_voidSetPinMode(HLEDMAT_COL0,OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL1,OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL2,OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL3,OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL4,OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL5,OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL6,OUTPUT) ;
	MGPIO_voidSetPinMode(HLEDMAT_COL7,OUTPUT) ;

	/*Set PushPull For Rows*/
	MGPIO_voidSetOutputType(HLEDMAT_ROW0,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW1,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW2,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW3,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW4,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW5,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW6,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_ROW7,OUTPUT_PP) ;

	/*Set PushPull For Col */
	MGPIO_voidSetOutputType(HLEDMAT_COL0,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL1,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL2,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL3,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL4,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL5,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL6,OUTPUT_PP) ;
	MGPIO_voidSetOutputType(HLEDMAT_COL7,OUTPUT_PP) ;

	/*Set Pin Speed ForRows*/
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW0,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW1,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW2,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW3,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW4,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW5,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW6,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW7,OUTPUT_LS) ;

	/*Set Pin Speed For Col */
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL0,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL1,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL2,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL3,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL4,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL5,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL6,OUTPUT_LS) ;
	MGPIO_voidSetOutputSpeed(HLEDMAT_COL7,OUTPUT_LS) ;

}

void HLEDMAT_voidDisplay(u8 *Copy_u8Frame)
{
	/*Column 0*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[0]) ;	//12
	/*Enable Column0 */
	GPIO_voidSetPinValue(HLEDMAT_COL0,LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 1*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[1]) ;	//18
	/*Enable Column0 */
	GPIO_voidSetPinValue(HLEDMAT_COL1,LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 2*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[2]) ;
	/*Enable Column0 */
	GPIO_voidSetPinValue(HLEDMAT_COL2,LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 3*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[3]) ;
	/*Enable Column0 */
	GPIO_voidSetPinValue(HLEDMAT_COL3,LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 4*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[4]) ;
	/*Enable Column0 */
	GPIO_voidSetPinValue(HLEDMAT_COL4,LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 5*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[5]) ;
	/*Enable Column0 */
	GPIO_voidSetPinValue(HLEDMAT_COL5,LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms


	/*Column 6*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[6]) ;
	/*Enable Column0 */
	GPIO_voidSetPinValue(HLEDMAT_COL6,LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 7*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[7]) ;
	/*Enable Column0 */
	GPIO_voidSetPinValue(HLEDMAT_COL7,LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

}


static void HLEDMAT_voidDisableCols(void)
{
	GPIO_voidSetPinValue(HLEDMAT_COL0,HIGH) ;
	GPIO_voidSetPinValue(HLEDMAT_COL1,HIGH) ;
	GPIO_voidSetPinValue(HLEDMAT_COL2,HIGH) ;
	GPIO_voidSetPinValue(HLEDMAT_COL3,HIGH) ;
	GPIO_voidSetPinValue(HLEDMAT_COL4,HIGH) ;
	GPIO_voidSetPinValue(HLEDMAT_COL5,HIGH) ;
	GPIO_voidSetPinValue(HLEDMAT_COL6,HIGH) ;
	GPIO_voidSetPinValue(HLEDMAT_COL7,HIGH) ;
}

static void HLEDMAT_voidSetRowVlaues(u8 Copy_u8Frame)
{
	GPIO_voidSetPinValue(HLEDMAT_ROW0,GET_BIT(Copy_u8Frame,0)) ;
	GPIO_voidSetPinValue(HLEDMAT_ROW1,GET_BIT(Copy_u8Frame,1)) ;
	GPIO_voidSetPinValue(HLEDMAT_ROW2,GET_BIT(Copy_u8Frame,2)) ;
	GPIO_voidSetPinValue(HLEDMAT_ROW3,GET_BIT(Copy_u8Frame,3)) ;
	GPIO_voidSetPinValue(HLEDMAT_ROW4,GET_BIT(Copy_u8Frame,4)) ;
	GPIO_voidSetPinValue(HLEDMAT_ROW5,GET_BIT(Copy_u8Frame,5)) ;
	GPIO_voidSetPinValue(HLEDMAT_ROW6,GET_BIT(Copy_u8Frame,6)) ;
	GPIO_voidSetPinValue(HLEDMAT_ROW7,GET_BIT(Copy_u8Frame,7)) ;
}

