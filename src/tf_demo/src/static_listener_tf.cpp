#include "ros/ros.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h" // 调用 transform 必须包含该头文件
#include "tf2_ros/transform_listener.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "static_listener_tf");
    ros::NodeHandle nh;
    ros::console::set_logger_level(
        ROSCONSOLE_DEFAULT_NAME,
        ros::console::levels::Debug); // 设置日志输出级别为 Debug

    // 创建 TF 订阅对象并监听
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate rate(1);
    while (ros::ok()) // 只要 ROS Master 存活
    {
        // 创建子级坐标系中的座标点
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id = "laser";
        point_laser.header.stamp = ros::Time::now();
        point_laser.point.x = 1.1;
        point_laser.point.y = 2.2;
        point_laser.point.z = 3.3;

        // 用 try-catch 防止接收延时导致坐标转换失败
        try {
            // 创建新的座标点，用于接收转换后的坐标
            geometry_msgs::PointStamped point_base =
                buffer.transform(point_laser, "base_link");
            ROS_DEBUG(
                "Transformed position:\nx=%.2f\ny=%.2f\nz=%.2f\nCoordinate: %s\n",
                point_base.point.x,
                point_base.point.y,
                point_base.point.z,
                point_base.header.frame_id.c_str());
        } catch (const tf2::TransformException &ex) {
            ROS_WARN("Unable to transform.");
        }

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}