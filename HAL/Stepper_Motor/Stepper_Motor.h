/***************************************************/
/* SWC : USART Driver                              */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 24 AUG 2023                              */
/* Description : SWC for Stepper Motor             */
/***************************************************/

/*File Guard*/
#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

volatile u8 motornowdegreer;
volatile u8 motornowdegreel;
volatile u8 motornowstep;
volatile u8 motordirection;

void Stepper_Initialize(u8 Copy_u8EnablePeripheral,u8 Copy_u8IN1,u8 Copy_u8IN2,u8 Copy_u8IN3,u8 Copy_u8IN4);
void Motor_rotation(u8 Copy_u8Direction,u8 degree,u8 Copy_u8EnablePeripheral,u8 Copy_u8IN1,u8 Copy_u8IN2,u8 Copy_u8IN3,u8 Copy_u8IN4);

#endif
