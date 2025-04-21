import rospy
from communication_package.srv import Division, DivisionRequest, DivisionResponse


def do_request(req):  # 与 C++ 中不同，这里的回调函数的参数是请求对象，返回值是响应对象
    rospy.loginfo(
        "Received numerator: %f, denominator: %f", req.numerator, req.denominator
    )

    if req.denominator == 0:
        rospy.logerr("Denominator cannot be zero")
        return DivisionResponse(success=False)

    result = req.numerator / req.denominator
    res = DivisionResponse(success=True, result=result)
    rospy.loginfo("Sending result: %f", result)
    return res


def main():
    rospy.init_node("division_server_py")
    server = rospy.Service("division_service_py", Division, handler=do_request)
    rospy.spin()


if __name__ == "__main__":
    main()
