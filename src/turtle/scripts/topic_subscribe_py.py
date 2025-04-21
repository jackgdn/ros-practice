import os
import rospy
from turtlesim.msg import Pose


def callback(msg):
    print("\033[H")
    print(
        "Turtle Position Information:    \nx={:.3f}    \ny={:.3f}    \ntheta={:.3f}    \nlinear_velocity={:.3f}    \nangular_velocity={:.3f}    \n".format(
            msg.x, msg.y, msg.theta, msg.linear_velocity, msg.angular_velocity
        )
    )


def main():
    rospy.init_node("topic_subscribe_py")
    os.system("clear")
    subscriber = rospy.Subscriber("/turtle1/pose", Pose, callback)
    rospy.spin()


if __name__ == "__main__":
    main()
