/***************************************************/
/* SWC : USART Driver                              */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 24 AUG 2023                              */
/* Description : SWC for Dc Motor                  */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dc_Motor.h"
#include "ATIMERS_Interface.h"
#include "GPIO_Interface.h"

void Motor_Initialize(u8 Copy_u8Enable,u8 Copy_u8EnablePeripheral,u8 Copy_u8IN1,u8 Copy_u8IN2){
    if((Copy_u8EnablePeripheral>IOC)||(Copy_u8Enable>15)||(Copy_u8IN1>15)||(Copy_u8IN2>15)){
        asm("NOP");
    }
    else{
        switch (Copy_u8EnablePeripheral)
        {
            case IOA:
                switch(Copy_u8Enable){
                     case PIN8:
                        /*Enable Alternate Functions for PA8*/
                        GPIO_voidSetPinMode(IOA,8,AF);
                        GPIO_voidSetPinPUPD(IOA,8,PD);
                        /*Select AF1 for PA8*/
                        GPIO_voidTIM1Init();
                        break;
                    default:
                        break;        }
                break;
            case IOB:
                break;
            case IOC:
                break;
            default:
                break;
    }
        /*Pins are OUTPUT, Push Pull, LS*/
        GPIO_voidSetPinMode(Copy_u8EnablePeripheral,Copy_u8IN1,OUTPUT);
        GPIO_voidSetPinMode(Copy_u8EnablePeripheral,Copy_u8IN2,OUTPUT);
        GPIO_voidSetPinType(Copy_u8EnablePeripheral,Copy_u8IN1,OUTPUT_PP);
        GPIO_voidSetPinType(Copy_u8EnablePeripheral,Copy_u8IN2,OUTPUT_PP);
        GPIO_voidSetPinSpeed(Copy_u8EnablePeripheral,Copy_u8IN1,OUTPUT_LS);
        GPIO_voidSetPinSpeed(Copy_u8EnablePeripheral,Copy_u8IN2,OUTPUT_LS);
        /*By default IN1 is High and IN2 is low*/
        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
    }
}
u16 Motor_Speed(u8 Copy_u8Speed){
    if(Copy_u8Speed==0){return 0;}
    else{
        /*resolution=(FFFF/100)*/
    return Copy_u8Speed*255+255;}}
void Motor_Direction(u8 Copy_u8Direction,u8 Copy_u8EnablePeripheral,u8 Copy_u8PinID1,u8 Copy_u8PinID2){
    switch(Copy_u8Direction){
        case 70:
            GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8PinID1, HIGH);
            GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8PinID2, LOW);
            break;
        case 66:
            GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8PinID1, LOW);
            GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8PinID2, HIGH);
            break;
        default:
            break;
    }
}
