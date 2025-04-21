import os
import sys
import rospy

"""
将当前文件所在路径添加到系统路径中
以便导入自定义模块
"""
sys.path.insert(0, os.path.dirname(__file__))

import hello

if __name__ == "__main__":
    rospy.init_node("hello_py")
    hello.hello()
