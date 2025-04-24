#include "geometry_msgs/TransformStamped.h"
#include "ros/ros.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "turtlesim/Pose.h"

std::string ns;

void callback(const turtlesim::Pose::ConstPtr &pose) {
    // 创建 TF 广播对象
    static tf2_ros::TransformBroadcaster broadcaster;

    // 将 Pose 转化为 TransformStamped
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = ns;

    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;

    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    broadcaster.sendTransform(ts);
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "broadcaster");
    ros::NodeHandle nh;

    ns = nh.getNamespace();

    ros::Subscriber subscriber = nh.subscribe<turtlesim::Pose>(ns + "/pose", 100, callback);
    ros::spin();
    return 0;
}