#ifndef _PC2MCU_H
#define _PC2MCU_H

#include<iostream>
#include <string>
#include<boost/asio.hpp>
#include<boost/bind.hpp>

namespace myserial
{
	class myserial
	{
	public:
		myserial();
		~myserial();
		bool init(); // ��ʼ��
		void send_data(int liner_x,int angle_y); //�������ٶȣ����ٶ�
	};

}
#endif // !_PC2MCU_H
#pragma once
