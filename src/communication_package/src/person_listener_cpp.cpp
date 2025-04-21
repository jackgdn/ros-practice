#include "ros/ros.h"
#include "communication_package/Person.h"

void callback(const communication_package::Person::ConstPtr &msg_ptr)
{
    ROS_INFO("Name: %s, Age: %d, Gender: %s from C++", msg_ptr->name.c_str(), msg_ptr->age, msg_ptr->gender ? "Male" : "Female");
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "person_listener_cpp");
    ros::NodeHandle n;
    ros::Subscriber person_sub = n.subscribe("person_chatter_cpp", 10, callback);
    ros::spin();
    return 0;
}