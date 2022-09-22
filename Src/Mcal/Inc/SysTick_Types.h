/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick_Types.h
 *       Module:  SysTick
 *
 *  Description:  SysTick types     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_TYPES_H
#define SYSTICK_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
	
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 SysTick_CounterType;

typedef enum
{
	SYSYTICK_NONE = 0,
	SYSYTICK_ON_TIME_REACHED ,
	SYSYTICK_OFF_TIME_REACHED 
}SysTick_Status;

#endif  /* SYSTICK_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick_Types.h
 *********************************************************************************************************************/
