#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int args, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(args, argv, "topic_talker_cpp");                                           // 初始化节点，节点名称为 topic_talker_cpp，这也是节点的唯一标识符
    ros::NodeHandle n;                                                                   // 创建节点句柄
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_chatter_cpp", 10); // 创建发布者，话题名称为 topic_chatter_cpp，最多保存 10 条消息

    std_msgs::String msg; // 创建消息对象
    std::string msg_front = "Hello from C++ talker!";

    int count = 0;
    ros::Rate loop_rate(1); // 设置循环频率为 1Hz

    while (ros::ok())
    {
        std::stringstream ss;
        ss << msg_front << " " << count;
        msg.data = ss.str();

        chatter_pub.publish(msg);                     // 发布消息
        ROS_INFO("C++ Talker: %s", msg.data.c_str()); // 打印发布的消息内容
        loop_rate.sleep();                            // 控制循环频率
        count++;
        ros::spinOnce(); // 刷新 ROS 事件队列
    }

    return 0;
}