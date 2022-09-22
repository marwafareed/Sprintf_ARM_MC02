/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

/*Application Interrupt and Reset Control (APINT)*/
typedef struct
{
	uint32 VECTRESET	:1;
	uint32 VECTCLRACT	:1;
	uint32 SYSRESREQ	:1;
	uint32 						:5;
	uint32 PRIGROUP		:3;
	uint32 						:4;
	uint32	ENDIANESS	:1;
	uint32 VECTKEY		:16;
}APINT_BF;

typedef union
{
	uint32	R;
	APINT_BF B;
}APINT_Tag;

typedef struct
{
	uint32 MOSCDIS		:1;
	uint32 						:3;
	uint32 OSCSRC			:2;
	uint32 XTAL				:5;
	uint32 BYPASS			:1;
	uint32 						:1;
	uint32 PWRDN			:1;
	uint32 						:3;
	uint32 PWMDIV			:3;
	uint32 USEPWMDIV 	:1;
	uint32 						:1;
	uint32 USESYSDIV 	:1;
	uint32 SYSDIV 		:4;
	uint32 ACG 				:1;
	uint32 						:4;
}RCC_BF;

typedef union
{
	uint32	R;
	RCC_BF B;
}RCC_Tag;


typedef struct
{
	uint32 R0					:1;
	uint32 R1					:1;
	uint32 R2					:1;
	uint32 R3					:1;
	uint32 R4					:1;
	uint32 R5					:1;
	uint32 						:26;
}RCGCGPIO_BF;

typedef union
{
	uint32	R;
	RCGCGPIO_BF B;
}RCGCGPIO_Tag;

typedef struct
{
	uint32 SYSTICK_ENABLE	:1;
	uint32 INTEN					:1;
	uint32 CLK_SRC				:1;
	uint32 								:13;
	uint32 COUNT					:1;
	uint32 								:15;
}STCTRL_BF;
typedef union
{
	uint32	R;
	STCTRL_BF B;
}STCTRL_Tag;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             	(0xE000E000)

#define BIT_BAND_SRAM_BASE											(0x20000000)
#define BIT_BAND_ALIAS_SRAM_BASE								(0x22000000)
#define BIT_BAND_PERIPHERAL_BASE								(0x40000000)
#define BIT_BAND_ALIAS_PERIPHERAL_BASE					(0x42000000)

#define APINT                                  	(*((volatile APINT_Tag*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD0C)))
#define INTCTRL                                	(*((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD04)))
#define PRI0																		(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x400)))	/*interrupts 0 : 3*/
#define EN0																			(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x100)))	/*interrupts 0 : 3*/
#define RCC																			(*((volatile RCC_Tag*)(CORTEXM4_PERI_BASE_ADDRESS + 0x060)))
#define RCGCGPIO																(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x608)))
#define RCGC2																		(*((volatile uint32*)(0x400FE108)))
	
/*SysTick*/
#define SYSTICK_STCTRL 													(*((volatile STCTRL_Tag*) (CORTEXM4_PERI_BASE_ADDRESS+0x010)))														
#define SYSTICK_STRELOAD												(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x014)))
#define SYSTICK_STCURRENT												(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x018)))

/****** GPIO ******/
#define GPIO_PORTA_BASE_ADDRESS_APB							(0x40004000)
#define GPIO_PORTA_BASE_ADDRESS_AHB							(0x40058000)

#define GPIO_PORTB_BASE_ADDRESS_APB							(0x40005000)
#define GPIO_PORTB_BASE_ADDRESS_AHB							(0x40059000)

#define GPIO_PORTC_BASE_ADDRESS_APB							(0x40006000)
#define GPIO_PORTC_BASE_ADDRESS_AHB							(0x4005A000)

#define GPIO_PORTD_BASE_ADDRESS_APB							(0x40007000)
#define GPIO_PORTD_BASE_ADDRESS_AHB							(0x4005B000)

#define GPIO_PORTE_BASE_ADDRESS_APB							(0x40024000)
#define GPIO_PORTE_BASE_ADDRESS_AHB							 0x4005C000)

#define GPIO_PORTF_BASE_ADDRESS_APB							(0x40025000)
#define GPIO_PORTF_BASE_ADDRESS_AHB							(0x4005D000)

/*Port F*/
#define GPIODATA_PORTF												  *(( volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x3fc))	/* 0x3fc Address masking  bits 2 : 9*/
#define GPIODIR_PORTF														*(( volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x400))
#define GPIOAFSEL_PORTF													*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x420))
#define	GPIODR2R_PORTF													*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x500))
#define	GPIODR4R_PORTF													*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x504))
#define	GPIODR8R_PORTF													*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x508))
#define	GPIOODR_PORTF														*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x50C))
#define GPIOPUR_PORTF														*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x510))
#define GPIOPDR_PORTF														*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x514))	
#define	GPIOSLR_PORTF														*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x518))	
#define GPIODEN_PORTF														*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x51C))
#define GPIOCR_PORTF														*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x524))
#define	GPIOLOCK_PORTF													*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB + 0x520))
		
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
