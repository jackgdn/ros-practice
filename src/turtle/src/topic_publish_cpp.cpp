#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "topic_publish_cpp");
    ros::NodeHandle n;

    ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    geometry_msgs::Twist twist;
    twist.linear.x = 1.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 0.5;

    ros::Rate rate(10);
    while (ros::ok())
    {
        publisher.publish(twist);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}