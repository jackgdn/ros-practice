#include "geometry_msgs/PointStamped.h"
#include "ros/ros.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "dynamic_listener_tf");
    ros::NodeHandle nh;
    ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug);

    // 创建 TF 订阅对象并且监听
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate rate(1);
    while (ros::ok()) {
        // 生成子级坐标系的座标点并配置
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id = "turtle1";
        point_laser.header.stamp = ros::Time();
        point_laser.point.x = 1;
        point_laser.point.y = 3;
        point_laser.point.z = 0;

        // 座标点转换
        try {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_laser, "world");
            ROS_DEBUG("\nTransformed position:\nx=%.2f\ny=%.2f\nCoordinate:\n%s\n",
                      point_base.point.x,
                      point_base.point.y,
                      point_base.header.frame_id.c_str());
        } catch (const tf2::TransformException &ex) {
            ROS_WARN("Failed to transform.");
        }
        rate.sleep();
    }
    return 0;
}