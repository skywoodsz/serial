#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"
#include "data.h"

#include "led.h"
#include "key.h"
#include "usart.h"
#include "tftlcd.h"
extern u8 Uart1_Buffer[Max_BUFF_Len];
extern u8 send_flag;
int char2int(char* str);
int main()
{
	int pc_data;
	u8 i = 0;
	u8 getchar[20]= "1"; 
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断分组
	USART1_Init(115200);//初始化串口
	TFTLCD_Init();			//LCD初始化
	FRONT_COLOR=BLACK;
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,24,getchar);
	while(1)
	{
		if(send_flag == 1)
		{
			send_flag = 0;
			//Send_data(Uart1_Buffer);
			//pc_data = char2int(Uart1_Buffer);
			//USART_SendData(USART1,pc_data);
			//LCD_ShowxNum(10,30, pc_data,1,24,0);
			for(i=0;i<Max_BUFF_Len;i++)
			{
				LCD_ShowxNum(10,30+20*i,Uart1_Buffer[i],3,24,0);
				//USART_SendData(USART1,Uart1_Buffer[0]);
			}
		}		
	}
} 
int char2int(char* str)
{
	u8 i;
	int num;
	for(i = 0,num = 0;str[i]!='\0';i++)
	{
		num = num*10 + (str[i] - '0');
	}
	//USART_SendData(USART1,num);
	return num;
}

