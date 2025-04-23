from random import uniform

import rospy
from geometry_msgs.msg import Twist


def main():
    rospy.init_node("random_track")
    publisher = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=1000)

    twist = Twist()

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        twist.linear.x = uniform(-1.3, 1.3)
        twist.angular.z = uniform(-1.3, 1.3)
        publisher.publish(twist)
        rate.sleep()


if __name__ == "__main__":
    main()
