#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/TransformStamped.h"
#include "ros/ros.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h" // 这个头文件不能少，否则过不了编译
#include "tf2_ros/transform_listener.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "sub_frames_cpp");
    ros::NodeHandle nh;

    // 创建 TF 订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Duration(1.3).sleep();

    // 解析 son1 相对于 son2 的坐标
    geometry_msgs::TransformStamped ts = buffer.lookupTransform("son2", "son1", ros::Time(0));
    ROS_INFO("----------");
    ROS_INFO("Parent frame id: %s", ts.header.frame_id.c_str());
    ROS_INFO("Children frame id: %s", ts.child_frame_id.c_str());
    ROS_INFO("Relative location: x=%.2f, y=%.2f, z=%.2f",
             ts.transform.translation.x,
             ts.transform.translation.y,
             ts.transform.translation.z);
    ROS_INFO("Relative angle: w=%.2f, x=%.2f, y=%.2f, z=%.2f",
             ts.transform.rotation.w,
             ts.transform.rotation.x,
             ts.transform.rotation.y,
             ts.transform.rotation.z);

    // 子级坐标系座标点解析
    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "son1";
    ps.header.stamp = ros::Time::now();
    ps.point.x = 1.1;
    ps.point.y = 2.2;
    ps.point.z = 3.3;

    geometry_msgs::PointStamped ps_son2;
    ps_son2 = buffer.transform(ps, "son2", ros::Duration(0));
    ROS_INFO("The coordinates of the point in frame son2: x=%.2f, y=%.2f, z=%.2f",
             ps_son2.point.x,
             ps_son2.point.x,
             ps_son2.point.x);
    ROS_INFO("----------");

    return 0;
}
