#include "serial_test/pc2mcu.h"
using namespace std;
using namespace boost::asio;
namespace myserial
{
	/*
		通信协议：{0x55,0x5a,线速度（4位）,角速度(4位)，0x0a}
	*/
	const unsigned char header[2] = {0x55,0x5A}; //报头
	const unsigned char ender[1] = { 0x0A };	//报尾
	// union 方便发送
	union send_msg
	{
		int d;
		unsigned char data[2];
	}send_liner_x,send_angele_y;
	
	io_service iosev;
	serial_port sp(iosev,"/dev/stm32"); //打开COM1口

	myserial::myserial()
	{
	}
	myserial::~myserial()
	{
	}
	bool myserial::init()
	{
		//参数设置
		sp.set_option(serial_port::baud_rate(115200)); //波特率
		sp.set_option(serial_port::flow_control(serial_port::flow_control::none));
		sp.set_option(serial_port::parity(serial_port::parity::none));//无奇偶校验位
		sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));//一个停止位
		sp.set_option(serial_port::character_size(8));//字长

		ros::Time::init();
		current_time_ = ros::Time::now();
		last_time_ = ros::Time::now();

		return true;
	}
	//发送串口
	void myserial::send_data(int liner_x, int angle_y)
	{
		unsigned char buf[11] = { 0 };
		send_liner_x.d = liner_x;
		send_angele_y.d = angle_y;
		//报头
		for (int i = 0; i < 2; i++)
		{
			buf[i] = header[i];
		}
		//线速度，角速度
		//数据从高到低
		int j = 3;
		for (int i = 0;i<4;i++)
		{
			buf[i + 2] = send_liner_x.data[j];
			buf[i + 6] = send_angele_y.data[j];
			j--;
		}
		//报尾
		buf[10] = ender[0];
		write(sp,buffer(buf));
	}
}
