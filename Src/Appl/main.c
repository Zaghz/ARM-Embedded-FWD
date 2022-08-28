#include <stdint.h>
#include "Mcu_Hw.h"
#include "Dio.h"
#include "Port_Config.h"
//void delayms(int time);

//void delayms(int time){
//	int x,y;
//	for(x=0;x<time;x++)
//	{
// 		for(y=0;y<500;y++);
//	}
//}

int main(){
	RCC |= 0x02400540;
	Port_Init(Ports,sizeof(Ports)/sizeof(Ports[0]));
	// RCGCGPIO |= 0x02;
	// GPIOA->DIR |= 0x02;
	GPIOB->DEN |= 0x02;
	while (1)
	{
		// Dio_ReadChannel(PORTA_1);
		// Dio_WriteChannel(PORTA_1,GPIO_HIGH);
		// Dio_WriteChannel(PORTA_1,GPIO_LOW);
		Dio_WritePort(PORTA,0xFF);
		GPIOA->DATA = 0x01;
	}
	
}
