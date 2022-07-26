#include <ros/ros.h>
#include <rj_training/StringWithHeader.h>
#include <iostream>

void callback(const rj_training::StringWithHeaderConstPtr& msg)
{
    std::cout << msg->data << std::endl;    //shared pointer use -> not dot
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "listener");

    ros::NodeHandle node_handle;

    ros::Subscriber subscriber = node_handle.subscribe("talker_topic", 1, &callback);
    
    ros::spin();
    return 0;
}
