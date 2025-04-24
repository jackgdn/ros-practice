from random import uniform

import rospy
from geometry_msgs.msg import Twist


def main():
    rospy.init_node("random_track")
    publisher = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=100)

    twist = Twist()
    twist.linear.x = 3

    rate = rospy.Rate(2)
    while not rospy.is_shutdown():
        twist.angular.z = uniform(-3.142, 3.142)
        publisher.publish(twist)
        rate.sleep()


if __name__ == "__main__":
    main()
