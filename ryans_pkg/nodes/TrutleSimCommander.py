 #!/usr/bin/env python3

#Referenced from: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29 

 import rospy
 from std_msgs.msgs import String




 def turtlecommander():

    rospy.init_node('turtlecommander', anonymous=True)

    rospy.Subscriber('command_topic', String, callback)

    rospy.Spin()

if __name__ == '__main__':
    turtlecommander()