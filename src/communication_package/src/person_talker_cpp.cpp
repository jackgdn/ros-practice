#include "ros/ros.h"
#include "communication_package/Person.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "person_talker_cpp");
    ros::NodeHandle n;
    ros::Publisher person_pub = n.advertise<communication_package::Person>("person_chatter_cpp", 10);

    communication_package::Person person;
    person.name = "John Doe";
    person.age = 13;
    person.gender = true;

    ros::Rate loop_rate(1);
    ros::Duration(3.0).sleep();  // 等待订阅者连接，否则订阅者有可能无法收到发出的第一条消息
    while (ros::ok())
    {
        person_pub.publish(person);
        person.age++;
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}