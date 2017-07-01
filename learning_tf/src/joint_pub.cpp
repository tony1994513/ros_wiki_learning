#include "ros/ros.h"
#include "baxter_core_msgs/JointCommand.h"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "baxter_left_arm_joint_pub");
  ros::NodeHandle n;
  ros::Publisher left_cmd_pub = n.advertise<baxter_core_msgs::JointCommand>("/robot/limb/left/joint_command", 1);
  // publish at at least 5 Hz, or else Baxter switches back to Position mode and holds position
  ros::Rate loop_rate(100);
  baxter_core_msgs::JointCommand cmd;
  // command in velocity mode
  cmd.mode = baxter_core_msgs::JointCommand::VELOCITY_MODE;
  // command joints in the order shown in baxter_interface
  cmd.names.push_back("left_s0");
  cmd.names.push_back("left_s1");
  cmd.names.push_back("left_e0");
  cmd.names.push_back("left_e1");
  cmd.names.push_back("left_w0");
  cmd.names.push_back("left_w1");
  cmd.names.push_back("left_w2");
  // set your calculated velocities
  cmd.command.resize(cmd.names.size());
  for(size_t i = 0; i < cmd.names.size(); i++)
    cmd.command[i] = 0.0;
  std::cout<<cmd<<std::endl;
  while(ros::ok()){
    //update cmd.command commands here
    left_cmd_pub.publish(cmd);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
