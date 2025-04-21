#!/usr/bin/python3

import rospy
from std_msgs.msg import String


def callback(msg):
    rospy.loginfo("Python Listener: " + msg.data)


def main():
    rospy.init_node("listener_py")
    sub = rospy.Subscriber("chatter_cpp", String, callback=callback, queue_size=10)
    rospy.spin()


if __name__ == "__main__":
    main()
