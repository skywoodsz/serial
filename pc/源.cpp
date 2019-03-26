#include<iostream>
#include<boost/asio.hpp>
#include<boost/bind.hpp>
using namespace std;
using namespace boost::asio;
int main()
{
	io_service iosev;
	serial_port sp(iosev, "COM4"); //串口
	//参数设置
	sp.set_option(serial_port::baud_rate(9600)); //波特率
	sp.set_option(serial_port::flow_control(serial_port::flow_control::none));
	sp.set_option(serial_port::parity(serial_port::parity::none));//无奇偶校验位
	sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));//一个停止位
	sp.set_option(serial_port::character_size(8));//字长
	//
	write(sp, buffer("hello",5));

	char buf[5];
	read(sp, buffer(buf));
	//buf[5] = '\0';
	cout << buf << endl;

	iosev.run();
	return 0;
}
