/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PWM_Ctrl.c
 *        \brief  PWM control module
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "PWM_Ctrl.h"
#include "LED.h"
#include "SysTick.h"
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static SysTick_CounterType onTimeSec = 0;
static SysTick_CounterType offTimeSec = 0;

static PWM_StateType PWM_state = PWM_OFF_STATE;

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
* \Syntax          : void PWM_CtrlInit(void)       
* \Description     : Initialize the PWM module and register the timer call back function                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                  
*******************************************************************************/
void PWM_CtrlInit(void)
{
	SysTick_SetCounterSec(offTimeSec);
	SysTick_RegisterCallBack(PWM_CtrlUpdate);
	
}
/******************************************************************************
* \Syntax          : void PWM_CtrlUpdate(void)       
* \Description     : Updates the state of the PWM; high or low                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                     
*******************************************************************************/
void PWM_CtrlUpdate(void)
{
	if(PWM_state == PWM_OFF_STATE)
	{
		Dio_WriteChannel(DIO_PORTF,1, DIO_HIGH);
		SysTick_SetCounterSec(onTimeSec);
		PWM_state = PWM_ON_STATE;
	}else{
		Dio_WriteChannel(DIO_PORTF,1, DIO_LOW);
		SysTick_SetCounterSec(offTimeSec);
		PWM_state = PWM_OFF_STATE;
	}		
}

/******************************************************************************
* \Syntax          : void PWM_SetPeriodSec(PWM_CtrlTimeType on_time_sec, PWM_CtrlTimeType off_time_sec)       
* \Description     : set the On and Off period of the PWM according to user input                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : on_time_sec    PWM on time in seconds
										 off_time_sec   PWM off time in seconds
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void PWM_SetPeriodSec(PWM_CtrlTimeType on_time_sec, PWM_CtrlTimeType off_time_sec)
{
	onTimeSec = on_time_sec;
	offTimeSec = off_time_sec;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/






