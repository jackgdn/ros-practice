#include "ros/ros.h"
#include "std_msgs/String.h"

void callback(const std_msgs::String::ConstPtr &msg_ptr) // 用 ConstPtr 指针接收消息，msg_ptr 是指向消息的指针
{
    ROS_INFO("C++ Listener: %s", msg_ptr->data.c_str()); // 打印消息内容；msg_ptr->data.c_str() 等价于 (*msg_ptr).data.c_str()
}

int main(int args, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(args, argv, "topic_listener_cpp");
    ros::NodeHandle n;
    ros::Subscriber chatter_sub = n.subscribe("topic_chatter_cpp", 10, callback); // 订阅话题，话题名为 "topic_chatter_py"，消息队列长度为 10

    ros::spin(); // 阻塞，等待回调函数 callback 执行完毕
    return 0;
}