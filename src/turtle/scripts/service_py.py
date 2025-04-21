#!/usr/bin/python3

import rospy
from turtlesim.srv import Spawn, SpawnRequest, SpawnResponse, Kill, KillRequest , KillResponse


def main():
    rospy.init_node("service_py")
    client_spawn = rospy.ServiceProxy("/spawn", Spawn)
    client_kill = rospy.ServiceProxy("/kill", Kill)
    client_spawn.wait_for_service()
    client_kill.wait_for_service()

    turtle_name = list()
    while True:
        try:
            try:
                x, y, theta, name = input().strip().split()
                spawn_request = SpawnRequest()
                spawn_request.x = float(x)
                spawn_request.y = float(y)
                spawn_request.theta = float(theta)
                spawn_request.name = name
            except ValueError:
                rospy.logerr("Invalid Input")
                continue

            try:
                client_spawn.call(spawn_request)
                rospy.loginfo("Turtle Spawned")
                turtle_name.append(name)
            except rospy.ServiceException:
                rospy.logerr("Failed to Spawn Turtle")

        except EOFError:
            break

    for name in turtle_name:
        kill_request = KillRequest()
        kill_request.name = name
        try:
            client_kill.call(kill_request)
            rospy.loginfo("Turtle Removed")
        except rospy.ServiceException:
            rospy.logerr("Failed to Remove Turtle")


if __name__ == "__main__":
    main()