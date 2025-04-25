#include "geometry_msgs/Twist.h"
#include "ros/ros.h"

#include <cmath>

#define TIME M_PI * 4

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "base_controller");
    ros::NodeHandle n;

    ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 100);
    geometry_msgs::Twist twist;
    twist.linear.x = 0.2;

    while (ros::ok()) {
        twist.angular.z = 0.5;
        publisher.publish(twist);
        ros::Duration(TIME).sleep();

        twist.angular.z = -0.5;
        publisher.publish(twist);
        ros::Duration(TIME).sleep();
    }
    return 0;
}