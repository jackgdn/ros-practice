import rospy
from communication_package.msg import Person


def main():
    rospy.init_node("person_talker_py")
    person_pub = rospy.Publisher("person_chatter_py", Person, queue_size=10)

    person = Person()
    person.name = "Jane Doe"
    person.age = 13
    person.gender = False

    loop_rate = rospy.Rate(1)
    rospy.sleep(rospy.Duration(3, 0))  # 等待订阅者连接
    while not rospy.is_shutdown():
        person_pub.publish(person)
        person.age += 1
        loop_rate.sleep()


if __name__ == "__main__":
    main()
