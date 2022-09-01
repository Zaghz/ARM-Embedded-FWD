/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PortDriver.c
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
#include "../Inc/Dio.h"
#include "../Inc/Port_Driver.h"
#include "../Config/Port_Config.h"

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
* \Syntax          : void Port_Init(const Port_Config_t* ConfigPtr, size_t ConfigSize)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : None  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void Port_Init(const Port_Config_t* ConfigPtr, size_t ConfigSize)
{
    int port_num = 0;
    int pin_num = 0;
    for(int i = 0; i < ConfigSize; i++){
        uint32_t channel = 0;
        channel = ConfigPtr[i].PortPin;
        port_num = channel / NUM_OF_CHANNELS_PER_PORT;
	    pin_num = channel % NUM_OF_CHANNELS_PER_PORT;
        if(port_num == 0)
        {
            bitset(RCGCGPIO,0);
            if(ConfigPtr[i].PortPinDirection == GPIO_OUTPUT)
            {
                bitset(GPIOA -> DIR,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == TWO)
            {
                bitset(GPIOA -> DR2R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == FOUR)
            {
                bitset(GPIOA -> DR4R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == EIGHT)
            {
                bitset(GPIOA -> DR8R,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLUP)
            {
                bitset(GPIOA -> PUR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLDOWN)
            {
                bitset(GPIOA -> PDR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == OPEN_DRAIN)
            {
                bitset(GPIOA -> ODR,pin_num);
            }
            if(ConfigPtr[i].PortPinMode == DIO)
            {
                bitset(GPIOA -> DEN,pin_num);
            }
        }

        if(port_num == 1)
        {
            bitset(RCGCGPIO,1);
            if(ConfigPtr[i].PortPinDirection == GPIO_OUTPUT)
            {
                bitset(GPIOB -> DIR,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == TWO)
            {
                bitset(GPIOB -> DR2R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == FOUR)
            {
                bitset(GPIOB -> DR4R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == EIGHT)
            {
                bitset(GPIOB -> DR8R,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLUP)
            {
                bitset(GPIOB -> PUR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLDOWN)
            {
                bitset(GPIOB -> PDR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == OPEN_DRAIN)
            {
                bitset(GPIOB -> ODR,pin_num);
            }
            if(ConfigPtr[i].PortPinMode == DIO)
            {
                bitset(GPIOB -> DEN,pin_num);
            }
        }
        
        if(port_num == 2)
        {
            bitset(RCGCGPIO,2);
            if(ConfigPtr[i].PortPinDirection == GPIO_OUTPUT)
            {
                bitset(GPIOC -> DIR,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == TWO)
            {
                bitset(GPIOC -> DR2R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == FOUR)
            {
                bitset(GPIOC -> DR4R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == EIGHT)
            {
                bitset(GPIOC -> DR8R,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLUP)
            {
                bitset(GPIOC -> PUR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLDOWN)
            {
                bitset(GPIOC -> PDR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == OPEN_DRAIN)
            {
                bitset(GPIOC -> ODR,pin_num);
            }
            if(ConfigPtr[i].PortPinMode == DIO)
            {
                bitset(GPIOC -> DEN,pin_num);
            }
        }

        if(port_num == 3)
        {
            bitset(RCGCGPIO,3);
            if(ConfigPtr[i].PortPinDirection == GPIO_OUTPUT)
            {
                bitset(GPIOD -> DIR,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == TWO)
            {
                bitset(GPIOD -> DR2R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == FOUR)
            {
                bitset(GPIOD -> DR4R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == EIGHT)
            {
                bitset(GPIOD -> DR8R,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLUP)
            {
                bitset(GPIOD -> PUR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLDOWN)
            {
                bitset(GPIOD -> PDR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == OPEN_DRAIN)
            {
                bitset(GPIOD -> ODR,pin_num);
            }
            if(ConfigPtr[i].PortPinMode == DIO)
            {
                bitset(GPIOD -> DEN,pin_num);
            }
        }

        if(port_num == 4)
        {
            bitset(RCGCGPIO,4);
            if(ConfigPtr[i].PortPinDirection == GPIO_OUTPUT)
            {
                bitset(GPIOE -> DIR,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == TWO)
            {
                bitset(GPIOE -> DR2R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == FOUR)
            {
                bitset(GPIOE -> DR4R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == EIGHT)
            {
                bitset(GPIOE -> DR8R,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLUP)
            {
                bitset(GPIOE -> PUR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLDOWN)
            {
                bitset(GPIOE -> PDR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == OPEN_DRAIN)
            {
                bitset(GPIOE -> ODR,pin_num);
            }
            if(ConfigPtr[i].PortPinMode == DIO)
            {
                bitset(GPIOE -> DEN,pin_num);
            }
        }

        if(port_num == 5)
        {
            bitset(RCGCGPIO,5);
            if(ConfigPtr[i].PortPinDirection == GPIO_OUTPUT)
            {
                bitset(GPIOF -> DIR,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == TWO)
            {
                bitset(GPIOF -> DR2R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == FOUR)
            {
                bitset(GPIOF -> DR4R,pin_num);
            }
            if(ConfigPtr[i].Port_PinOutputCurrent == EIGHT)
            {
                bitset(GPIOF -> DR8R,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLUP)
            {
                bitset(GPIOF -> PUR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == INTERNAL_PULLDOWN)
            {
                bitset(GPIOF -> PDR,pin_num);
            }
            if(ConfigPtr[i].PortPinInternalAttach == OPEN_DRAIN)
            {
                bitset(GPIOF -> ODR,pin_num);
            }
            if(ConfigPtr[i].PortPinMode == DIO)
            {
                bitset(GPIOF -> DEN,pin_num);
            }
        }
    }
}
/**********************************************************************************************************************
 *  END OF FILE: PortDriver.c
 *********************************************************************************************************************/
