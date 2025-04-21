import rospy
from communication_package.msg import Person


def callback(msg):
    rospy.loginfo(
        "Name: %s, Age: %d, Gender: %s from Python",
        msg.name,
        msg.age,
        "Male" if msg.gender else "Female",
    )


def main():
    rospy.init_node("person_listener_py")
    person_sub = rospy.Subscriber("person_chatter_py", Person, callback, queue_size=10)
    rospy.spin()


if __name__ == "__main__":
    main()
