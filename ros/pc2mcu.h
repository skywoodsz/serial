#ifndef _PC2MCU_H
#define _PC2MCU_H

#include<iostream>
#include <string>
#include<boost/asio.hpp>
#include<boost/bind.hpp>

#include <ros/ros.h>
#include <ros/time.h>
#include <geometry_msgs/Twist.h>
namespace myserial
{
	class myserial
	{
	public:
		myserial();
		~myserial();
		bool init(); 
		void send_data(int liner_x,int angle_y); 
	private:
    	ros::Time current_time_, last_time_;
	};

}
#endif // !_PC2MCU_H
#pragma once
