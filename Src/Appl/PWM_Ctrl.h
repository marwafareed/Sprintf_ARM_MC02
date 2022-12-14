/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PWM_Ctrl.h
 *       Module:  PWM_Ctrl
 *
 *  Description:  header file for the controlling the PWM  
 *  
 *********************************************************************************************************************/
#ifndef PWM_CTRL_H
#define PWM_CTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 PWM_CtrlTimeType;
typedef uint8 PWM_CtrlPeriodType;

typedef enum
{
		PWM_ON_STATE = 0,
		PWM_OFF_STATE
	
}PWM_StateType;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

	
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
void PWM_CtrlInit(void);
void PWM_CtrlUpdate(void);
void PWM_SetPeriodSec(PWM_CtrlTimeType on_time_sec, PWM_CtrlTimeType off_time_sec);
#endif  /* PWM_CTRL_H */

/**********************************************************************************************************************
 *  END OF FILE: PWM_Ctrl.h
 *********************************************************************************************************************/


