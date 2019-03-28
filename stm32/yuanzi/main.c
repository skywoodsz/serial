#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
 
extern u8 Uart1_Buffer[Max_BUFF_Len];
extern u8 send_flag;

 int main(void)
 {		
	u16 times=0;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	USART1_Init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	KEY_Init();          //初始化与按键连接的硬件接口
 	while(1)
	{
		times++;
		if(times%100==0)
		{
			LED0 = !LED0;
			times = 0;
		}
		delay_ms(10);
		if(send_flag == 1)
		{
			send_flag = 0;
			//Send_data(Uart1_Buffer);
			//pc_data = char2int(Uart1_Buffer);
			//USART_SendData(USART1,pc_data);
			//LCD_ShowxNum(10,30, pc_data,1,24,0);
//			for(i=0;i<Max_BUFF_Len;i++)
//			{
//				LCD_ShowxNum(10,30+20*i,Uart1_Buffer[i],3,24,0);
//				//USART_SendData(USART1,Uart1_Buffer[0]);
//			}
//			led2 = Uart1_Buffer[2];
//			led3 = Uart1_Buffer[7];
				if(Uart1_Buffer[0]==0x55 && Uart1_Buffer[1]==0x5A && Uart1_Buffer[Max_BUFF_Len-1]==0x0A )
				{
					LED1 = 0;
				}
		}		
	}	 
 }

