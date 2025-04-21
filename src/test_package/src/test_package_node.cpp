#include "ros/ros.h"

using namespace ros;

int main(int argc, char **argv)
{
    init(argc, argv, "test_node_cpp");
    NodeHandle n;
    ROS_INFO("Hello, World! Hello, C++!");
    return 0;
}