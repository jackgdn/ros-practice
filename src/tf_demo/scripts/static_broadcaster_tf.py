#!/usr/bin/python3

import logging

import rospy
import tf
import tf2_ros
from geometry_msgs.msg import TransformStamped


def main():
    rospy.init_node("static_broadcaster_tf")

    broadcaster = tf2_ros.StaticTransformBroadcaster()  # 创建静态坐标转换广播器
    ts = TransformStamped()  # 创建坐标信息

    ts.header.stamp = rospy.Time.now()  # 设置时间辍
    ts.header.frame_id = "base_link"  # 设置发送者的坐标系名称

    ts.child_frame_id = "laser"  # 设置子级坐标系

    # 设置子级坐标系相对父坐标系的偏移量
    ts.transform.translation.x = 1
    ts.transform.translation.y = 2
    ts.transform.translation.z = 3

    qtn = tf.transformations.quaternion_from_euler(
        0, 0, 0
    )  # 创建四元数对象，并分别设置 RPY 角度

    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]

    broadcaster.sendTransform(ts)  # 广播器发送坐标
    rospy.spin()


if __name__ == "__main__":
    main()
