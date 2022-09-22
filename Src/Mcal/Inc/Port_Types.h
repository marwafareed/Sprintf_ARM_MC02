/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  Port
 *
 *  Description:  Port defined types    
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
typedef enum{
	PORT_A = 0,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F
}PORT_NameType;

typedef enum{
	PORT_PIN_0 = 0,
	PORT_PIN_1,
	PORT_PIN_2,
	PORT_PIN_3,
	PORT_PIN_4,
	PORT_PIN_5,
	PORT_PIN_6,
	PORT_PIN_7
}PORT_PinNumberType;

typedef enum
{
	PORT_DIO = 0,
	PORT_UART,
	PORT_SSI
}PORT_PinModeType;

typedef enum
{
	PORT_LEVEL_LOW = 0,
	PORT_LEVEL_HIGH 
}PORT_PinLevelType;

typedef enum
{
	PORT_DIRECTION_IN = 0,
	PORT_DIRECTION_OUT 
}PORT_PinDirectionType;

typedef enum
{
	PORT_ATTACH_NONE = 0,
	PORT_PULL_UP,
	PORT_PULL_DOWN,
	PORT_OPEN_DRAIN,
	PORT_SLEW_RATE
}PORT_PinInternalAttachType;

typedef enum
{
	PORT_2_MA = 0,
	PORT_4_MA,
	PORT_8_MA
}PORT_PinStrengthType;

typedef struct 
{
	PORT_NameType port_name;
	PORT_PinNumberType pin_no;
	PORT_PinModeType mode;
	PORT_PinLevelType level;
	PORT_PinDirectionType direction;
	PORT_PinInternalAttachType pullAttach;
	PORT_PinStrengthType strength;
}PORT_ConfigType;

typedef struct {
	PORT_ConfigType Pin[PORT_CFG_NO_OF_PINS];
}PORT_ConfigPinType;


#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
