#include "geometry_msgs/Twist.h"
#include "ros/ros.h"

#include <random>

double generate_random() {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_real_distribution<> dis(-1.3, 1.3);
    return dis(gen);
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "random_track");
    ros::NodeHandle n;

    ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    geometry_msgs::Twist twist;

    ros::Rate rate(1);
    while (ros::ok()) {
        twist.linear.x = generate_random();
        twist.angular.z = generate_random();
        publisher.publish(twist);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}