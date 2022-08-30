#include <stdint.h>
#include "Dio.h"
#include "Port_Config.h"
#include "SysTick_Timer.h"


int main(){
	Port_Init(Ports,sizeof(Ports)/sizeof(Ports[0]));
	SysTick_Init(0.001);
	while (1)
	{

	}
	
}


void SysTick_Handler(void)
{
	Dio_WriteChannel(PORTA_0,GPIO_HIGH);
	SysTick_Init(0.002);
}

void Toggle_LED(float ON_Time, float OFF_Time, Port_Pin_t LED_Pin)
{
	
	SysTick_Init(ON_Time);
	
}