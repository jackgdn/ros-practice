import rospy
from geometry_msgs.msg import Twist


def main():
    rospy.init_node("topic_publish_py")
    publisher = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=1000)

    twist = Twist()
    twist.linear.x = 1.0
    twist.linear.y = 0.0
    twist.linear.z = 0.0
    twist.angular.x = 0.0
    twist.angular.y = 0.0
    twist.angular.z = 0.5

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        publisher.publish(twist)
        rate.sleep()


if __name__ == "__main__":
    main()
