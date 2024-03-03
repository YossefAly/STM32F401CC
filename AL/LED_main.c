#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "LEDMTRX_Interface.h"

u8 GLOB_u8DataArr[8] = {12, 18, 34, 68, 34, 18, 12, 0};

void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	/*Step 3 : Enable GPIO Peripherial Clock For Port B*/
    RCC_voidEnablePeripheralClk(AHB1,1);

	/*Step 4 : Initialize For LED Matrix*/
    HLEDMAT_voidInit() ;

	/* Loop forever */
	while(1)
	{
      /*Send Data To Led Matrix*/
		HLEDMAT_voidDisplay(GLOB_u8DataArr) ;
	}

}

