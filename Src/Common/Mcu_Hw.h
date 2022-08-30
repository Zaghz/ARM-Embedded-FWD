/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef Mcu_Hw_H
#define Mcu_Hw_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct {                                  
  uint32_t  RESERVED[255];
  uint32_t  DATA;                            
  uint32_t  DIR;                          
  uint32_t  IS;                              
  uint32_t  IBE;                
  uint32_t  IEV;                        
  uint32_t  IM;                   
  uint32_t  RIS;                           
  uint32_t  MIS;                      
  uint32_t  ICR;                       
  uint32_t  AFSEL;                           
  uint32_t  RESERVED1[55];
  uint32_t  DR2R;                           
  uint32_t  DR4R;                          
  uint32_t  DR8R;                           
  uint32_t  ODR;                      
  uint32_t  PUR;                         
  uint32_t  PDR;                         
  uint32_t  SLR;                            
  uint32_t  DEN;                              
  uint32_t  LOCK;                     
  uint32_t  CR;                       
  uint32_t  AMSEL;                         
  uint32_t  PCTL;                           
  uint32_t  ADCCTL;       
  uint32_t  DMACTL; 
} GPIO_Type;

typedef struct
{
    uint32_t CTRL;
    uint32_t LOAD;
    uint32_t VAL;
    uint32_t CALIB;
} SysTick_Type;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define BITBAND_PERI_REF 0x40000000
#define BITBAND_PERI_BASE 0x42000000
#define SCS_BASE 0xE000E000
#define CORTEXM4_PERIPHERAL_BASE_ADDRESS 0x400FE000
#define RCC *((volatile uint32_t*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0x060))
#define RCGCGPIO *((volatile uint32_t*)(CORTEXM4_PERIPHERAL_BASE_ADDRESS+0x608))
#define GPIOA_APB_BASE 0x40004000
#define GPIOB_APB_BASE 0x40005000
#define GPIOC_APB_BASE 0x40006000
#define GPIOD_APB_BASE 0x40007000
#define GPIOE_APB_BASE 0x40024000
#define GPIOF_APB_BASE 0x40025000
#define GPIOA ((GPIO_Type*) GPIOA_APB_BASE)
#define GPIOB ((GPIO_Type*) GPIOB_APB_BASE)
#define GPIOC ((GPIO_Type*) GPIOC_APB_BASE)
#define GPIOD ((GPIO_Type*) GPIOD_APB_BASE)
#define GPIOE ((GPIO_Type*) GPIOE_APB_BASE)
#define GPIOF ((GPIO_Type*) GPIOF_APB_BASE)
#define SysTick_BASE (SCS_BASE +  0x0010)
#define SysTick ((SysTick_Type*) SysTick_BASE)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))
#define BITBAND_PERI(a,b)  ((BITBAND_PERI_BASE + (a - BITBAND_PERI_REF) * 32 + (b * 4)))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* Mcu_Hw_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
