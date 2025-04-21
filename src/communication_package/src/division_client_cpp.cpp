#include "ros/ros.h"
#include "communication_package/Division.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "division_client_cpp");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<communication_package::Division>("division_service_py");
    client.waitForExistence(); // 等待服务端启动

    communication_package::Division div_srv; // 创建服务对象，包含请求和响应
    ros::Rate loop_rate(1);                  // 设置循环频率

    for (int i = 3; i >= 0; i--)
    {
        div_srv.request.numerator = 10.0; // 设置请求参数
        div_srv.request.denominator = double(i);

        if (client.call(div_srv) && div_srv.response.success)
        {
            ROS_INFO("Result: %f", div_srv.response.result);
        }
        else
        {
            ROS_ERROR("Failed to call service");
        }
        loop_rate.sleep(); // 控制循环频率
    }
}