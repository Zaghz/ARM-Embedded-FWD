/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Driver.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SysTick_Timer_H
#define SysTick_Timer_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>
#include <stdio.h>
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32_t SysTick_Value_t;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SysTick_Init(uint32_t delay_in_seconds);

#endif  /* SysTick_Timer_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Driver.h
 *********************************************************************************************************************/
