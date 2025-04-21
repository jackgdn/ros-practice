#include "ros/ros.h"
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "paramget_cpp");
    ros::NodeHandle n;

    ros::Duration(1.0).sleep();
    string name, gender;
    int age;
    // 读取参数
    n.getParam("name", name);
    n.getParam("age", age);
    n.getParam("gender", gender);
    ROS_INFO("Name: %s, Age: %d, Gender: %s", name.c_str(), age, gender.c_str());

    ros::Duration(3.0).sleep();
    if (n.getParam("name", name) && n.getParam("age", age) && n.getParam("gender", gender))
    {
        ROS_INFO("Name: %s, Age: %d, Gender: %s", name.c_str(), age, gender.c_str());
    }
    else
    {
        ROS_ERROR("Failed to get parameters");
    }
    return 0;
}