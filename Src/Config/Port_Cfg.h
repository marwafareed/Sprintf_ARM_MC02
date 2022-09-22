/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.h
 *       Module:  Port
 *
 *  Description:  Port configuration definitions and macros    
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_CFG_NO_OF_PINS									(43)
#define PORT_DIO_NO_FUNCTION

#define PORT_PORTF_UNLOCK										(0x4C4F434B)
#define PORT_LED_PIN												(1)

#define PORT_BIT_SET(REGISTER, BIT)   			((REGISTER) |= (1u<<(BIT)))
#define PORT_BIT_CLEAR(REGISTER, BIT) 			(REGISTER&=(~(1u<<BIT)))


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


#endif  /* PORT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/
 
