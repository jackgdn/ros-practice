#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include <cstdlib>

void callback(const turtlesim::Pose::ConstPtr &msg)
{
    printf("\033[H");
    printf("Turtle Position Information:    \nx=%.3f    \ny=%.3f    \ntheta=%.3f    \nlinear_velocity=%.3f    \nangular_velocity=%.3f    \n",
           msg->x,
           msg->y,
           msg->theta,
           msg->linear_velocity,
           msg->angular_velocity);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "topic_subscribe_cpp");
    ros::NodeHandle n;
    std::system("clear");
    ros::Subscriber subscriber = n.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, callback);
    ros::spin();
    return 0;
}