import rospy


def main():
    rospy.init_node("paramget_py")

    rospy.sleep(rospy.Duration(1))
    name = rospy.get_param("name")
    age = rospy.get_param("age")
    gender = rospy.get_param("gender")

    rospy.loginfo("Name: %s, Age: %d, Gender: %s", name, age, gender)

    rospy.sleep(rospy.Duration(3))
    # 如果参数不存在，则返回默认值，此处设置为 None
    name = rospy.get_param("name", None)
    age = rospy.get_param("age", None)
    gender = rospy.get_param("gender", None)
    if name and age and gender:
        rospy.loginfo("Name: %s, Age: %d, Gender: %s", name, age, gender)
    else:
        rospy.logerr("Failed to get parameters")


if __name__ == "__main__":
    main()
