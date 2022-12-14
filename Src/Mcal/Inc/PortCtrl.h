/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef CLOCKCTRL_TYPES_H
#define CLOCKCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CLOCKCONTROL_PLL_ENABLE			
#define CLOCKCONTROL_PLL_DISABLE

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	CLOCKCONTROL_INTERNAL_OSC,
	CLOCKCONTROL_MAIN_OSC,
	CLOCKCONTROL_LOW_FREQUENCY_OSC,
	CLOCKCONTROL_HIBERNATE_OSC
}ClockCtrl_ClockType;

#endif  /* CLOCKCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: ClockCtrl_Types.h
 *********************************************************************************************************************/