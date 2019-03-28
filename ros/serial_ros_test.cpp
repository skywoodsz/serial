#include <boost/asio.hpp>                  
#include <boost/bind.hpp>
//asio头文件
 
#include <ros/ros.h>
#include<stdio.h>
#include <std_msgs/String.h>  
//ros头文件 
using namespace std;
using namespace boost::asio;  
using namespace ros;  
    
io_service iosev;
serial_port sp(iosev,"/dev/stm32");
int main(int argc, char** argv) {
    ros::init(argc, argv, "boost");       //
    ros::NodeHandle n;                      //
    
    sp.set_option(serial_port::baud_rate(115200));
    sp.set_option(serial_port::flow_control(serial_port::flow_control::none));
    sp.set_option(serial_port::parity(serial_port::parity::none));
    sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));
    sp.set_option(serial_port::character_size(8));//按照图1进行通信设置
    
    //ros::spin();
    unsigned char date[11]={0};
//通信命令，按照自己的实际情况修改，底层一般是16进制按位校验，位的声明可为unsigned char
    
     write(sp, buffer(date));//命令写入
     //read(sp, buffer(buf,100));//接收底层反馈信息，buf若显示未定的可自行定义
     iosev.run();
    return 0;
}
