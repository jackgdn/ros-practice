#include "ros/ros.h"
#include "turtlesim/Spawn.h"
#include "turtlesim/Kill.h"
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "service_cpp");
    ros::NodeHandle n;
    ros::ServiceClient client_spawn = n.serviceClient<turtlesim::Spawn>("/spawn");
    ros::ServiceClient client_kill = n.serviceClient<turtlesim::Kill>("/kill");
    client_spawn.waitForExistence();
    client_kill.waitForExistence();

    std::vector<std::string> turtle_names;
    float x, y, theta;
    std::string name;
    while (std::cin >> x >> y >> theta >> name) {
        turtlesim::Spawn spawn;
        spawn.request.x = x;
        spawn.request.y = y;
        spawn.request.theta = theta;
        spawn.request.name = name;
        
        if (client_spawn.call(spawn)) {
            ROS_INFO("Turtle Spawned");
            turtle_names.push_back(name);
        }
        else
        {
            ROS_ERROR("Failed to Spawn Turtle");
        }
    }

    for (auto name : turtle_names) {
        turtlesim::Kill kill;
        kill.request.name = name;
        if (client_kill.call(kill)) {
            ROS_INFO("Turtle Removed!");
        }
        else
        {
            ROS_ERROR("Failed to Remove Turtle");
        }
    }

    return 0;
}