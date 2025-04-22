#include "ros/ros.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/static_transform_broadcaster.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "static_broadcaster_tf");

    tf2_ros::StaticTransformBroadcaster broadcaster; // 创建静态坐标转换广播器
    geometry_msgs::TransformStamped ts;              // 创建坐标信息

    // 设置头信息
    ts.header.stamp = ros::Time::now(); // 设置时间辍
    ts.header.frame_id = "base_link";   // 设置发送者的坐标系名称

    ts.child_frame_id = "laser"; // 设置子级坐标系，一个 TransformStamped
                                 // 对象只能有一个子级坐标系

    // 设置子级坐标系相对父坐标系的偏移量
    ts.transform.translation.x = 1;
    ts.transform.translation.y = 2;
    ts.transform.translation.z = 3;

    tf2::Quaternion qtn; // 创建四元数对象
    qtn.setRPY(0, 0, 0); // 设置 Roll、Pitch、Yaw 角度

    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    broadcaster.sendTransform(ts); // 广播坐标信息
    ros::spin();
    return 0;
}