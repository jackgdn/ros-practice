import os

import rospy
import tf2_ros
from tf2_geometry_msgs import PointStamped


def main():
    rospy.init_node("dynamic_listener_tf")

    # 创建 TF 订阅对象
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        point_laser = PointStamped()
        point_laser.header.frame_id = "turtle1"
        point_laser.header.stamp = rospy.Time.now()
        point_laser.point.x = 1
        point_laser.point.y = 3
        point_laser.point.z = 0.0

        try:
            point_base = buffer.transform(point_laser, "world", rospy.Duration(1))
            rospy.logdebug(
                "\nTransformed position:\nx=%.2f\ny=%.2f\n\Coordinate: %s\n",
                point_base.point.x,
                point_base.point.y,
                point_base.header.frame_id,
            )
        except:
            rospy.logwarn("Failed to transform.")
        rate.sleep()


if __name__ == "__main__":
    main()
