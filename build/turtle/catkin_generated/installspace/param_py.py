import rospy


def main():
    rospy.init_node("param_py")
    rospy.set_param("background_r", 113)
    rospy.set_param("background_g", 113)
    rospy.set_param("background_b", 113)


if __name__ == "__main__":
    main()
