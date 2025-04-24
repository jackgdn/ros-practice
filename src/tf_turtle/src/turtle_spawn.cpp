#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "spawn_turtle");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn"); // 创建客户端
    ros::service::waitForService("/spawn");                                   // 等待服务启动

    turtlesim::Spawn spawn;
    spawn.request.name = "turtle2";
    spawn.request.x = 1.0;
    spawn.request.y = 1.0;
    spawn.request.theta = 1.571;

    if (client.call(spawn)) {
        ROS_INFO("Turtle spawned successfully!");
    } else {
        ROS_ERROR("Failed to spawn turtle.");
    }

    return 0;
}