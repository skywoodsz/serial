#include "serial_test/pc2mcu.h"
using namespace std;
int liner_x = 0,angle_z = 0;
void cmdCallback(const geometry_msgs::Twist& msg)
{
	liner_x = msg.linear.x;
	angle_z = msg.angular.z;
}
int main(int argc, char** argv)
{
	ros::init(argc, argv, "serila_test");									
    ros::NodeHandle n;

	myserial::myserial serial;
	if (!serial.init())
	{
		ROS_ERROR("MSerial initialized failed.");
	}
	ROS_INFO("MSerial initialized successful.");

	ros::Subscriber sub = n.subscribe("cmd_vel", 50, cmdCallback);

	//serial.send_data(1000, 2000);
	ros::Rate loop_rate(50);
	while(ros::ok())
	{
		ros::spinOnce();
		if(liner_x == 1000 && angle_z == 2000)
			serial.send_data(liner_x, angle_z);
		loop_rate.sleep();
	}
	return 0;
}