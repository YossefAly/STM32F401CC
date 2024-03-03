#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"

#include "GPIO_Interface.h"

#include "STK_Interface.h"

#include "NVIC_Interface.h"

#include "USART_Interface.h"

#include "ATIMERS_Interface.h"

#include "Dc_Motor.h"

#include "Stepper_Motor.h"

    void Print();

    int main(){
	/*Init System Clock*/
	RCC_voidInitSysClk();
	/*Enable Clock for USART1*/
	RCC_voidEnablePeripheralClk(APB2, 4);
	/*Enable Clock for PortB*/
	RCC_voidEnablePeripheralClk(AHB1,1);
		/*Enable Clock for PortA*/
	RCC_voidEnablePeripheralClk(AHB1,0);
	/*Enable Clock for Timer1*/
	RCC_voidEnablePeripheralClk(APB2, 0);
	/*Initialize Dc Motor*/
	Motor_Initialize(PIN8,IOA,PIN7,PIN6);
	/*Initialize Stepper Motor*/
	Stepper_Initialize(IOA,PIN0,PIN1,PIN2,PIN3);
	/*Enable Alternate Functions for PB6-7*/
	GPIO_voidSetPinMode(IOB,6,AF);
	GPIO_voidSetPinMode(IOB,7,AF);
    /*Set Pins 6 PUSHPULL*/
	GPIO_voidSetPinType(IOB,6,OUTPUT_PP);
	/*Set Pin6 Speed*/
	GPIO_voidSetPinSpeed(IOB,6,OUTPUT_LS);
	/*Set Pin7 Pull up*/
	GPIO_voidSetPinPUPD(IOB,7,PU);
	/*Set AF to be USART at Pins6-7*/
	GPIO_voidUARTInit(USART_1);
    /*Initialize USART1*/
    USART_voidInit(USART_1);
    /*Enable USART1*/
    USART_voidEnable(USART_1);
    /*Initialize Timer1*/
    TIM1_voidInit();
    /*Initialize prescale*/
    TIM1_voidPrescale();
    /*Initialize count value*/
    TIM1_voidAutoReload(0xFFFF);
    /*Duty Cycle 50%*/
    TIM1_voidCompare((0x7FFF),0);
    /*Enable Timer*/
    TIM1_voidEnable();
	/*Enable NVIC for USART1*/
	NVIC_voidEnablePeriInt(37);
    STK_voidInit();
    USART_voidRecieveInt(Print);
    while(1){}
}
void Print(){
	u8 speedfinal;
	u8 rotationfinal;
    u8 Characters[10];
    u8 speed[3];
    u8 speedDi;
    u8 rotation[2];
    u8 rotationDi;
    u8 speedword[5]={'s','p','e','e','d'};
    u8 Directionword[9]={'D','i','r','e','c','t','i','o','n'};
	u8 invalid=0;
	USART_voidRecieve(Characters);
    /*Input Validation*/
    if((Characters[7]!=69)||(Characters[8]!='\0')){
    	invalid=1;
  	  asm("NOP");
    }
    else{
		  /*Split Data*/
		  for(int i=0;i<3;i++){
			  speed[i]=Characters[i]-0x30;
			  /*Check if speed is valid*/
			  if(speed[i]>9){invalid=1;}}
		  speedDi=Characters[3];
		  if((speedDi!=70)&&(speedDi!=66)){invalid=1;}
		  for(int i=4;i<6;i++){
			  rotation[i-4]=Characters[i]-0x30;}
			  if(rotation[0]*10+rotation[1]>45){invalid=1;}
			  if(speed[0]*100+speed[1]*10+speed[2]>100){invalid=1;}
		  	  rotationDi=Characters[6];
		  	 if((rotationDi!=82)&&(rotationDi!=76)){invalid=1;}}
    if(invalid==0){
    	TIM1_voidDisable();
    	speedfinal=speed[0]*100+speed[1]*10+speed[2];
    	rotationfinal=rotation[0]*10+rotation[1];
    	u16 speedpwm=Motor_Speed(speedfinal);
    	Motor_Direction(speedDi,IOA,PIN7,PIN6);
        /*Duty Cycle*/
    	TIM1_voidCompare((speedpwm),0);
    	/*Enable Timer*/
    	TIM1_voidEnable();
    	//Motor_rotation(rotationDi,rotationfinal,IOA,PIN0,PIN1,PIN2,PIN3);
    	for(int i=0;i<5;i++){
    		USART_voidTransmit(speedword[i]);}
    	USART_voidTransmit(':');
    	for(int i=0;i<3;i++){
    		USART_voidTransmit(speed[i]+0x30);}
    	for(int i=0;i<9;i++){
    		USART_voidTransmit(Directionword[i]);}
    	if(rotationDi==76){USART_voidTransmit('-');}
    	else {USART_voidTransmit(' ');}
    	for(int i=0;i<2;i++){
    		USART_voidTransmit(rotation[i]+0x30);}
    		USART_voidTransmit('\n');
    		USART_voidTransmit('\r');
}
}
