#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

using namespace std;


int main(int argc, char **argv)
{ 
   ros::init(argc , argv , "turtlesim_infinity");
   ros::NodeHandle n;
   

   ros::Publisher infinity_turtle = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel" , 1000);

   ros::Rate loop_rate(1);

   geometry_msgs::Twist vel_msg;
    
   vel_msg.linear.x=10;
   vel_msg.linear.y=0;
   vel_msg.linear.z=0;

  vel_msg.angular.x=0;
  vel_msg.angular.y=0;
  vel_msg.angular.z= 3.28;

   loop_rate.sleep();
   infinity_turtle.publish(vel_msg);

   vel_msg.angular.z=-3.28;
   loop_rate.sleep();
   infinity_turtle.publish(vel_msg);

   ros::spin();

    return 0;
}
