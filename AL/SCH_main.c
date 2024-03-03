#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "SCH_Interface.h"

int main()
{
    RCC_voidInitSysClk();

    RCC_voidEnablePeripheralClk(AHB1,0);

    STK_voidInit();

    SCH_voidCreateTask();
    while (1)
    {
        /* code */
    }
    
}
void App_BlinkLed(){
    static u8 Copy_u8LocalPinValue=0;
    if(Copy_u8LocalPinValue){
        GPIO_voidSetPinValue(IOA,PIN0,LOW);
    }
    else{
        GPIO_voidSetPinValue(IOA)
    }
}