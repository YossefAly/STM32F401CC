/***************************************************/
/* SWC : USART Driver                              */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 24 AUG 2023                              */
/* Description : SWC for Stepper Motor             */
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_Interface.h"
#include "Stepper_Motor.h"
#include "GPIO_Interface.h"



void Stepper_Initialize(u8 Copy_u8EnablePeripheral,u8 Copy_u8IN1,u8 Copy_u8IN2,u8 Copy_u8IN3,u8 Copy_u8IN4){
if((Copy_u8EnablePeripheral>IOC)||(Copy_u8IN1>15)||(Copy_u8IN2>15)||(Copy_u8IN3>15)||(Copy_u8IN4>15)){
        asm("NOP");
    }
else{
     /*Pins are OUTPUT, Push Pull, LS*/
        GPIO_voidSetPinMode(Copy_u8EnablePeripheral,Copy_u8IN1,OUTPUT);
        GPIO_voidSetPinMode(Copy_u8EnablePeripheral,Copy_u8IN2,OUTPUT);
        GPIO_voidSetPinMode(Copy_u8EnablePeripheral,Copy_u8IN3,OUTPUT);
        GPIO_voidSetPinMode(Copy_u8EnablePeripheral,Copy_u8IN4,OUTPUT);
        GPIO_voidSetPinType(Copy_u8EnablePeripheral,Copy_u8IN1,OUTPUT_PP);
        GPIO_voidSetPinType(Copy_u8EnablePeripheral,Copy_u8IN2,OUTPUT_PP);
        GPIO_voidSetPinType(Copy_u8EnablePeripheral,Copy_u8IN3,OUTPUT_PP);
        GPIO_voidSetPinType(Copy_u8EnablePeripheral,Copy_u8IN4,OUTPUT_PP);
        GPIO_voidSetPinSpeed(Copy_u8EnablePeripheral,Copy_u8IN1,OUTPUT_LS);
        GPIO_voidSetPinSpeed(Copy_u8EnablePeripheral,Copy_u8IN2,OUTPUT_LS);
        GPIO_voidSetPinSpeed(Copy_u8EnablePeripheral,Copy_u8IN3,OUTPUT_LS);
        GPIO_voidSetPinSpeed(Copy_u8EnablePeripheral,Copy_u8IN4,OUTPUT_LS);
        /*By default all pins are LOW*/
        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
}
}
void Motor_rotation(u8 Copy_u8Direction,u8 degree,u8 Copy_u8EnablePeripheral,u8 Copy_u8IN1,u8 Copy_u8IN2,u8 Copy_u8IN3,u8 Copy_u8IN4){
    /*Assuming Motor step size is 1 degree*/
    
    if(motordirection==0){
    switch(Copy_u8Direction){
        case 82:
            while(motornowdegreer<degree){
                switch(motornowstep){
                    case 0:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
                        motornowstep=2;
                        break;
                    case 2:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
                        motornowstep=4;
                        break;
                    case 4:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
                        motornowstep=1;
                        break;
                    case 1:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
                        motornowstep=3;
                        break;
                    case 3:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
                        motornowstep=2;
                        break;
                }
                motornowdegreer++;
            }
            motordirection=82;
            break;
        case 76:
             while(motornowdegreel<degree){
                switch(motornowstep){
                    case 0:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
                        motornowstep=1;
                        break;
                    case 2:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
                        motornowstep=3;
                        break;
                    case 4:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
                        motornowstep=2;
                        break;
                    case 1:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
                        motornowstep=4;
                        break;
                    case 3:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
                        motornowstep=1;
                        break;
                }
                motornowdegreel++;
            }
            motordirection=76;
            break;
        default:
            break;
    }
    }
    else if((motordirection==82)&&(Copy_u8Direction==motordirection)&&(motornowdegreer>degree)){
        while(motornowdegreer>degree){
        	switch(motornowstep){
        	                    case 0:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
        	                        motornowstep=1;
        	                        break;
        	                    case 2:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
        	                        motornowstep=3;
        	                        break;
        	                    case 4:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
        	                        motornowstep=2;
        	                        break;
        	                    case 1:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
        	                        motornowstep=4;
        	                        break;
        	                    case 3:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
        	                        motornowstep=1;
        	                        break;
        	                }
            motornowdegreer--;
        }
    }
     else if((motordirection==82)&&(Copy_u8Direction==motordirection)&&(motornowdegreer<degree)){
        while(motornowdegreer<degree){
        	 switch(motornowstep){
        	                    case 0:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
        	                        motornowstep=2;
        	                        break;
        	                    case 2:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
        	                        motornowstep=4;
        	                        break;
        	                    case 4:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
        	                        motornowstep=1;
        	                        break;
        	                    case 1:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
        	                        motornowstep=3;
        	                        break;
        	                    case 3:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
        	                        motornowstep=2;
        	                        break;
        	                }
            motornowdegreer++;
        }
    }
     else if((motordirection==82)&&(Copy_u8Direction!=motordirection)){
        while(motornowdegreel<degree){
        	switch(motornowstep){
        	                    case 0:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
        	                        motornowstep=1;
        	                        break;
        	                    case 2:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
        	                        motornowstep=3;
        	                        break;
        	                    case 4:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
        	                        motornowstep=2;
        	                        break;
        	                    case 1:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
        	                        motornowstep=4;
        	                        break;
        	                    case 3:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
        	                        motornowstep=1;
        	                        break;
        	                }
                if(motornowdegreer!=0){
                    motornowdegreer--;}
                else{
                    motornowdegreel++;
                }
        }
        motordirection=76;
    }
         else if((motordirection==76)&&(Copy_u8Direction==motordirection)&&(motornowdegreel<degree)){
        while(motornowdegreel<degree){
        	switch(motornowstep){
        	                    case 0:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
        	                        motornowstep=1;
        	                        break;
        	                    case 2:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
        	                        motornowstep=3;
        	                        break;
        	                    case 4:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
        	                        motornowstep=2;
        	                        break;
        	                    case 1:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
        	                        motornowstep=4;
        	                        break;
        	                    case 3:
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
        	                        STK_voidSetBusyWait(4000000);
        	                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
        	                        motornowstep=1;
        	                        break;
        	                }
            motornowdegreel++;
        }
    }
    else if((motordirection==76)&&(Copy_u8Direction==motordirection)&&(motornowdegreel>degree)){
        while(motornowdegreel>degree){
                switch(motornowstep){
                    case 0:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
                        motornowstep=2;
                        break;
                    case 2:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
                        motornowstep=4;
                        break;
                    case 4:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
                        motornowstep=1;
                        break;
                    case 1:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
                        motornowstep=3;
                        break;
                    case 3:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
                        motornowstep=2;
                        break;
                }
            motornowdegreel--;
        }
    }
    
     else if((motordirection==76)&&(Copy_u8Direction!=motordirection)){
        while(motornowdegreer<degree){
                           switch(motornowstep){
                    case 0:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
                        motornowstep=2;
                        break;
                    case 2:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN4, LOW);
                        motornowstep=4;
                        break;
                    case 4:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN1, LOW);
                        motornowstep=1;
                        break;
                    case 1:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN3, LOW);
                        motornowstep=3;
                        break;
                    case 3:
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, HIGH);
                        STK_voidSetBusyWait(4000000);
                        GPIO_voidSetPinValue(Copy_u8EnablePeripheral, Copy_u8IN2, LOW);
                        motornowstep=2;
                        break;
                }
                if(motornowdegreel!=0){
                    motornowdegreel--;}
                else{
                    motornowdegreer++;
                }
        }
        motordirection=82;
    }
}
