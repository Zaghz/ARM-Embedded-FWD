/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
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
#include "../Common/Mcu_Hw.h"
#include "../Inc/Dio.h"

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
* \Syntax          : Dio_Level_t Dio_ReadChannel(Dio_Channel_t channel)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : channel   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_Level_t  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Dio_Level_t Dio_ReadChannel(Dio_Channel_t channel)
{
    int port_num = 0;
    int pin_num = 0;
    port_num = channel / NUM_OF_CHANNELS_PER_PORT;
	pin_num = channel % NUM_OF_CHANNELS_PER_PORT;
	if(port_num == 0)
    {
        if((GPIOA -> DATA) & (1<<(pin_num)))
        {
            return GPIO_HIGH;
        }
        else
        {
            return GPIO_LOW;
        }
    }

    if(port_num == 1)
    {
        if((GPIOB -> DATA) & (1<<(pin_num)))
        {
            return GPIO_HIGH;
        }
        else
        {
            return GPIO_LOW;
        }
    }
    
    if(port_num == 2)
    {
        if((GPIOC -> DATA) & (1<<(pin_num)))
        {
            return GPIO_HIGH;
        }
        else
        {
            return GPIO_LOW;
        }
    }

    if(port_num == 3)
    {
        if((GPIOD -> DATA) & (1<<(pin_num)))
        {
            return GPIO_HIGH;
        }
        else
        {
            return GPIO_LOW;
        }
    }

    if(port_num == 4)
    {
        if((GPIOE -> DATA) & (1<<(pin_num)))
        {
            return GPIO_HIGH;
        }
        else
        {
            return GPIO_LOW;
        }
    }

    if(port_num == 5)
    {
        if((GPIOF -> DATA) & (1<<(pin_num)))
        {
            return GPIO_HIGH;
        }
        else
        {
            return GPIO_LOW;
        }
    }
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_Channel_t channel,Dio_Level_t level)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : channel   Parameter Describtion   
                     level                 
* \Parameters (out): None                                                      
* \Return value:   : None  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void Dio_WriteChannel(Dio_Channel_t channel,Dio_Level_t level)
{
    int port_num = 0;
    int pin_num = 0;
    port_num = channel / NUM_OF_CHANNELS_PER_PORT;
	pin_num = channel % NUM_OF_CHANNELS_PER_PORT;
	if(port_num == 0)
    {
        uint32_t address = &(GPIOA -> DATA);
        uint32_t* bitband = ((uint32_t*) (BITBAND_PERI(address,pin_num)));
        if(level == GPIO_HIGH)
        {
            *bitband = 0x01;
        }
        else
        {
            *bitband = 0x00;
        }
    }

    else if(port_num == 1)
    {
        uint32_t address = &(GPIOB -> DATA);
        uint32_t* bitband = ((uint32_t*) (BITBAND_PERI(address,pin_num)));
        if(level == GPIO_HIGH)
        {
            *bitband = 0x01;
        }
        else
        {
            *bitband = 0x00;
        }
    }
    
    else if(port_num == 2)
    {
        uint32_t address = &(GPIOC -> DATA);
        uint32_t* bitband = ((uint32_t*) (BITBAND_PERI(address,pin_num)));
        if(level == GPIO_HIGH)
        {
            *bitband = 0x01;
        }
        else
        {
            *bitband = 0x00;
        }
    }

    else if(port_num == 3)
    {
        uint32_t address = &(GPIOD -> DATA);
        uint32_t* bitband = ((uint32_t*) (BITBAND_PERI(address,pin_num)));
        if(level == GPIO_HIGH)
        {
            *bitband = 0x01;
        }
        else
        {
            *bitband = 0x00;
        }
    }

    else if(port_num == 4)
    {
        uint32_t address = &(GPIOE -> DATA);
        uint32_t* bitband = ((uint32_t*) (BITBAND_PERI(address,pin_num)));
        if(level == GPIO_HIGH)
        {
            *bitband = 0x01;
        }
        else
        {
            *bitband = 0x00;
        }
    }

    else if(port_num == 5)
    {
        uint32_t address = &(GPIOF -> DATA);
        uint32_t* bitband = ((uint32_t*) (BITBAND_PERI(address,pin_num)));
        if(level == GPIO_HIGH)
        {
            *bitband = 0x01;
        }
        else
        {
            *bitband = 0x00;
        }
    }
}

/******************************************************************************
* \Syntax          : Dio_PortLevel_t Dio_ReadPort(Dio_Port_t port)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : port   Parameter Describtion                  
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevel_t  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

Dio_PortLevel_t Dio_ReadPort(Dio_Port_t port)
{
    if(port == 0)
    {
        return (uint8_t)(GPIOA -> DATA);
    }
    if(port == 1)
    {
        return (uint8_t)(GPIOB -> DATA);
    }
    if(port == 2)
    {
        return (uint8_t)(GPIOC -> DATA);
    }
    if(port == 3)
    {
        return (uint8_t)(GPIOD -> DATA);
    }
    if(port == 4)
    {
        return (uint8_t)(GPIOE -> DATA);
    }
    if(port == 5)
    {
        return (uint8_t)(GPIOF -> DATA);
    }
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_Port_t port,Dio_PortLevel_t portlevel)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : port   Parameter Describtion     
                     portlevel   
* \Parameters (out): None                                                      
* \Return value:   : None  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void Dio_WritePort(Dio_Port_t port,Dio_PortLevel_t portlevel)
{
    if(port == 0)
    {
        GPIOA -> DATA = portlevel;
    }
    if(port == 1)
    {
        GPIOB -> DATA = portlevel;
    }
    if(port == 2)
    {
        GPIOC -> DATA = portlevel;
    }
    if(port == 3)
    {
        GPIOD -> DATA = portlevel;
    }
    if(port == 4)
    {
        GPIOE -> DATA = portlevel;
    }
    if(port == 5)
    {
        GPIOF -> DATA = portlevel;
    }
}

// Dio_Level_t Dio_FlipChannel(Dio_Channel_t channel)
// {
    
// }
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
