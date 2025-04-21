#include "ros/ros.h"
#include "libtest/hello.h"

namespace Hello
{
    void hello()
    {
        ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug); // 设置日志级别
        ROS_DEBUG("Hello, World! Hello, C++!");
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "hello_cpp");
    Hello::hello();
    return 0;
}