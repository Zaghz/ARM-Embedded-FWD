/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Interrupts.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "stdint.h"
#include "stdio.h"
#include "../Common/Mcu_Hw.h"
#include "../Config/Interrupt_Config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : void IntCntrl_Init(uint8_t no_of_groups, uint8_t no_of_subgroups)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : no_of_groups   Parameter Describtion   
                     no_of_subgroups                     
* \Parameters (out): None                                                      
* \Return value:   : None  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void IntCntrl_Init(uint8_t no_of_groups, uint8_t no_of_subgroups)
{
    if(no_of_groups > 4)
    {
        bitclear(SCB -> AIRCR,8);
        bitclear(SCB -> AIRCR,9);
        bitclear(SCB -> AIRCR,10);
    }
    else if(no_of_groups > 2)
    {
        bitset(SCB -> AIRCR,8);
        bitclear(SCB -> AIRCR,9);
        bitset(SCB -> AIRCR,10);
    }
    else if(no_of_groups > 1)
    {
        bitset(SCB -> AIRCR,8);
        bitset(SCB -> AIRCR,9);
        bitclear(SCB -> AIRCR,10);
    }
    else if(no_of_groups > 0)
    {
        bitset(SCB -> AIRCR,8);
        bitset(SCB -> AIRCR,9);
        bitset(SCB -> AIRCR,10);
    }
    for(int i = 0; i < NUM_INTERRUPTS; i++)
    {
        uint32_t interrupt_number = InterruptConfig[i].interrupt_peripheral_gate / 32;
        uint32_t interrupt_pin = InterruptConfig[i].interrupt_peripheral_gate % 32;
        bitset(NVIC -> ISER[interrupt_number], interrupt_pin);
        uint32_t priority = InterruptConfig[i].interrupt_group_priority - 1;
        uint32_t subpriority = InterruptConfig[i].interrupt_group_subpriority - 1;
        if(no_of_groups > 4)
        {
            NVIC -> IP[((uint32_t)InterruptConfig[i].interrupt_peripheral_gate)] = (uint8_t) ((priority << 5) & 0xFF) ;
        }
        else if(no_of_groups > 2)
        {
            NVIC -> IP[((uint32_t)InterruptConfig[i].interrupt_peripheral_gate)] = (uint8_t)((((priority << 1) + subpriority) << 5) & 0xFF);
        }
        else if(no_of_groups > 1)
        {
            NVIC -> IP[((uint32_t)InterruptConfig[i].interrupt_peripheral_gate)] = (uint8_t)((((priority << 2) + subpriority) << 5) & 0xFF);
        }
        else if(no_of_groups > 0)
        {
            NVIC -> IP[((uint32_t)InterruptConfig[i].interrupt_peripheral_gate)] = (uint8_t) ((subpriority << 5) & 0xFF);
        }
    }
}


/**********************************************************************************************************************
 *  END OF FILE: Interrupts.c
 *********************************************************************************************************************/
