#!/usr/bin/python3

import rospy
from std_msgs.msg import String


def main():
    rospy.init_node("talker_py")
    chatter_pub = rospy.Publisher("chatter_py", String, queue_size=10)

    msg = String()
    msg_front = "Hello from Python talker!"

    count = 0
    loop_rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        msg.data = msg_front + " " + str(count)

        chatter_pub.publish(msg)
        rospy.loginfo("Python Talker: " + msg.data)
        loop_rate.sleep()
        count += 1


if __name__ == "__main__":
    main()
