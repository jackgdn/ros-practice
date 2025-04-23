#include "geometry_msgs/TransformStamped.h"
#include "ros/ros.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "turtlesim/Pose.h"

/*
    回调函数监听 turtlesim_node 的 Pose 消息，然后通过 Pose
    中的参数创建子级坐标系
*/
void callback(const turtlesim::Pose::ConstPtr &pose) {
    static tf2_ros::TransformBroadcaster
        broadcaster; // 声明为 static 以确保程序生命周期中只会创建一个 TransformBroadcaster 对象

    // 创建 TransformStamped 对象并配置
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = "turtle1";

    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0.0; // 平面上 z 为 0

    tf2::Quaternion qtn;
    qtn.setRPY(0.0, 0.0, pose->theta);
    ts.transform.rotation.w = qtn.getW();
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();

    broadcaster.sendTransform(ts);
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "dynamic_broadcaster_tf");
    ros::NodeHandle nh;
    ros::Subscriber subscriber = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 100, callback);
    ros::spin();
    return 0;
}