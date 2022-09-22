/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Usr.h
 *       Module:  Usr
 *
 *  Description:  User input header file
 *  
 *********************************************************************************************************************/
#ifndef USR_H
#define USR_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Usr_OnTimeSecType;
typedef uint8 Usr_OffTimeSecType;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define USR_MAX_ON_TIME								(255)
#define USR_MAX_OFF_TIME							(255)

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
void Usr_Set(Usr_OnTimeSecType on_time, Usr_OffTimeSecType off_time);
 
#endif  /* USR_H */

/**********************************************************************************************************************
 *  END OF FILE: Usr.h
 *********************************************************************************************************************/
