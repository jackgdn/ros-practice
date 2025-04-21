import rospy
from std_msgs.msg import String


def callback(msg):
    rospy.loginfo("Python Listener: " + msg.data)


def main():
    rospy.init_node("topic_listener_py")  # 初始化节点
    sub = rospy.Subscriber(
        "topic_chatter_py", String, callback=callback, queue_size=10
    )  # 创建订阅者对象并注册回调函数
    rospy.spin()  # 保持节点运行，直到节点关闭


if __name__ == "__main__":
    main()
