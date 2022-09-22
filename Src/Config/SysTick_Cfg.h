/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_CFG_H
#define SYSTICK_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SYSTICK_MAX_RELOAD									(0x00FFFFFF)
/*#define SYSTICK_PRECISION_INTERNAL_OSC*/
#define SYSTICK_INTERRUPT_ENABLE

#define RELOAD_FOR_1_SECOND									(15999999)	

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
void SysTick_RegisterCallBack(void (*call_back)(void));

/*********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
#endif  /* SYSTICK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick_Cfg.h
 *********************************************************************************************************************/

