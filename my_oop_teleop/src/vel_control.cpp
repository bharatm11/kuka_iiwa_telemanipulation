#include<ros/ros.h>
#include<omni_msgs/OmniFeedback.h>
#include<omni_msgs/OmniButtonEvent.h>
#include<geometry_msgs/Twist.h>
#include<geometry_msgs/PoseStamped.h>
#include<geometry_msgs/WrenchStamped.h>
#include<sensor_msgs/JointState.h>
#include<trajectory_msgs/JointTrajectory.h>
#include<trajectory_msgs/JointTrajectoryPoint.h>
#include<kdl/chain.hpp>
#include<std_msgs/UInt8.h>
#include<std_msgs/Bool.h>
#include<std_msgs/Float64.h>
#include<std_msgs/Int16.h>
#include<tf/transform_listener.h>
#include "kuka.hpp"
#include "phantom.hpp"

#include <kdl/chainfksolver.hpp>
#include <kdl/chainiksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainiksolverpos_nr.hpp>
#include <kdl/chainjnttojacsolver.hpp>
sensor_msgs::JointState joints_phantom;
sensor_msgs::JointState joints;
// initialize a joint command point
void initialize_points(trajectory_msgs::JointTrajectoryPoint & _pt, int _nj, float _init)
{
	for (int i = 0; i < _nj; ++i)
	{
		if(i==0)
		_pt.positions.push_back(0);//1.3);
		if(i==1)
		_pt.positions.push_back(1.0);//0.0);
		if(i==2)
		_pt.positions.push_back(1.0);//0.0);
		if(i==3)
		_pt.positions.push_back(-1.57);//-1.57);
		if(i==4)
		_pt.positions.push_back(0.0);//0.0);
		if(i==5)
		_pt.positions.push_back(1.0);//1.57);
		if(i==6)
		_pt.positions.push_back(0);
	}

}
std_msgs::Float64 tele_start_msg;
void tele_start_callback(const std_msgs::Float64ConstPtr& msg2)
{
	tele_start_msg.data=msg2->data;
}

// initialize the joint positions with a non-zero value to be used in the solvers
void initialize_joints(KDL::JntArray & _jointpositions, int _nj, float _init){
	for (int i = 0; i < _nj; ++i)
	_jointpositions(i) = _init;
}

void initialize_joints(sensor_msgs::JointState & _jointpositions, int _nj, float _init){
	for (int i = 0; i < _nj; ++i)
	_jointpositions.position.push_back(_init);
}


//Read joint values LWR
bool initialized = false;
bool initialized_phantom = false;
void get_joints(const sensor_msgs::JointState & data)
{
	for (int i = 0; i < data.position.size();++i)
	{
		// if this is not the first time the callback function is read, obtain the joint positions
		if(initialized){
			joints.position[i] = data.position[i];
			// otherwise initilize them with 0.0 values
		}
	}
	initialized = true;
}
double cam_yaw=0.0;
double cam_pitch=0.0;
double cam_roll=0.0;
geometry_msgs::Twist phantom_joints_msg;
//Get Joint values of PHANTOM
void get_joints_phantom(const sensor_msgs::JointState & data)
{
	double swap;
	for (int i = 0; i < 6;++i)
	{
		joints_phantom.position[i] = data.position[i];
	}
	/*joints_phantom.position[1]=joints_phantom.position[1]-0.82;
	joints_phantom.position[2]=joints_phantom.position[2]-1.422;
	joints_phantom.position[3]=3.115-joints_phantom.position[3];
	joints_phantom.position[4]=-2.248-joints_phantom.position[4];
	joints_phantom.position[5]=-3.185-joints_phantom.position[5];*/

	//joints_phantom.position[2] -= M_PI_2; // correct the offset in reading this joint positions based on the raw sensor data
	//joints_phantom.position[3] -= 6.29; // correct the offset in reading this joint positions based on the raw sensor data
	//joints_phantom.position[4] += 0.785398; // correct the offset in reading this joint positions based on the raw sensor data
	//joints_phantom.position[5]+=joints_phantom.position[5]-3.98;
	//joints_phantom.position[4]+=joints_phantom.position[4]+2.02;
	//joints_phantom.position[3]+=joints_phantom.position[3]-4.09;
	//AXES 6 AND 4 ARE SWITCHED!!!
	joints_phantom.position[1]=joints_phantom.position[1]-0.82;
	joints_phantom.position[3]=3.115-joints_phantom.position[3];
	joints_phantom.position[5]=-3.185-joints_phantom.position[5];
	joints_phantom.position[4]=-2.248-joints_phantom.position[4];
	swap=joints_phantom.position[3];
	joints_phantom.position[3]=joints_phantom.position[5];
	joints_phantom.position[5]=swap;//3.1205;//swap;*/
	cam_roll = (joints_phantom.position[3])*0.01;
	cam_pitch = (joints_phantom.position[4])*0.03;
	cam_yaw = (joints_phantom.position[5])*0.008;
	phantom_joints_msg.angular.x=joints_phantom.position[3];
	phantom_joints_msg.angular.y=joints_phantom.position[4];
	phantom_joints_msg.angular.z=joints_phantom.position[5];

	if((joints_phantom.position[3]>-0.6)&&(joints_phantom.position[3]<0.6))
	{
		cam_roll=0;
	}
	if((joints_phantom.position[4]>-0.3)&&(joints_phantom.position[4]<0.3))
	{
		cam_pitch=0;
	}
	if((joints_phantom.position[5]>-0.6)&&(joints_phantom.position[5]<0.6))
	{
		cam_yaw=0;
	}
	initialized_phantom = true;

}
//Get Pose of PHANTOM
geometry_msgs::PoseStamped pos;
void get_pos(const geometry_msgs::PoseStamped & _data)
{
	pos = _data;

}

geometry_msgs::PoseStamped iiwa_pos;
void iiwa_get_pos(const geometry_msgs::PoseStamped & _data)
{
	iiwa_pos = _data;

}

geometry_msgs::WrenchStamped ft;
void get_forces(const geometry_msgs::WrenchStamped & _fdata)
{
	ft = _fdata;

}

geometry_msgs::WrenchStamped compensated_ft;
void get_compensated_forces(const geometry_msgs::WrenchStamped & _fdata2)
{
	compensated_ft = _fdata2;

}

void eval_points(trajectory_msgs::JointTrajectoryPoint & _point, KDL::JntArray & _jointpositions, int _nj){
	// joints can move between -+: 172,120,172,120,172,120,170
	//double joint_bounds[] = {3.002, 2.0944,3.002, 2.0944,3.002, 2.0944, 3.002};
	for (int i = 0; i < _nj; ++i){
		while(_jointpositions(i) > M_PI)
		_jointpositions(i) -= 2*M_PI;
		while(_jointpositions(i) < -M_PI)
		_jointpositions(i) += 2*M_PI;
		_point.positions[i] = _jointpositions(i);
	}
}


omni_msgs::OmniFeedback centering_force;

double prev_z_phant_command;
double prev_x_phant_command;
double prev_y_phant_command;
double prev_z_iiwa_position;
double prev_x_iiwa_position;
double prev_y_iiwa_position;

//////////   MAIN  //////////////
int main(int argc, char * argv[])
{

	//Define LWR Chain
	KDL::Chain chain;
	//base
	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::None),KDL::Frame::DH_Craig1989(0,0,0.33989,0)));
	//joint 1
	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0, -M_PI_2,0,0)));
	//joint 2
	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0,M_PI_2,0.40011,0)));
	//joint 3
	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0,M_PI_2,0,0)));
	//joint 4
	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0, -M_PI_2,0.40003,0)));
	//joint 5
	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0, -M_PI_2,0,0)));
	//joint 6
	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0, M_PI_2,0,0)));
	//joint 7 (with flange adapter)
	//chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0,0,0.12597,0)));
	chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0,0,0.37897,0)));




	//Define PHANTOM Chain
	/*KDL::Chain chain_phantom;
	//base
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::None),KDL::Frame::DH(0,0,0,0)));
	//joint 1
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0, M_PI_2,0,0)));
	//joint 2
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0.1321, 0.0,0.0,0)));
	//joint 3
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0, M_PI_2,0.0,0)));
	//joint 4
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0, -M_PI_2,0.1321,0)));
	//joint 5 not considering the roll angle in th stylus (last DoF)
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0,M_PI_2,0,0)));
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0,0.0,-0.05,0)));
	*/
	KDL::Chain chain_phantom;
	//base
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::None),KDL::Frame::DH(0,0,0,0)));
	//joint 1
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0, M_PI_2,0,0)));
	//joint 2
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0.157508, 0.0,0.0,0)));//127508
	//joint 3
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0, M_PI_2,0,0)));//0.149352
	//joint 4
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0, -M_PI_2,0.139352,0)));
	//joint 5 not considering the roll angle in th stylus (last DoF)
	chain_phantom.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH(0,M_PI_2,0,0)));




	//Define FK Solver for BOTH
	KDL::ChainFkSolverPos_recursive fksolver = KDL::ChainFkSolverPos_recursive(chain);
	KDL::ChainFkSolverPos_recursive fksolver_phantom = KDL::ChainFkSolverPos_recursive(chain_phantom);


	//Define IK Solver for LWR
	KDL::ChainIkSolverVel_pinv iksolverv = KDL::ChainIkSolverVel_pinv(chain);//Inverse velocity solver
	KDL::ChainIkSolverPos_NR iksolver(chain,fksolver,iksolverv,100,1e-4);//Maximum 100 iterations, stop at accuracy 1e-6


	//Define number of joints for BOTH
	unsigned int nj = chain.getNrOfJoints();
	unsigned int nj_phantom = chain_phantom.getNrOfJoints();


	//Define Joint Arrays for Joint Positions for BOTH
	KDL::JntArray jointpositions = KDL::JntArray(nj);
	KDL::JntArray jointpositions_phantom = KDL::JntArray(nj_phantom);

	//Define Joint Arrays for New Joint Positions for LWR
	KDL::JntArray jointpositions_new = KDL::JntArray(nj);

	//Initialize Joint Arrays for Joint Positions
	initialize_joints(jointpositions, nj, 0.2);
	initialize_joints(jointpositions_phantom, nj_phantom, 0.2);

	////Initialize Joints to be Read
	initialize_joints(joints, nj, 0.0);
	initialize_joints(joints_phantom, nj_phantom, 0.0);

	//Initialize ROS node
	ros::init(argc, argv, "tele_op");
	ros::NodeHandle nh_;

	//Set loop rate
	int loop_freq = 100;
	float dt = (float) 1/loop_freq;
	ros::Rate loop_rate(loop_freq);
	ROS_INFO_STREAM("Start tele_op");
	//Define Joint Position Command Publisher
	std::string command_topic = "/iiwa/PositionJointInterface_trajectory_controller/command";
	ros::Publisher cmd_pub = nh_.advertise<trajectory_msgs::JointTrajectory>(command_topic,dt);
	ros::Publisher pub1 = nh_.advertise<std_msgs::Float64>("/debug",10);
	ros::Publisher blocker = nh_.advertise<std_msgs::Float64>("/blocker",10);
	ros::Publisher solver_debug = nh_.advertise<std_msgs::Int16>("solver_debug",10);
	ros::Publisher rob_pose = nh_.advertise<geometry_msgs::Twist>("/iiwa_fk",10);
	ros::Publisher phantom_rpy = nh_.advertise<geometry_msgs::Twist>("/phantom_rpy",10);
	ros::Publisher pha_pose = nh_.advertise<geometry_msgs::PoseStamped>("/phant_pose",10);
	ros::Publisher phantom_joints = nh_.advertise<geometry_msgs::Twist>("/phantom_joints_zeroed",10);
	ros::Publisher robot_pose_recorder = nh_.advertise<geometry_msgs::Twist>("/robot_pose_recorder",10);
	//ros::Publisher force_pub =nh_.advertise<omni_msgs::OmniFeedback>("/phantom/force_feedback",10);
	geometry_msgs::PoseStamped fk_pose;
	std_msgs::Float64 msg1;
	msg1.data=1;
	pub1.publish(msg1);
	tf::TransformListener listener;
	tf::StampedTransform transform;
	tf::Transform inv_transform;

	tf::TransformListener listener2;
	tf::StampedTransform transform2;
	tf::Transform inv_transform2;

	//Define Subscriber to Read LWR Joints
	ros::Subscriber joints_sub = nh_.subscribe("/iiwa/joint_states",10, get_joints);

	//Define Subscriber to Read Phantom Joints
	ros::Subscriber joints_phantom_sub = nh_.subscribe("/phantom/joint_states",10, get_joints_phantom);

	//Define Subscriber to Read Phantom Pose
	ros::Subscriber pos_sub = nh_.subscribe("/phantom/pose",10, get_pos);
	ros::Subscriber forces_sub = nh_.subscribe("/ft18215",10, get_forces);
	ros::Subscriber compensated_forces_sub = nh_.subscribe("/compensated_forces_ft_frame",10, get_compensated_forces);
	ros::Subscriber iiwa_pos_sub = nh_.subscribe("/iiwa/state/CartesianPose",.10, iiwa_get_pos);
	ros::Subscriber tele_start_sub=nh_.subscribe("/tele_start",10, tele_start_callback);
	//Define joint_cmd: final joint command
	//Define pt: current trajectory points
	//Define pt2: new trajectory points
	trajectory_msgs::JointTrajectory joint_cmd;
	trajectory_msgs::JointTrajectoryPoint pt,pt2;

	//Initialize pt, pt2
	initialize_points(pt,nj,10.0);
	initialize_points(pt2,nj,0.0);
	//Define Current Cartesian Position of LWR
	KDL::Frame current_cartpos;
	KDL::Frame cartpos_new;
	//Define positions and orientations for Phantom input
	double roll, pitch, yaw, x, y, z;
	double roll_phantom, pitch_phantom, yaw_phantom;
	double roll_phantom_init, pitch_phantom_init, yaw_phantom_init;
	double roll_iiwa_init, pitch_iiwa_init, yaw_iiwa_init;
	std_msgs::Int16 ret_solver;
	//Define joint names

	joint_cmd.joint_names.push_back("iiwa_joint_1");
	joint_cmd.joint_names.push_back("iiwa_joint_2");
	joint_cmd.joint_names.push_back("iiwa_joint_3");
	joint_cmd.joint_names.push_back("iiwa_joint_4");
	joint_cmd.joint_names.push_back("iiwa_joint_5");
	joint_cmd.joint_names.push_back("iiwa_joint_6");
	joint_cmd.joint_names.push_back("iiwa_joint_7");

	//Define Cartesian Position KDL Frames for BOTH
	KDL::Frame cartpos;
	KDL::Frame cartpos_iiwa_init;
	KDL::Frame cartpos_phantom;
	//Define Roation Matrix for Roll,Pitch Yaw
	KDL::Rotation rpy = KDL::Rotation::RPY(roll,pitch,yaw);


	pt.time_from_start = ros::Duration(1.0);
	joint_cmd.points.push_back(pt);
	geometry_msgs::Twist ref;
	geometry_msgs::Twist xyz;
	geometry_msgs::Twist xyz_new;
	geometry_msgs::Twist xyz_phantom;
	geometry_msgs::Twist xyz_phantom_init;
	geometry_msgs::Twist xyz_iiwa_init;
	geometry_msgs::Twist xyz_command;
	double roll_new, pitch_new, yaw_new;
	msg1.data=2;
	pub1.publish(msg1);
	//initialize robot to start pose
	//initialize_robot_start(pt);
	ros::spinOnce();
	joint_cmd.points[0] = pt;
	joint_cmd.header.seq = 0;
	joint_cmd.header.stamp=ros::Time::now();
	joint_cmd.header.frame_id = "";
	/*for(int j = 0; j<1500000; ++j)
	{
	cmd_pub.publish(joint_cmd);
}*/
ros::Duration(5).sleep();
ros::spinOnce();
bool kinematics_status;
bool start_loc_available = false;
bool all_zero = true;
// Read Initial Transform For Initial IIWA Cartesian
try{
	listener.lookupTransform("/US_probe_tip222", "/world", ros::Time(0), transform);
	inv_transform = transform.inverse();
}
catch (tf::TransformException &ex) {
	ROS_ERROR("%s",ex.what());
	ros::Duration(1.0).sleep();
}
tf::Vector3 iiwa_pos_in_camera, iiwa_pos_in_world;
tf::Vector3 iiwa_prev_in_camera, iiwa_prev_in_world;
tf::Vector3 iiwa_init_pos_in_camera, iiwa_init_pos_in_world;
tf::Quaternion iiwa_rot_in_cam;
tf::Quaternion phantom_rot_in_cam;
tf::Quaternion phantom_rot_in_world;
tf::Quaternion iiwa_init_rot_in_cam;
tf::Quaternion iiwa_init_rot_in_world;
double phantom_roll_in_cam,phantom_pitch_in_cam,phantom_yaw_in_cam;
double iiwa_init_roll_in_cam = 0.0;
double iiwa_init_pitch_in_cam = 0.0;
double iiwa_init_yaw_in_cam = 0.0;

double iiwa_roll_in_cam = 0.0;
double iiwa_pitch_in_cam = 0.0;
double iiwa_yaw_in_cam = 0.0;

bool blocking=0;
std_msgs::Float64 block_msg;

kuka ku;
trajectory_msgs::JointTrajectory cmd;
ros::spinOnce();
cmd = ku.driveRobot(ku.initializeHomePos());
cmd_pub.publish(cmd);
ros::Duration(3).sleep();

//Read Joint Positions of Phantom and put them in KDL format
for (int k = 0; k<nj_phantom; ++k)
{
	jointpositions_phantom(k) = joints_phantom.position[k];
}
kinematics_status = fksolver_phantom.JntToCart(jointpositions_phantom,cartpos_phantom);
if(kinematics_status>=0)
{
	xyz_phantom_init.linear.x = pos.pose.position.x;//cartpos_phantom.p[0];
	xyz_phantom_init.linear.y = pos.pose.position.y;//cartpos_phantom.p[1];
	xyz_phantom_init.linear.z = pos.pose.position.z;//cartpos_phantom.p[2];
	//Get roll, pitch, yaw values
	cartpos_phantom.M.GetRPY(roll_phantom_init, pitch_phantom_init, yaw_phantom_init);
	xyz_phantom_init.angular.x = roll_phantom_init;
	xyz_phantom_init.angular.y = pitch_phantom_init;
	xyz_phantom_init.angular.z = yaw_phantom_init;

}
ros::spinOnce();
//Read Joint Positions of IIWA and put them in KDL format
for (int k = 0; k<7; ++k)
{
	jointpositions(k) = joints.position[k];

}
//Perform Forward Kinematics to get Cartesian Pose of LWR
kinematics_status = fksolver.JntToCart(jointpositions,cartpos_iiwa_init);
if(kinematics_status>=0)
{

	xyz_iiwa_init.linear.x = cartpos_iiwa_init.p[0];
	xyz_iiwa_init.linear.y = cartpos_iiwa_init.p[1];
	xyz_iiwa_init.linear.z = cartpos_iiwa_init.p[2];
	cartpos_iiwa_init.M.GetRPY(roll_iiwa_init, pitch_iiwa_init, yaw_iiwa_init);
	xyz_iiwa_init.angular.x = roll_iiwa_init;
	xyz_iiwa_init.angular.y = pitch_iiwa_init;
	xyz_iiwa_init.angular.z = yaw_iiwa_init;
	/*xyz_iiwa_init.linear.x = iiwa_pos.pose.position.x;
	xyz_iiwa_init.linear.y = iiwa_pos.pose.position.y;
	xyz_iiwa_init.linear.z = iiwa_pos.pose.position.z;*/

	ROS_INFO_STREAM("x"<<xyz_iiwa_init.linear.x);
	ROS_INFO_STREAM("y"<<xyz_iiwa_init.linear.y);
	ROS_INFO_STREAM("z"<<xyz_iiwa_init.linear.z);
	ROS_INFO_STREAM("ax"<<roll_iiwa_init);
	ROS_INFO_STREAM("ay"<<pitch_iiwa_init);
	ROS_INFO_STREAM("az"<<yaw_iiwa_init);

}
iiwa_init_rot_in_world.setRPY(xyz_iiwa_init.angular.x,xyz_iiwa_init.angular.y,xyz_iiwa_init.angular.z);
iiwa_init_pos_in_camera = transform(tf::Vector3(xyz_iiwa_init.linear.x,xyz_iiwa_init.linear.y,xyz_iiwa_init.linear.z));
iiwa_init_rot_in_cam=transform*(iiwa_init_rot_in_world);
tf::Matrix3x3(iiwa_init_rot_in_cam).getRPY(iiwa_init_roll_in_cam,iiwa_init_pitch_in_cam,iiwa_init_yaw_in_cam);

while (ros::ok())
{
	if (initialized)
	{
		if(initialized_phantom)
		{
			try{
				listener.lookupTransform("/US_probe_tip222", "/world", ros::Time(0), transform);
				inv_transform = transform.inverse();
			}
			catch (tf::TransformException &ex) {
				ROS_ERROR("%s",ex.what());
				ros::Duration(1.0).sleep();
				continue;
			}



			//Read Joint Positions of Phantom and put them in KDL format
			for (int k = 0; k<nj_phantom; ++k)
			{
				jointpositions_phantom(k) = joints_phantom.position[k];
			}
			//jointpositions_phantom(5)=3;

			//Perform Forward Kinematics To get Cartesian Pose of PHANTOM
			kinematics_status = fksolver_phantom.JntToCart(jointpositions_phantom,cartpos_phantom);
			if(kinematics_status>=0)
			{
				xyz_phantom.linear.x = cartpos_phantom.p[0];
				xyz_phantom.linear.y = cartpos_phantom.p[1];
				xyz_phantom.linear.z = cartpos_phantom.p[2];
				//Get roll, pitch, yaw values
				cartpos_phantom.M.GetRPY(roll_phantom,pitch_phantom, yaw_phantom);
				xyz_phantom.angular.x = roll_phantom;
				xyz_phantom.angular.y = pitch_phantom;
				xyz_phantom.angular.z = yaw_phantom;
				phantom_rpy.publish(xyz_phantom);
				phantom_rot_in_world.setRPY(roll_phantom, pitch_phantom, yaw_phantom);
				phantom_rot_in_cam=transform*phantom_rot_in_world;
				tf::Matrix3x3(phantom_rot_in_cam).getRPY(phantom_roll_in_cam,phantom_pitch_in_cam,phantom_yaw_in_cam);
			}

			// Get LWR joint positions in KDL form
			for (int k = 0; k<7; ++k)
			{
				jointpositions(k) = joints.position[k];

			}
			msg1.data=3;
			pub1.publish(msg1);

			//Perform Forward Kinematics to get Cartesian Pose of LWR
			msg1.data=4;
			pub1.publish(msg1);
			//find where the robot is
			if(!start_loc_available) //if initial position is not known
			{

				msg1.data=5;
				pub1.publish(msg1);
				kinematics_status = fksolver.JntToCart(jointpositions,cartpos);
				if(kinematics_status>=0)
				{

					/*	xyz.linear.x = cartpos.p[0];
					xyz.linear.y = cartpos.p[1];
					xyz.linear.z = cartpos.p[2];*/
					xyz.linear.x=iiwa_pos.pose.position.x;
					xyz.linear.y=iiwa_pos.pose.position.y;
					xyz.linear.z=iiwa_pos.pose.position.z;
					cartpos.M.GetRPY(roll,pitch, yaw);
					xyz.angular.x = roll;
					xyz.angular.y = pitch;
					xyz.angular.z = yaw;
					rob_pose.publish(xyz);
				}

				start_loc_available = true;
			}
			else
			{
				ros::spinOnce();
				kinematics_status = fksolver.JntToCart(jointpositions,cartpos);
				if(kinematics_status>=0)
				{

					xyz.linear.x = cartpos.p[0];
					xyz.linear.y = cartpos.p[1];
					xyz.linear.z = cartpos.p[2];
					cartpos.M.GetRPY(roll,pitch, yaw);
					xyz.angular.x = roll;
					xyz.angular.y = pitch;
					xyz.angular.z = yaw;
					rob_pose.publish(xyz);
				}
				robot_pose_recorder.publish(xyz);

				msg1.data=6;
				pub1.publish(msg1);
				double z_gain = 1;
				ros::spinOnce();
				try{
					listener.lookupTransform("/US_probe_tip222", "/world", ros::Time(0), transform);
					inv_transform = transform.inverse();
				}
				catch (tf::TransformException &ex) {
					ROS_ERROR("%s",ex.what());
					ros::Duration(1.0).sleep();
					continue;
				}
				xyz_command.linear.y = -pos.pose.position.x*1.5;//xyz_phantom.linear.x;
				xyz_command.linear.z =(-pos.pose.position.y)*1.5; //xyz_phantom.linear.z*z_gain;
				xyz_command.linear.x = pos.pose.position.z*1.5;//xyz_phantom.linear.y;

				xyz_command.angular.x=xyz_phantom.angular.x-xyz_phantom_init.angular.x;
				xyz_command.angular.y=xyz_phantom.angular.y-xyz_phantom_init.angular.y;
				xyz_command.angular.z=xyz_phantom.angular.z-xyz_phantom_init.angular.z;

				iiwa_init_pos_in_camera = transform(tf::Vector3(xyz_iiwa_init.linear.x,xyz_iiwa_init.linear.y,xyz_iiwa_init.linear.z));
				ref.linear.x=iiwa_init_pos_in_camera.x()-xyz_command.linear.x;
				ref.linear.y=iiwa_init_pos_in_camera.y()-xyz_command.linear.y;
				ref.linear.z=iiwa_init_pos_in_camera.z()-xyz_command.linear.z;

				iiwa_pos_in_world = inv_transform(tf::Vector3(ref.linear.x,ref.linear.y,ref.linear.z));
				ref.linear.y = iiwa_pos_in_world.y();
				ref.linear.x = iiwa_pos_in_world.x();
				ref.linear.z = iiwa_pos_in_world.z();

				ros::spinOnce();
				try{
					listener2.lookupTransform("/US_probe_tip222", "/world", ros::Time(0), transform2);
					inv_transform2 = transform2.inverse();
				}
				catch (tf::TransformException &ex) {
					ROS_ERROR("%s",ex.what());
					ros::Duration(1.0).sleep();
					continue;
				}


				prev_x_iiwa_position=ref.linear.x;
				prev_y_iiwa_position=ref.linear.y;
				prev_z_iiwa_position=ref.linear.z;
				ROS_INFO_STREAM("NOT blocking");
				ROS_INFO_STREAM(ref.linear.z);

				blocking=0;
				block_msg.data=0;
				blocker.publish(block_msg);



				ref.angular.x = xyz.angular.x+cam_roll;
				ref.angular.y = xyz.angular.y+cam_pitch;//+cam_pitch;
				ref.angular.z = xyz.angular.z;//+cam_yaw;

				cartpos.p[0]=ref.linear.x;//xyz_iiwa_init.linear.x;//
				cartpos.p[1]=ref.linear.y;//xyz_iiwa_init.linear.y;//ref.linear.y;
				cartpos.p[2]=ref.linear.z;//xyz_iiwa_init.linear.z;//ref.linear.z;
				rpy = KDL::Rotation::RPY(ref.angular.x,ref.angular.y,ref.angular.z);


				cartpos.M =rpy;// cartpos_phantom.M;//rpy;
				int ret = iksolver.CartToJnt(jointpositions,cartpos,jointpositions_new);
				ret_solver.data=ret;
				jointpositions_new(6)=jointpositions_new(6)+cam_yaw;
				solver_debug.publish(ret_solver);
				eval_points(pt, jointpositions_new, nj);
				pt.time_from_start = ros::Duration(dt);
				joint_cmd.points[0] = pt;
				joint_cmd.header.stamp = ros::Time::now();
				msg1.data=5;
				pub1.publish(msg1);
				cmd_pub.publish(joint_cmd);
				phantom_joints.publish(phantom_joints_msg);
				kinematics_status = fksolver.JntToCart(jointpositions_new,cartpos_new);
				if(tele_start_msg.data==2)
				{
					ROS_INFO_STREAM("Killing tele_op");
					ros::shutdown();
				}
				if(kinematics_status>=0)
				{
					xyz_new.linear.x = cartpos_new.p[0];
					xyz_new.linear.y = cartpos_new.p[1];
					xyz_new.linear.z = cartpos_new.p[2];
					//Get roll, pitch, yaw values
					cartpos_new.M.GetRPY(roll_new, pitch_new, yaw_new);
					xyz_new.angular.x = roll_new;
					xyz_new.angular.y = pitch_new;
					xyz_new.angular.z = yaw_new;

					/*xyz_new.pose.position.x = cartpos_new.p[0];
					xyz_new.pose.position.y = cartpos_new.p[1];
					xyz_new.pose.position.z = cartpos_new.p[2];
					//Get roll, pitch, yaw values
					cartpos_new.M.GetQuaternion(roll_new, pitch_new, yaw_new, w_new);
					xyz_new.pose.orientation.x = roll_new;
					xyz_new.pose.orientation.y = pitch_new;
					xyz_new.pose.orientation.z = yaw_new;
					xyz_new.pose.orientation.w = w_new;*/

				}
			}
		}
	}
	else
	{
		cmd_pub.publish(joint_cmd);
		msg1.data=9;
		pub1.publish(msg1);

	}
	ros::spinOnce();
	loop_rate.sleep();
}
return 0;
}
