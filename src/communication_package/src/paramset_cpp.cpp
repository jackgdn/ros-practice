#include "ros/ros.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "paramset_cpp");
    ros::NodeHandle n;

    // 写入参数
    n.setParam("name", "John Doe");
    n.setParam("age", 13);
    n.setParam("gender", "Male");

    ros::Duration(3.0).sleep();

    // 删除参数
    n.deleteParam("name");
    n.deleteParam("age");
    n.deleteParam("gender");

    return 0;
}