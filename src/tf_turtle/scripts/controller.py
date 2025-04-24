from math import atan2, pow, sqrt

import rospy
import tf2_ros
from geometry_msgs.msg import Twist


def main():
    rospy.init_node("turtle2_controller")

    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)

    publisher = rospy.Publisher("turtle2/cmd_vel", Twist, queue_size=100)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        try:
            ts = buffer.lookup_transform("turtle2", "turtle1", rospy.Time(0))

            twist = Twist()
            twist.linear.x = 0.5 * sqrt(
                pow(ts.transform.translation.x, 2) + pow(ts.transform.translation.y, 2)
            )
            twist.angular.z = 4 * atan2(
                ts.transform.translation.y, ts.transform.translation.x
            )

            publisher.publish(twist)
        except tf2_ros.TransformException:
            rospy.logwarn("Failed to process")

        rate.sleep()


if __name__ == "__main__":
    main()
