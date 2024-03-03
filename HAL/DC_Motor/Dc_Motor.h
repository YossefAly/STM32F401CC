/***************************************************/
/* SWC : USART Driver                              */
/* Author :Yossef Aly                              */
/* Version : V 1.0                                 */
/* Date : 24 AUG 2023                              */
/* Description : SWC for Dc Motor                  */
/***************************************************/

/*File Guard*/
#ifndef DC_MOTOR_H
#define DC_MOTOR_H
void Motor_Initialize(u8 Copy_u8Enable,u8 Copy_u8EnablePeripheral,u8 Copy_u8IN1,u8 Copy_u8IN2);
u16 Motor_Speed(u8 Copy_u8Speed);
void Motor_Direction(u8 Copy_u8Direction,u8 Copy_u8EnablePeripheral,u8 Copy_u8PinID1,u8 Copy_u8PinID2);

#endif
