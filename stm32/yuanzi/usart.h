#ifndef __usart_H
#define __usart_H

#include "sys.h"
#include "stdio.h" 


#define Max_BUFF_Len 11

void USART1_Init(u32 bound);
void Send_data(u8 *s);
void USART1_IRQHandler(void);

#endif

