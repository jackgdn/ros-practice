#include "geometry_msgs/Twist.h"
#include "ros/ros.h"

#include <random>

double generate_random() {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_real_distribution<> dis(-3.142, 3.142);
    return dis(gen);
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "random_track");
    ros::NodeHandle n;

    ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
    geometry_msgs::Twist twist;
    twist.linear.x = 3.3;

    ros::Rate rate(2);
    while (ros::ok()) {
        twist.angular.z = generate_random();
        publisher.publish(twist);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}