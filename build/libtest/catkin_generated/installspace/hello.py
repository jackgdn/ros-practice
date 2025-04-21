import rospy
import logging


def hello():
    logging.getLogger("rosout").setLevel(logging.DEBUG)  # 修改日志级别
    rospy.logdebug("Hello, world! Hello, Python!")
