import rospy
import tf
import tf2_ros
import tf.transformations
from geometry_msgs.msg import TransformStamped
from turtlesim.msg import Pose


def callback(pose):

    # 创建 TF 广播器和 TransformStamped 对象
    broadcaster = tf2_ros.TransformBroadcaster()
    ts = TransformStamped()
    ts.header.frame_id = "world"
    ts.header.stamp = rospy.Time.now()
    ts.child_frame_id = "turtle1"

    ts.transform.translation.x = pose.x
    ts.transform.translation.y = pose.y
    ts.transform.translation.z = 0.0

    qtn = tf.transformations.quaternion_from_euler(0, 0, pose.theta)
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]

    broadcaster.sendTransform(ts)


def main():
    rospy.init_node("dynamic_broadcaster_tf")
    subscriber = rospy.Subscriber("/turtle1/pose", Pose, callback)
    rospy.spin()


if __name__ == "__main__":
    main()
