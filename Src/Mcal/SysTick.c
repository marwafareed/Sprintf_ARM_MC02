/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       \file  SysTick.c
 *        \brief  SysTick module
 *
 *      	\details  initiaze the systick timer and includes all API functions 
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysTick.h"
#include "system_TM4C123.h"
#include "SysTick_Types.h"
#include "SysTick_Cfg.h"
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static void (*SysTickCallBack)(void);
static uint8 SysTick_reload;
 
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void SysTick_RegisterCallBack(void (*call_back)(void))
{
	SysTickCallBack = call_back;
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void SysTick_Handler (void);

/******************************************************************************
* \Syntax          : void SysTick_Init(void)       
* \Description     : SysTick Timer                                   
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void SysTick_Init(void)
{

	/*Program the value in the STRELOAD register*/
	SYSTICK_STRELOAD = RELOAD_FOR_1_SECOND ;
	
	/*Clear the STCURRENT register by writing to it with any value.*/
	SYSTICK_STCURRENT = 3;
	
	/*Select the clock source*/
	#ifdef SYSTICK_PRECISION_INTERNAL_OSC
	SYSTICK_STCTRL.B.CLK_SRC = 0;
	#else
		SYSTICK_STCTRL.B.CLK_SRC = 1;
	#endif /*Clock source*/
	
	/*Enable the interrupt*/
	#ifdef SYSTICK_INTERRUPT_ENABLE
		SYSTICK_STCTRL.B.INTEN = 1;
	#else
		SYSTICK_STCTRL.B.INTEN = 0;
	#endif
}

/******************************************************************************
* \Syntax          : void SysTick_Enable(void)       
* \Description     : SysTick Timer enable                                 
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void SysTick_Enable(void)
{
	SYSTICK_STCTRL.B.SYSTICK_ENABLE = 1;
}
/******************************************************************************
* \Syntax          : void SysTick_Disable(void)           
* \Description     : SysTick Timer Disable                                 
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void SysTick_Disable(void)
{
	SYSTICK_STCTRL.B.SYSTICK_ENABLE = 0;
}
/******************************************************************************
* \Syntax          : SysTick_Status SysTick_GetStatus(void)       
* \Description     : Return the status returned after overflow define by the                                
*                    SysTick_Status type                                                         
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
SysTick_Status SysTick_GetStatus(void)
{
	SysTick_Status status;
	status = SYSYTICK_ON_TIME_REACHED;
	return (status);
}
/******************************************************************************
* \Syntax          : void SysTick_Handler (void)       
* \Description     : SysTick Timernterrupt handler                                  
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void SysTick_Handler (void)
{
	static uint8 ticks_count = 0;

	ticks_count++;
	if(ticks_count == SysTick_reload)
	{
		ticks_count = 0;
		SysTickCallBack();
	}
	SYSTICK_STCURRENT = 1;
}

/******************************************************************************
* \Syntax          : void SysTick_SetCounterSec(SysTick_CounterType counter)   
* \Description     : Set the number of seconds at which the application call back function will ne invoked                                  
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void SysTick_SetCounterSec(SysTick_CounterType counter)
{
	SysTick_reload = counter;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
