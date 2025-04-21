import rospy
from communication_package.srv import Division, DivisionRequest, DivisionResponse


def main():
    rospy.init_node("division_client_py")
    client = rospy.ServiceProxy("division_service_cpp", Division)  # 创建客户端
    client.wait_for_service()  # 等待服务端启动

    req = DivisionRequest()  # 创建请求对象
    loop_rate = rospy.Rate(1)

    for i in range(4)[::-1]:
        req.numerator = 10.0
        req.denominator = i

        res = client.call(req)  # 调用服务端
        if res.success:
            rospy.loginfo("Result: %f", res.result)
        else:
            rospy.logerr("Failed to call service")
        loop_rate.sleep()


if __name__ == "__main__":
    main()
