/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       \file  Port.c
 *        \brief  Initialize the Port driver
 *
 *      	\details  Configures the port 
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const PORT_ConfigPinType* Port_ConfigPinPtr = NULL_PTR;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init(const PORT_ConfigType* ConfigPtr )  
* \Description     : Initializes the port pins                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void Port_Init(const PORT_ConfigPinType* ConfigPtr )
{
	uint8 pin_index = 1;
	volatile unsigned long delay;
	Port_ConfigPinPtr = ConfigPtr;
	switch(Port_ConfigPinPtr->Pin[1].port_name)
	{
		case PORT_A:
			break;
		case PORT_B:
			break;
		case PORT_C:
			break;
		case PORT_D:
			break;
		case PORT_E:
			break;
		case PORT_F:
		/*Enable the clock*/
			PORT_BIT_SET(RCGC2,5);
			delay = RCGC2;
		
			/*Unlock the port*/
			GPIOLOCK_PORTF = PORT_PORTF_UNLOCK;
			break;
	}//switch(Port_ConfigPinPtr->Pin[1].port_name)
	
	/*Set the configuration*/
		for(pin_index = 0 ; pin_index < PORT_CFG_NO_OF_PINS; pin_index++)
		{
				if(Port_ConfigPinPtr->Pin[pin_index].direction == PORT_DIRECTION_IN)
				{
					PORT_BIT_CLEAR(GPIODIR_PORTF, pin_index);
				}else{
					PORT_BIT_SET(GPIODIR_PORTF, pin_index);
				}
		
				/*No Alternative function selected set by default to DIO*/
				
				/*Drive select*/
				if(Port_ConfigPinPtr->Pin[pin_index].strength == PORT_2_MA)
				{
					PORT_BIT_SET(GPIODR2R_PORTF,pin_index);
				}else if(Port_ConfigPinPtr->Pin[pin_index].strength == PORT_4_MA){
					PORT_BIT_SET(GPIODR4R_PORTF,pin_index);
				}else{
					PORT_BIT_SET(GPIODR8R_PORTF,pin_index);
				}
				
				/*Port internal attach type*/
				if(Port_ConfigPinPtr->Pin[pin_index].pullAttach == PORT_OPEN_DRAIN)
				{
					PORT_BIT_SET(GPIOODR_PORTF,pin_index);
				}else if(Port_ConfigPinPtr->Pin[pin_index].pullAttach == PORT_PULL_UP){
					PORT_BIT_SET(GPIOPUR_PORTF,pin_index);
				}else if(Port_ConfigPinPtr->Pin[pin_index].pullAttach == PORT_PULL_DOWN){
					PORT_BIT_SET(GPIOPDR_PORTF,pin_index);
				}else if(Port_ConfigPinPtr->Pin[pin_index].pullAttach == PORT_SLEW_RATE){
					PORT_BIT_SET(GPIOSLR_PORTF,pin_index);
				}else{
					/*Do nothing*/
				}
		}/*for(pin_index = 0; pin_index < 8; pin_index++)*/
		
		/*Enable the port pin*/
		PORT_BIT_SET(GPIODEN_PORTF, PORT_LED_PIN);
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
