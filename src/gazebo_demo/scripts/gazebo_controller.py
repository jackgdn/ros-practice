from math import pi

import rospy
from geometry_msgs.msg import Twist


def main():
    rospy.init_node("base_controller")

    publisher = rospy.Publisher("/cmd_vel", Twist, queue_size=100)
    twist = Twist()
    twist.linear.x = 0.2

    TIME = pi * 4
    while not rospy.is_shutdown():
        twist.angular.z = -0.5
        publisher.publish(twist)
        rospy.sleep(TIME)

        twist.angular.z = 0.5
        publisher.publish(twist)
        rospy.sleep(TIME)


if __name__ == "__main__":
    main()
