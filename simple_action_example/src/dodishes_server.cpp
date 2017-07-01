#include <simple_action_example/DoDishesAction.h>
#include <actionlib/server/simple_action_server.h>

typedef actionlib::SimpleActionServer<simple_action_example::DoDishesAction> Server;

void execute(const simple_action_example::DoDishesGoalConstPtr& goal, Server* as)
{
  // Do lots of awesome groundbreaking robot stuff here
  ROS_INFO("excuting action_server");
  as->setSucceeded();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "do_dishes_server");
  ros::NodeHandle n;
  Server server(n, "do_dishes", boost::bind(&execute, _1, &server), false);
  server.start();
  ros::spin();
  return 0;
}
