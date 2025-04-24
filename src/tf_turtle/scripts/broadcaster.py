import rospy
import tf2_ros
import tf_conversions
from geometry_msgs.msg import TransformStamped
from turtlesim.msg import Pose


def callback(pose):
    global ns

    broadcaster = tf2_ros.TransformBroadcaster()

    ts = TransformStamped()
    ts.header.frame_id = "world"
    ts.header.stamp = rospy.Time.now()

    """
    通过 launch 文件将 ns 参数传到 Python 节点中，默认会在前后都添加斜线
    例如 turtle 被转换为 /turtle/
    而在 C++ 节点中则会是 /turtle
    因此要去掉最后一个斜线，否则无法识别这个 TF 对象
    同理 main 函数中的 rospy.Subscriber(ns + "pose", Pose, callback) 用的是 "pose" 而非 "/pose"
    """
    ts.child_frame_id = ns[:-1]

    ts.transform.translation.x = pose.x
    ts.transform.translation.y = pose.y
    ts.transform.translation.z = 0

    qtn = tf_conversions.transformations.quaternion_from_euler(0, 0, pose.theta)
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]

    broadcaster.sendTransform(ts)


def main():
    global ns

    rospy.init_node("broadcaster")

    ns = rospy.get_namespace()
    rospy.Subscriber(ns + "pose", Pose, callback)
    rospy.spin()


if __name__ == "__main__":
    main()
