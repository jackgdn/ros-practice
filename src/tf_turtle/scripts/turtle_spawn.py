import rospy
from turtlesim.srv import Spawn, SpawnRequest, SpawnResponse


def main():
    rospy.init_node("spawn_turtle")

    client = rospy.ServiceProxy("/spawn", Spawn)
    client.wait_for_service()

    request = SpawnRequest()
    request.name = "turtle2"
    request.x = 1.0
    request.y = 1.0
    request.theta = 1.571

    if client.call(request):
        rospy.loginfo("Turtle spawned successfully!")
    else:
        rospy.logerr("Failed to spawn turtle.")


if __name__ == "__main__":
    main()
