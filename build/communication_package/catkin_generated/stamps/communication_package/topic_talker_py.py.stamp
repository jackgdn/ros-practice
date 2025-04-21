import rospy
from std_msgs.msg import String


def main():
    rospy.init_node("topic_talker_py")  # 初始化节点
    chatter_pub = rospy.Publisher(
        "topic_chatter_py", String, queue_size=10
    )  # 创建发布者对象

    msg = String()  # 创建消息对象
    msg_front = "Hello from Python talker!"

    count = 0
    loop_rate = rospy.Rate(1)  # 设置循环频率为 1Hz

    while not rospy.is_shutdown():
        msg.data = msg_front + " " + str(count)

        chatter_pub.publish(msg)  # 发布消息
        rospy.loginfo("Python Talker: " + msg.data)
        loop_rate.sleep()  # 控制循环频率
        count += 1


if __name__ == "__main__":
    main()
