#include "pc2mcu.h"
using namespace std;
using namespace boost::asio;
namespace myserial
{
	/*
		ͨ��Э�飺{0x55,0x5a,���ٶȣ�4λ��,���ٶ�(4λ)��0x0a}
	*/
	const unsigned char header[2] = {0x55,0x5A}; //��ͷ
	const unsigned char ender[1] = { 0x0A };	//��β
	// union ���㷢��
	union send_msg
	{
		int d;
		unsigned char data[2];
	}send_liner_x,send_angele_y;

	io_service iosev;
	serial_port sp(iosev,"COM1"); //��COM1��

	myserial::myserial()
	{
	}
	myserial::~myserial()
	{
	}
	bool myserial::init()
	{
		//��������
		sp.set_option(serial_port::baud_rate(9600)); //������
		sp.set_option(serial_port::flow_control(serial_port::flow_control::none));
		sp.set_option(serial_port::parity(serial_port::parity::none));//����żУ��λ
		sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));//һ��ֹͣλ
		sp.set_option(serial_port::character_size(8));//�ֳ�
		return true;
	}
	//���ʹ���
	void myserial::send_data(int liner_x, int angle_y)
	{
		unsigned char buf[11] = { 0 };
		send_liner_x.d = liner_x;
		send_angele_y.d = angle_y;
		//��ͷ
		for (int i = 0; i < 2; i++)
		{
			buf[i] = header[i];
		}
		//���ٶȣ����ٶ�
		//���ݴӸߵ���
		int j = 3;
		for (int i = 0;i<4;i++)
		{
			buf[i + 2] = send_liner_x.data[j];
			buf[i + 6] = send_angele_y.data[j];
			j--;
		}
		//��β
		buf[10] = ender[0];
		write(sp,buffer(buf));
	}
}