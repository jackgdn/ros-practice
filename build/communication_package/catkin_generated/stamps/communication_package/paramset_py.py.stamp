import rospy


def main():
    rospy.init_node("paramset_py")
    rospy.set_param("name", "Jane Doe")
    rospy.set_param("age", 13)
    rospy.set_param("gender", "Female")

    rospy.sleep(rospy.Duration(3))

    rospy.delete_param("name")
    rospy.delete_param("age")
    rospy.delete_param("gender")


if __name__ == "__main__":
    main()
