#include <ros/ros.h>
#include <rj_training/StringWithHeader.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle node_handle;               //interact with ros backend
    
    ros::NodeHandle private_node_handle("~");
    ros::Publisher publisher = node_handle.advertise<rj_training::StringWithHeader>("talker_topic",1);

    std::string greeting = private_node_handle.param<std::string>("greeting", "Hello!") ;


    ros::Rate rate(10 /*Hz*/);
    while(ros::ok)
    {
        rj_training::StringWithHeader msg;
        msg.data = greeting;
        publisher.publish(msg);
        ros::spinOnce();         //Leaving time for backend event loop to spin once and take care of any events
        rate.sleep();
    }

    return 0;
}
