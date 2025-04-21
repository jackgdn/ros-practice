#include "ros/ros.h"
#include <iostream>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_cpp");

    ros::NodeHandle n("turtlesim_node");  // 指定命名空间
    n.setParam("background_r", 113);
    n.setParam("background_g", 113);
    n.setParam("background_b", 113);

    return 0;
}