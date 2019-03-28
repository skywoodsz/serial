#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
int main(int argc,char** argv)
{
    ros::init(argc,argv,"cmd_vel_pub");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000) ;
    int count = 0;
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        geometry_msgs::Twist vel;
        vel.linear.x = 1000;
        vel.angular.z = 2000;
        //ROS_INFO("send cmd_vel_liner_x is %d",vel.linear.x);
        //ROS_INFO("send cmd_vel_angular_z is %d",vel.angular.z);
        ROS_INFO_STREAM(""<<" linear=" << vel.linear.x<< " angular=" << vel.angular.z);
        pub.publish(vel);
        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}