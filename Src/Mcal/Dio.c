/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       \file  Dio.c
 *        \brief  Driver for Gpio pins
 *
 *      	\details  Digital IO pins function used to access and set each port pin
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Common.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType Channel)        
* \Description     : Reads port pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Port pin (channel)                     
* \Parameters (out): None                                                    
* \Return value:   : pin/channel value (high/low)  
*                                                                  
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType port, Dio_ChannelType Channel)
{
	Dio_LevelType channelValue = DIO_LOW;
	return(channelValue);
}
/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_PortType port, Dio_ChannelType channel, Dio_LevelType Level)     
* \Description     : Write a value to a port pin                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Port, pin & level (high or low)                    
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void Dio_WriteChannel(Dio_PortType port, Dio_ChannelType channel, Dio_LevelType Level)
{
	switch(port)
	{
		case DIO_PORTA:
			/*DIO_PortADataReg += (1u<<channel);
			DIO_PortADataReg = Level;*/
			break;
		
		case DIO_PORTB:
			break;
		
		case DIO_PORTC:
			break;
		
		case DIO_PORTD:
			break;
		
		case DIO_PORTE:
			break;
		
		case DIO_PORTF:
			BIT_BAND_PERIPHERAL((GPIO_PORTF_BASE_ADDRESS_APB + 0x3fc),channel) = Level;
			break;
		
		default:
			/*you shouldn't be here*/
			break;
	}/*switch(port)*/
}
/******************************************************************************
* \Syntax          :	Dio_PortLevelType Dio_ReadPort(Dio_PortType Port)        
* \Description     :  Read port value                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType Port)
{
	Dio_PortLevelType ret;
	return(ret);
}
/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType port, Dio_PortLevelType Level)        
* \Description     : Write a value to a port                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void Dio_WritePort(Dio_PortType port, Dio_PortLevelType Level)
{
}
/******************************************************************************
* \Syntax          : Dio_LevelType DioFlipChannel(Dio_PortType port, Dio_ChannelType Channel)      
* \Description     : Toggles port pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
Dio_LevelType DioFlipChannel(Dio_PortType port, Dio_ChannelType Channel)
{
	
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
