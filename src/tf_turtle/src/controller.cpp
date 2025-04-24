#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "turtle2_controller");
    ros::NodeHandle nh;

    // 创建 TF 订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    // 创建发布到 /turtle2/cmd_vel 的发布对象
    ros::Publisher publisher = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 100);

    ros::Rate rate(10);
    while (ros::ok()) {
        try {
            geometry_msgs::TransformStamped ts = buffer.lookupTransform("turtle2", "turtle1", ros::Time(0));

            // 根据坐标信息生成速度信息
            geometry_msgs::Twist twist;
            twist.linear.x = 0.5 * sqrt(pow(ts.transform.translation.x, 2) + pow(ts.transform.translation.y, 2));
            twist.angular.z = 4 * atan2(ts.transform.translation.y, ts.transform.translation.x);

            publisher.publish(twist);
        } catch (const tf2::TransformException &ex) {
            ROS_WARN("Failed to process.");
        }

        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}