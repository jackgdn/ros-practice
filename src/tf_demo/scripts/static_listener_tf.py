#!/usr/bin/python3

import logging

import rospy
import tf2_ros
from tf2_geometry_msgs import PointStamped  # 使用 tf2 内置的 PointStamped


def main():
    rospy.init_node("static_listener_tf")
    logging.getLogger("rosout").setLevel(logging.DEBUG)  # 修改日志级别

    # 创建 TF 订阅对象并且监听
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():

        # 创建子级坐标系中的座标点
        point_laser = PointStamped()
        point_laser.header.frame_id = "laser"
        point_laser.header.stamp = rospy.Time.now()
        point_laser.point.x = 1.1
        point_laser.point.y = 2.2
        point_laser.point.z = 3.3

        try:
            point_base = buffer.transform(point_laser, "base_link")
            rospy.logdebug(
                "\nTransformed position:\nx=%.2f\ny=%.2f\nCoordinate:\n%s\n",
                point_base.point.x,
                point_base.point.y,
                point_base.header.frame_id,
            )
        except tf2_ros.TransformException:
            rospy.logwarn("Failed to transform.")
        rate.sleep()


if __name__ == "__main__":
    main()
