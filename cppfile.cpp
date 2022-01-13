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

   geometry_msgs::Twist msg;
    
   msg.linear.x=10;
   msg.linear.y=0;
   msg.linear.z=0;

  msg.angular.x=0;
  msg.angular.y=0;
  msg.angular.z= 3.28;

   loop_rate.sleep();
   infinity_turtle.publish(msg);

   msg.angular.z=-3.28;
   loop_rate.sleep();
   infinity_turtle.publish(msg);

   ros::spin();

    return 0;
}
