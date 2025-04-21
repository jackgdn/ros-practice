#include "ros/ros.h"
#include "communication_package/Division.h"

bool do_request(communication_package::Division::Request &req, communication_package::Division::Response &res)
{
    double numerator = req.numerator, denominator = req.denominator;
    ROS_INFO("Received numerator: %f, denominator: %f", numerator, denominator);

    if (denominator == 0.0) // 业务逻辑
    {
        ROS_ERROR("Denominator cannot be zero");
        res.success = false;
    }
    else
    {
        double result = numerator / denominator;
        res.success = true;
        res.result = result;
        ROS_INFO("Sending result: %f", result);
    }

    return true;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "division_server_cpp");
    ros::NodeHandle n;
    ros::ServiceServer server = n.advertiseService("division_service_cpp", do_request); // 创建服务器对象
    ROS_INFO("Starting division service from C++");
    ros::spin();
    return 0;
}