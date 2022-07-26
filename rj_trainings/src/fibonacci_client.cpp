#include <iostream>
#include <ros/ros.h>
#include <actionlib_tutorials/FibonacciAction.h>
#include <actionlib/client/simple_action_client.h>


int main(int argc, char** argv)
{
    ros::init(argc, argv, "fibonacci_client");

    actionlib::SimpleActionClient<actionlib_tutorials::FibonacciAction> client("fibonacci", true);

    client.waitForServer();

    actionlib_tutorials::FibonacciGoal goal;
    goal.order = 20;
    client.sendGoal(goal);

    bool finished = client.waitForResult(ros::Duration(30.9));

    if(finished)
    {
        const auto& sequence = client.getResult()->sequence;
        std::cout << "Result: "; 
        for(const auto& number : sequence)
        {
            std::cout << number << ' ';
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Action timed out." << std::endl;
    }

    return 0;
}