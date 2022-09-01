#include <stdint.h>
#include "Dio.h"
#include "Port_Config.h"
#include "SysTick_Timer.h"

uint8_t led_flag = 0;
float on_time = 0.002f;
float off_time = 0.001f;
Port_Pin_t led_pin = PORTA_0;


void Toggle_LED(float ON_Time, float OFF_Time, Port_Pin_t LED_Pin)
{
	if(led_flag == 0)
	{
		SysTick_Init(ON_Time);
		Dio_WriteChannel(PORTA_0,GPIO_HIGH);
		led_flag = 1;
	}else if(led_flag == 1)
	{
		SysTick_Init(OFF_Time);
		Dio_WriteChannel(PORTA_0,GPIO_LOW);
		led_flag = 0;
	}
	
}

int main(){
	Port_Init(Ports,sizeof(Ports)/sizeof(Ports[0]));
	Toggle_LED(on_time,off_time,led_pin);
	while (1)
	{

	}
	
}


void SysTick_Handler(void)
{
	void(*ptr)() = &Toggle_LED;
	(*ptr)();
}
