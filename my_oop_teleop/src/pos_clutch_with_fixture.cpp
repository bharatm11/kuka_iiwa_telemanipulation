/*
*                     GNU LESSER GENERAL PUBLIC LICENSE
*                         Version 3, 29 June 2007
*
*   Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
*   Everyone is permitted to copy and distribute verbatim copies
*   of this license document, but changing it is not allowed.
*
*   This version of the GNU Lesser General Public License incorporates
* the terms and conditions of version 3 of the GNU General Public
* License, supplemented by the additional permissions listed below.
*
*   0. Additional Definitions.
*
*   As used herein, "this License" refers to version 3 of the GNU Lesser
* General Public License, and the "GNU GPL" refers to version 3 of the GNU
* General Public License.
*
*   "The Library" refers to a covered work governed by this License,
* other than an Application or a Combined Work as defined below.
*
*   An "Application" is any work that makes use of an interface provided
* by the Library, but which is not otherwise based on the Library.
* Defining a subclass of a class defined by the Library is deemed a mode
* of using an interface provided by the Library.
*
*   A "Combined Work" is a work produced by combining or linking an
* Application with the Library.  The particular version of the Library
* with which the Combined Work was made is also called the "Linked
* Version".
*
*   The "Minimal Corresponding Source" for a Combined Work means the
* Corresponding Source for the Combined Work, excluding any source code
* for portions of the Combined Work that, considered in isolation, are
* based on the Application, and not on the Linked Version.
*
*   The "Corresponding Application Code" for a Combined Work means the
* object code and/or source code for the Application, including any data
* and utility programs needed for reproducing the Combined Work from the
* Application, but excluding the System Libraries of the Combined Work.
*
*   1. Exception to Section 3 of the GNU GPL.
*
*   You may convey a covered work under sections 3 and 4 of this License
* without being bound by section 3 of the GNU GPL.
*
*   2. Conveying Modified Versions.
*
*   If you modify a copy of the Library, and, in your modifications, a
* facility refers to a function or data to be supplied by an Application
* that uses the facility (other than as an argument passed when the
* facility is invoked), then you may convey a copy of the modified
* version:
*
*    a) under this License, provided that you make a good faith effort to
*    ensure that, in the event an Application does not supply the
*    function or data, the facility still operates, and performs
*    whatever part of its purpose remains meaningful, or
*
*    b) under the GNU GPL, with none of the additional permissions of
*    this License applicable to that copy.
*
*   3. Object Code Incorporating Material from Library Header Files.
*
*   The object code form of an Application may incorporate material from
* a header file that is part of the Library.  You may convey such object
* code under terms of your choice, provided that, if the incorporated
* material is not limited to numerical parameters, data structure
* layouts and accessors, or small macros, inline functions and templates
* (ten or fewer lines in length), you do both of the following:
*
*    a) Give prominent notice with each copy of the object code that the
*    Library is used in it and that the Library and its use are
*    covered by this License.
*
*    b) Accompany the object code with a copy of the GNU GPL and this license
*    document.
*
*   4. Combined Works.
*
*   You may convey a Combined Work under terms of your choice that,
* taken together, effectively do not restrict modification of the
* portions of the Library contained in the Combined Work and reverse
* engineering for debugging such modifications, if you also do each of
* the following:
*
*    a) Give prominent notice with each copy of the Combined Work that
*    the Library is used in it and that the Library and its use are
*    covered by this License.
*
*    b) Accompany the Combined Work with a copy of the GNU GPL and this license
*    document.
*
*    c) For a Combined Work that displays copyright notices during
*    execution, include the copyright notice for the Library among
*    these notices, as well as a reference directing the user to the
*    copies of the GNU GPL and this license document.
*
*    d) Do one of the following:
*
*        0) Convey the Minimal Corresponding Source under the terms of this
*        License, and the Corresponding Application Code in a form
*        suitable for, and under terms that permit, the user to
*        recombine or relink the Application with a modified version of
*        the Linked Version to produce a modified Combined Work, in the
*        manner specified by section 6 of the GNU GPL for conveying
*        Corresponding Source.
*
*        1) Use a suitable shared library mechanism for linking with the
*        Library.  A suitable mechanism is one that (a) uses at run time
*        a copy of the Library already present on the user's computer
*        system, and (b) will operate properly with a modified version
*        of the Library that is interface-compatible with the Linked
*        Version.
*
*    e) Provide Installation Information, but only if you would otherwise
*    be required to provide such information under section 6 of the
*    GNU GPL, and only to the extent that such information is
*    necessary to install and execute a modified version of the
*    Combined Work produced by recombining or relinking the
*    Application with a modified version of the Linked Version. (If
*    you use option 4d0, the Installation Information must accompany
*    the Minimal Corresponding Source and Corresponding Application
*    Code. If you use option 4d1, you must provide the Installation
*    Information in the manner specified by section 6 of the GNU GPL
*    for conveying Corresponding Source.)
*
*   5. Combined Libraries.
*
*   You may place library facilities that are a work based on the
* Library side by side in a single library together with other library
* facilities that are not Applications and are not covered by this
* License, and convey such a combined library under terms of your
* choice, if you do both of the following:
*
*    a) Accompany the combined library with a copy of the same work based
*    on the Library, uncombined with any other library facilities,
*    conveyed under the terms of this License.
*
*    b) Give prominent notice with the combined library that part of it
*    is a work based on the Library, and explaining where to find the
*    accompanying uncombined form of the same work.
*
*   6. Revised Versions of the GNU Lesser General Public License.
*
*   The Free Software Foundation may publish revised and/or new versions
* of the GNU Lesser General Public License from time to time. Such new
* versions will be similar in spirit to the present version, but may
* differ in detail to address new problems or concerns.
*
*   Each version is given a distinguishing version number. If the
* Library as you received it specifies that a certain numbered version
* of the GNU Lesser General Public License "or any later version"
* applies to it, you have the option of following the terms and
* conditions either of that published version or of any later version
* published by the Free Software Foundation. If the Library as you
* received it does not specify a version number of the GNU Lesser
* General Public License, you may choose any version of the GNU Lesser
* General Public License ever published by the Free Software Foundation.
*
*   If the Library as you received it specifies that a proxy can decide
* whether future versions of the GNU Lesser General Public License shall
* apply, that proxy's public statement of acceptance of any version is
* permanent authorization for you to choose that version for the
* Library.
*/
/**
* @file main.cpp
* @author Bharat Mathur [bharatm11]
* @author Royneal Rayess [royneal]
* @date 15 Dec 2018
* @copyright 2018 Bharat Mathur, Royneal Rayess
* @brief This is the main file of the kitting_cell package to perform color
*        based kitting of items with a KUKA IIWA manipulator equipped with a vacuum gripper.
*/

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


#include <kdl/chainfksolver.hpp>
#include <kdl/chainiksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainiksolverpos_nr.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include "kuka.hpp"
#include "phantom.hpp"


// =============================================================================
//  Force subscribers
// =============================================================================
geometry_msgs::WrenchStamped ft;
void get_forces(const geometry_msgs::WrenchStamped & _fdata) {
  ft = _fdata;
}
geometry_msgs::WrenchStamped compensated_ft;
void get_compensated_forces(const geometry_msgs::WrenchStamped & _fdata2) {
  compensated_ft = _fdata2;
}

// =============================================================================
// Omni Button Subscriber
// =============================================================================
omni_msgs::OmniButtonEvent button;
omni_msgs::OmniButtonEvent prev_button;
bool control_mode = false;
bool prev_control_mode = false;
int pos_gain=0;
int or_gain=0;
bool button_init = false;
void get_button(const omni_msgs::OmniButtonEvent & _data){
  button = _data;
  // check if the control mode has changed via the grey button
  if(button.grey_button == 1 && prev_button.grey_button == 0){
    ROS_INFO_STREAM("control_mode = true");
    pos_gain=0;
    or_gain=1;
    button_init = true;
    control_mode = true;
  } else if(button.grey_button == 0 && prev_button.grey_button == 1) {
    ROS_INFO_STREAM("control_mode = false");
    pos_gain=1.5;
    or_gain=0;
    button_init = true;
    control_mode = false;
  }
  prev_button = button;
}

int main(int argc, char **argv) {
  // ===========================================================================
  // ROS Things
  // ===========================================================================
  ros::init(argc, argv, "kuka");
  ros::NodeHandle n;
  ros::NodeHandle nh;
  kuka ku;  ///< kuka class object
  phantom omni;  ///< phantom class object
  int loop_freq = 1000;
  float dt = static_cast<float>(1/loop_freq);
  ros::Rate loop_rate(loop_freq);
  ros::Duration(5).sleep();
  auto joints_sub = n.subscribe("/iiwa/joint_states", 10,&kuka::getJoints, &ku);
  //Define Subscriber to Read Phantom Joints
  auto joints_phantom_sub = n.subscribe("/phantom/joint_states",10, &phantom::getJoints,&omni);
  //Define Subscriber to Read Phantom Pose
  auto pos_sub = n.subscribe("/phantom/pose",10, &phantom::get_pos,&omni);
  std::string command_topic ="/iiwa/PositionJointInterface_trajectory_controller/command";
  ros::Publisher cmd_pub =  n.advertise<trajectory_msgs::JointTrajectory>(command_topic, 1);
  ros::Subscriber button_sub = n.subscribe("/phantom/button",10, get_button);
  auto iiwa_fk =  n.advertise<geometry_msgs::Twist>("/iiwa_fk", 1);
  ros::Subscriber forces_sub = n.subscribe("/ft18215",10, get_forces);
  ros::Subscriber compensated_forces_sub = n.subscribe("/compensated_forces_ft_frame",10, get_compensated_forces);
  // =============================================================================

  // Global Variables
  // =============================================================================
  KDL::JntArray newJoints;  ///< from IK
  KDL::JntArray currOmniJoints;  ///< current phantom joints
  KDL::JntArray prevPhantomJoints;  ///< previous phantom joints
  trajectory_msgs::JointTrajectory cmd;  ///< final command to robot
  geometry_msgs::PoseStamped phantom_pose;  ///< pose from driver. overwriting positions from FK
  KDL::Frame phantomInitCartPos;  ///< phantom initial cartpos - used for computation
  KDL::Frame iiwaInitCartPos;  ///< IIWA initial cartpos - used for computation
  KDL::Frame iiwaCurrCartPos;  ///< IIWA current cartpos - used for computation
  KDL::Frame phantomCurrCartPos;  ///< Phantom current cartpos - used for computation
  KDL::Frame refCartPos;  ///< Command cartpos - from computation
  KDL::Rotation rpy;          ///<  rotation matrix used for compiling commands
  geometry_msgs::Twist xyzPhantomInit;  ///< phantom initial orientations in angula - used for computation
  geometry_msgs::Twist xyzPhantomCurr;  ///< phantom current orientations in angula - used for computation
  geometry_msgs::Twist xyzIIWAInit;  ///< IIWA initial orientations in angula - used for computation
  geometry_msgs::Twist xyzIIWACurr;  ///< IIWA current orientations in angula - used for computation
  geometry_msgs::Twist xyzCommand;  ///< IIWA commands - used for computation
  geometry_msgs::Twist xyzRef;  ///< equivalent of ref. Fed to output Cartpos for IK
  geometry_msgs::Twist xyzIIWAPrev;  ///< IIWA Prev Cartpos
  geometry_msgs::Twist xyzCommandsPrev;  ///< previous commands for clutch
  tf::TransformListener listener;  ///<  TF listener
  tf::StampedTransform transform;  ///<  TF transform
  tf::Transform inv_transform;  ///<  TF transform inverse
  tf::Quaternion iiwa_init_rot_in_world;  ///<  IIWA initial orientation in world
  tf::Quaternion iiwa_init_rot_in_cam;  ///<  IIWA initial orientation in camera
  tf::Quaternion rot_in_world;
  tf::Quaternion rot_in_cam;
  tf::Vector3 iiwa_init_pos_in_camera;  ///<  IIWA initial position in camera
  tf::Vector3 iiwa_pos_in_world_v3;  ///<  IIWA position in world for transform
  tf::Vector3 iiwa_in_world_before_blocking_v3;  ///<  IIWA position in world before blocking
  tf::Vector3 iiwa_prev_in_cam_before_blocking_v3;  ///<  IIWA position in camera before blocking
  double iiwa_init_roll_in_cam,iiwa_init_pitch_in_cam,iiwa_init_yaw_in_cam;  ///<  IIWA initial orientation RPY in camera
  double iiwa_roll_in_cam,iiwa_pitch_in_cam,iiwa_yaw_in_cam;
  bool blocking = 0;  ///< flag for blocking
  // =============================================================================
  // Drive Home
  // =============================================================================
  ros::Duration(1).sleep();
  ros::spinOnce();
  cmd = ku.driveRobot(ku.initializeHomePos());
  cmd_pub.publish(cmd);
  ros::Duration(3).sleep();
  // =============================================================================
  //  Read transform
  // =============================================================================
  try{
    listener.lookupTransform("/US_probe_tip222", "/world", ros::Time(0), transform);
    inv_transform = transform.inverse();
  }
  catch (tf::TransformException &ex) {
    ROS_ERROR("%s",ex.what());
    ros::Duration(1.0).sleep();
  }
  // =============================================================================
  //   Phantom Init Cartpos (mix of FK and pose from driver)
  // =============================================================================
  prevPhantomJoints = omni.returnCurrJoints();
  phantomInitCartPos=omni.evalKinematicsFK();
  phantomInitCartPos.M.GetRPY(xyzPhantomInit.angular.x,xyzPhantomInit.angular.y,xyzPhantomInit.angular.z);
  phantom_pose=omni.returnCurrPose();
  phantomInitCartPos.p[0] = phantom_pose.pose.position.x;
  phantomInitCartPos.p[1] = phantom_pose.pose.position.y;
  phantomInitCartPos.p[2] = phantom_pose.pose.position.z;
  // =============================================================================
  //  IIWA Init Cartpos  (from FK)
  // =============================================================================
  iiwaInitCartPos = ku.evalKinematicsFK();
  iiwaInitCartPos.M.GetRPY(xyzIIWAInit.angular.x,xyzIIWAInit.angular.y,xyzIIWAInit.angular.z);
  // Init IIWA Prev
  iiwaInitCartPos.M.GetRPY(xyzIIWAPrev.angular.x,xyzIIWAPrev.angular.y,xyzIIWAPrev.angular.z);
  // ===========================================================================
  //   Convert IIWA Init to Camera Frame
  // ===========================================================================
  iiwa_init_rot_in_world.setRPY(xyzIIWAInit.angular.x,xyzIIWAInit.angular.y,xyzIIWAInit.angular.z);
  iiwa_init_pos_in_camera = transform(tf::Vector3(iiwaInitCartPos.p[0],iiwaInitCartPos.p[1],iiwaInitCartPos.p[2]));
  iiwa_init_rot_in_cam=transform*(iiwa_init_rot_in_world);
  tf::Matrix3x3(iiwa_init_rot_in_cam).getRPY(iiwa_init_roll_in_cam,iiwa_init_pitch_in_cam,iiwa_init_yaw_in_cam);
  // ===========================================================================
  // Initialize previous
  // ===========================================================================
  xyzCommandsPrev.linear.x = 0;
  xyzCommandsPrev.linear.y = 0;
  xyzCommandsPrev.linear.z = 0;
  xyzCommandsPrev.angular.x = 0;
  xyzCommandsPrev.angular.y = 0;
  // ===========================================================================
  // MAIN LOOP
  // ===========================================================================
  ROS_INFO_STREAM("Initialize Button");
  bool initWait = false;
  while (ros::ok()) {
    if(button_init) {
      if(!initWait) {
        ROS_INFO_STREAM("Starting!!!! Get Ready");
        ros::Duration(3).sleep();
        initWait = true;
      }
      ros::spinOnce();

      // =========================================================================
      //  Read transform
      // =========================================================================
      try{
        listener.lookupTransform("/US_probe_tip222", "/world", ros::Time(0), transform);
        inv_transform = transform.inverse();
      }
      catch (tf::TransformException &ex) {
        ROS_ERROR("%s",ex.what());
        ros::Duration(1.0).sleep();
      }

      if(prev_control_mode!=control_mode){
        ROS_ERROR("SWITCH");
        // =============================================================================
        //  IIWA Init Cartpos  (from FK)
        // =============================================================================
        iiwaInitCartPos = ku.evalKinematicsFK();
        iiwaInitCartPos.M.GetRPY(xyzIIWAInit.angular.x,xyzIIWAInit.angular.y,xyzIIWAInit.angular.z);
        // ===========================================================================
        //   Convert IIWA Init to Camera Frame
        // ===========================================================================
        iiwa_init_rot_in_world.setRPY(xyzIIWAInit.angular.x,xyzIIWAInit.angular.y,xyzIIWAInit.angular.z);
        iiwa_init_pos_in_camera = transform(tf::Vector3(iiwaInitCartPos.p[0],iiwaInitCartPos.p[1],iiwaInitCartPos.p[2]));
        iiwa_init_rot_in_cam=transform*(iiwa_init_rot_in_world);
        tf::Matrix3x3(iiwa_init_rot_in_cam).getRPY(iiwa_init_roll_in_cam,iiwa_init_pitch_in_cam,iiwa_init_yaw_in_cam);
      }
      // =============================================================================
      //   Phantom Curr Cartpos (mix of FK and pose from driver)
      // =============================================================================
      phantomCurrCartPos=omni.evalKinematicsFK();
      phantomCurrCartPos.M.GetRPY(xyzPhantomCurr.angular.x,xyzPhantomCurr.angular.y,xyzPhantomCurr.angular.z);
      phantom_pose=omni.returnCurrPose();
      phantomCurrCartPos.p[0] = phantom_pose.pose.position.x;
      phantomCurrCartPos.p[1] = phantom_pose.pose.position.y;
      phantomCurrCartPos.p[2] = phantom_pose.pose.position.z;
      // =============================================================================
      //  IIWA Current Cartpos  (from FK)
      // =============================================================================
      iiwaCurrCartPos = ku.evalKinematicsFK();
      iiwaCurrCartPos.M.GetRPY(xyzIIWACurr.angular.x,xyzIIWACurr.angular.y,xyzIIWACurr.angular.z);

      // =======================================================================
      // Computation
      // =======================================================================

      if((blocking==0)&&(sqrt(compensated_ft.wrench.force.x*compensated_ft.wrench.force.x+compensated_ft.wrench.force.y*compensated_ft.wrench.force.y+compensated_ft.wrench.force.z*compensated_ft.wrench.force.z)<7)) {
        ROS_INFO_STREAM("NOT blocking");
        // =======================================================================
        // For position control
        // =======================================================================
        if(pos_gain>0) {
          //  Phantom positions become linear commands. gain 1.50
          xyzCommand.linear.x = (phantomCurrCartPos.p[0]) - xyzCommandsPrev.linear.x ;
          xyzCommand.linear.z = -(phantomCurrCartPos.p[1]) + xyzCommandsPrev.linear.z;
          xyzCommand.linear.y = -(phantomCurrCartPos.p[2]) + xyzCommandsPrev.linear.y;

          // =======================================================================
          // Get IIWA init cartpos(positions) in current camera frame
          iiwa_init_pos_in_camera = transform(tf::Vector3(iiwaInitCartPos.p[0],iiwaInitCartPos.p[1],iiwaInitCartPos.p[2]));
          // =======================================================================

          // =======================================================================
          // xyzRef = init in cam + command. Commands are added to initial camera frame
          xyzRef.linear.x = iiwa_init_pos_in_camera.x()+xyzCommand.linear.y;
          xyzRef.linear.y = iiwa_init_pos_in_camera.y()+xyzCommand.linear.x;
          xyzRef.linear.z = iiwa_init_pos_in_camera.z()-xyzCommand.linear.z;
          // =======================================================================

          // =============================================================================
          //  Save iiwa position in world before blocking
          iiwa_in_world_before_blocking_v3 = inv_transform(tf::Vector3(xyzRef.linear.x,xyzRef.linear.y,xyzRef.linear.z));
          // =============================================================================


          // =======================================================================
          // Overwrite prev positions
          xyzIIWAPrev.linear.x= xyzRef.linear.x;
          xyzIIWAPrev.linear.y= xyzRef.linear.y;
          xyzIIWAPrev.linear.z= xyzRef.linear.z;
          prevPhantomJoints = omni.returnCurrJoints();
          xyzCommandsPrev.angular.x =  prevPhantomJoints(3);
          xyzCommandsPrev.angular.y =  prevPhantomJoints(4);
          // =======================================================================

          // =======================================================================
          // Keep previous orientation
          xyzRef.angular.x=xyzIIWAPrev.angular.x;
          xyzRef.angular.y=xyzIIWAPrev.angular.y;
          xyzRef.angular.z=xyzIIWAPrev.angular.z;
          // =======================================================================
        }
        blocking=0;
      } else {
        blocking=1;
        // =======================================================================
        // For position control
        // =======================================================================
        if(pos_gain>0) {
          //  Phantom positions become linear commands. gain 1.50
          xyzCommand.linear.x = (phantomCurrCartPos.p[0]) - xyzCommandsPrev.linear.x ;
          xyzCommand.linear.z = -(phantomCurrCartPos.p[1]) + xyzCommandsPrev.linear.z;
          xyzCommand.linear.y = -(phantomCurrCartPos.p[2]) + xyzCommandsPrev.linear.y;

          // =======================================================================
          // Get IIWA prev position before blocking in current camera frame
          iiwa_prev_in_cam_before_blocking_v3 = transform(iiwa_in_world_before_blocking_v3);
          // =======================================================================

          // =======================================================================
          // Get IIWA init cartpos(positions) in current camera frame
          iiwa_init_pos_in_camera = transform(tf::Vector3(iiwaInitCartPos.p[0],iiwaInitCartPos.p[1],iiwaInitCartPos.p[2]));
          // =======================================================================

          // =======================================================================
          // xyzRef = init in cam + command. Commands are added to initial camera frame
          xyzRef.linear.x = iiwa_init_pos_in_camera.x()+xyzCommand.linear.y;
          xyzRef.linear.y = iiwa_init_pos_in_camera.y()+xyzCommand.linear.x;
          xyzRef.linear.z = iiwa_init_pos_in_camera.z()-xyzCommand.linear.z;
          // =======================================================================

          if(iiwa_prev_in_cam_before_blocking_v3.z()<xyzRef.linear.z) {
            xyzRef.linear.x=iiwa_prev_in_cam_before_blocking_v3.x();
            xyzRef.linear.y=iiwa_prev_in_cam_before_blocking_v3.y();
            xyzRef.linear.z=iiwa_prev_in_cam_before_blocking_v3.z();
            ROS_INFO_STREAM("going down");
          } else {
            blocking=0;
          }
          ROS_INFO_STREAM("blocking");
          // =======================================================================
          // Overwrite prev positions
          xyzIIWAPrev.linear.x= xyzRef.linear.x;
          xyzIIWAPrev.linear.y= xyzRef.linear.y;
          xyzIIWAPrev.linear.z= xyzRef.linear.z;
          prevPhantomJoints = omni.returnCurrJoints();
          xyzCommandsPrev.angular.x =  prevPhantomJoints(3);
          xyzCommandsPrev.angular.y =  prevPhantomJoints(4);
          // =======================================================================

          // =======================================================================
          // Keep previous orientation
          xyzRef.angular.x=xyzIIWAPrev.angular.x;
          xyzRef.angular.y=xyzIIWAPrev.angular.y;
          xyzRef.angular.z=xyzIIWAPrev.angular.z;
          // =======================================================================
        }
      }
      // =============================================================================
      // For orientation control
      // =============================================================================
      if(or_gain>0) {
        // Angular commands
        ros::spinOnce();
        currOmniJoints = omni.returnCurrJoints();
        rot_in_world.setRPY(xyzIIWACurr.angular.x,xyzIIWACurr.angular.y,xyzIIWACurr.angular.z);
        rot_in_cam = transform*(iiwa_init_rot_in_world);
        tf::Matrix3x3(rot_in_cam).getRPY(iiwa_roll_in_cam,iiwa_pitch_in_cam,iiwa_yaw_in_cam);
        xyzRef.angular.x = iiwa_roll_in_cam +(currOmniJoints(3)*or_gain) - xyzCommandsPrev.angular.x;
        xyzRef.angular.y = iiwa_pitch_in_cam -(currOmniJoints(4)*or_gain) +xyzCommandsPrev.angular.y;//(xyzPhantomCurr.angular.y*or_gain);
        xyzRef.angular.z = iiwa_yaw_in_cam;
        rot_in_cam.setRPY(xyzRef.angular.x,xyzRef.angular.y,xyzRef.angular.z);
        rot_in_world = inv_transform*(rot_in_cam);
        tf::Matrix3x3(rot_in_world).getRPY(xyzRef.angular.x,xyzRef.angular.y,xyzRef.angular.z);


        xyzIIWAPrev.angular.x=xyzRef.angular.x;
        xyzIIWAPrev.angular.y=xyzRef.angular.y;
        xyzIIWAPrev.angular.z=xyzRef.angular.z;
        phantom_pose=omni.returnCurrPose();
        xyzCommandsPrev.linear.x = phantom_pose.pose.position.x;
        xyzCommandsPrev.linear.z = phantom_pose.pose.position.y;
        xyzCommandsPrev.linear.y = phantom_pose.pose.position.z;

        // Keep previous position
        xyzRef.linear.x = xyzIIWAPrev.linear.x;
        xyzRef.linear.y = xyzIIWAPrev.linear.y;
        xyzRef.linear.z = xyzIIWAPrev.linear.z;
      }
      // =======================================================================
      // Convert xyzRef to world frame
      // =======================================================================
      iiwa_pos_in_world_v3 = inv_transform(tf::Vector3(xyzRef.linear.x,xyzRef.linear.y,xyzRef.linear.z));
      // Overwrite ref linear to ref linear in world frame
      xyzRef.linear.x = iiwa_pos_in_world_v3.x();
      xyzRef.linear.y = iiwa_pos_in_world_v3.y();
      xyzRef.linear.z = iiwa_pos_in_world_v3.z();

      // Compile xyzRef into refCartPos
      refCartPos.p[0] = xyzRef.linear.x;
      refCartPos.p[1] = xyzRef.linear.y;
      refCartPos.p[2] = xyzRef.linear.z;

      rpy = KDL::Rotation::RPY(xyzRef.angular.x,xyzRef.angular.y,xyzRef.angular.z);
      iiwa_fk.publish(xyzRef);
      refCartPos.M = rpy;
      // =======================================================================
      // =======================================================================
      // IK and send to robot
      newJoints = ku.evalKinematicsIK(refCartPos);
      double a = omni.returnlastJoints();
      newJoints(6) = a;
      cmd = ku.driveRobot(ku.normalizePoints(newJoints));
      cmd_pub.publish(cmd);
      // =======================================================================

      ros::spinOnce();
      loop_rate.sleep();

      prev_control_mode = control_mode;
    }
    ros::spinOnce();
  }

  return 0;
}
