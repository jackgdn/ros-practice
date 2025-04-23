import rospy
import tf2_ros
from geometry_msgs.msg import TransformStamped
from tf2_geometry_msgs import PointStamped


def main():
    rospy.init_node("sub_frames_py")

    # 创建 TF 订阅对象
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)

    rospy.sleep(3.3)

    # 解析 son1 相对于 son2 的坐标
    ts = buffer.lookup_transform("son2", "son1", rospy.Time(0))
    rospy.loginfo("----------")
    rospy.loginfo("Parent frame id: %s", ts.header.frame_id)
    rospy.loginfo("Children frame id: %s", ts.child_frame_id)
    rospy.loginfo(
        "Relative location: x=%.2f, y=%.2f, z=%.2f",
        ts.transform.translation.x,
        ts.transform.translation.y,
        ts.transform.translation.z,
    )
    rospy.loginfo(
        "Relative angle: w=%.2f, x=%.2f, y=%.2f, z=%.2f",
        ts.transform.rotation.w,
        ts.transform.rotation.x,
        ts.transform.rotation.y,
        ts.transform.rotation.z,
    )

    # 在 son1 中创建一个座标点
    ps = PointStamped()
    ps.header.frame_id = "son1"
    ps.header.stamp = rospy.Time.now()
    ps.point.x = 1.1
    ps.point.y = 2.2
    ps.point.z = 3.3

    # 计算点在 son2 中的坐标
    ps_son2 = buffer.transform(ps, "son2", rospy.Duration(0))
    rospy.loginfo(
        "The coordinates of the point in frame son2: x=%.2f, y=%.2f, z=%.2f",
        ps_son2.point.x,
        ps_son2.point.x,
        ps_son2.point.x,
    )
    rospy.loginfo("----------")


if __name__ == "__main__":
    main()
