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
* @file kuka.cpp
* @author Bharat Mathur [bharatm11] - driver
* @author Royneal Rayess [royneal] - navigator
* @date 27 Nov 2018
* @copyright 2018 Bharat Mathur, Royneal Rayess
* @brief This file implements the methods for class "kuka"
* This class cpp file defines data members and methods applicable for class
* kuka to to control a KUKA IIWA manipulator using on IIWA_STACK using
* OROCOS KDL for forward and inverse kinematics
*/





#include<std_msgs/UInt8.h>
#include<std_msgs/Bool.h>
#include<std_msgs/Float64.h>
#include<std_msgs/Int16.h>
#include<ros/ros.h>
#include<sensor_msgs/JointState.h>
#include<trajectory_msgs/JointTrajectory.h>
#include<trajectory_msgs/JointTrajectoryPoint.h>
#include<kdl/chain.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainiksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainiksolverpos_nr.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include "kuka.hpp"

KDL::Chain kuka::makeChain() {
  // Define LWR chain_
  KDL::Chain chain_;
  // base
  chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::None),
                                   KDL::Frame::DH_Craig1989(0, 0, 0.33989, 0)));
  // joint 1
  chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),
                                   KDL::Frame::DH_Craig1989(0, -M_PI_2, 0, 0)));
  // joint 2
  chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),
                              KDL::Frame::DH_Craig1989(0, M_PI_2, 0.40011, 0)));
  // joint 3
  chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),
                                    KDL::Frame::DH_Craig1989(0, M_PI_2, 0, 0)));
  // joint 4
  chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),
                             KDL::Frame::DH_Craig1989(0, -M_PI_2, 0.40003, 0)));
  // joint 5
  chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),
                                   KDL::Frame::DH_Craig1989(0, -M_PI_2, 0, 0)));
  // joint 6
  chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),
                                    KDL::Frame::DH_Craig1989(0, M_PI_2, 0, 0)));
  // joint 7 (with flange adapter)
  /* chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),
                                    KDL::Frame::DH_Craig1989(0, 0, 0.12597, 0)));*/
 chain_.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ),KDL::Frame::DH_Craig1989(0,0,0.37897,0)));
  kuka::kinematicChain_ = chain_;
  return chain_;
}
//  Calback to get joint angles
void kuka::getJoints(const sensor_msgs::JointState::ConstPtr& msg) {
  for (int i = 0; i < msg->position.size(); ++i) {
    kuka::jointsState_.position[i] = msg->position[i];
  }
}

//  Get joint numbers for the chain
unsigned int kuka::getJointNums() {
  kuka::numJoints_ = kuka::kinematicChain_.getNrOfJoints();
  // initialize joint array
  kuka::jointPosKdl_ = KDL::JntArray(numJoints_);
  // initialize joint array
  kuka::newJointPosKdl_ = KDL::JntArray(numJoints_);
  return kuka::numJoints_;
}
// initialize trajectory point message parameters
trajectory_msgs::JointTrajectory kuka::initializeTrajectoryPoint() {
  // initialize names
  kuka::jointCommands_.joint_names.push_back("iiwa_joint_1");
  kuka::jointCommands_.joint_names.push_back("iiwa_joint_2");
  kuka::jointCommands_.joint_names.push_back("iiwa_joint_3");
  kuka::jointCommands_.joint_names.push_back("iiwa_joint_4");
  kuka::jointCommands_.joint_names.push_back("iiwa_joint_5");
  kuka::jointCommands_.joint_names.push_back("iiwa_joint_6");
  kuka::jointCommands_.joint_names.push_back("iiwa_joint_7");
  // initialize message header
  kuka::jointCommands_.header.seq = 0;
  // initialize message stamo
  //kuka::jointCommands_.header.stamp = ros::Time::now();
  // initialize message frame id
  kuka::jointCommands_.header.frame_id = "";
  return kuka::jointCommands_;
}
// initialize home location
trajectory_msgs::JointTrajectoryPoint kuka::initializeHomePos() {
  for (int i = 0; i < kuka::numJoints_; ++i) {
    if (i == 0)
    kuka::homePos_.positions.push_back(0);
    if (i == 1)
    kuka::homePos_.positions.push_back(0);
    if (i == 2)
    kuka::homePos_.positions.push_back(0);
    if (i == 3)
    kuka::homePos_.positions.push_back(-1.57);
    if (i == 4)
    kuka::homePos_.positions.push_back(0.0);
    if (i == 5)
    kuka::homePos_.positions.push_back(1.57);
    if (i == 6)
    kuka::homePos_.positions.push_back(0);
  }
  kuka::homePos_.time_from_start = ros::Duration(1.0);
  return kuka::homePos_;
}
// initialize kdl joint arrays to 0.2
KDL::JntArray kuka::initializeJointsKDL() {
  for (int i = 0; i < kuka::numJoints_; ++i) {
    kuka::jointPosKdl_(i) = 0.2;
    kuka::newJointPosKdl_(i) = 0.2;
  }
  return kuka::jointPosKdl_;
}
// initialize subscriber variabble to 0.2
sensor_msgs::JointState kuka::initializeJointsSub() {
  for (int i = 0; i < kuka::numJoints_; ++i) {
    kuka::jointsState_.position.push_back(0.2);
  }
  return kuka::jointsState_;
}
// this function formulates the final point the robot has to drive to
trajectory_msgs::JointTrajectory kuka::driveRobot(
                                  trajectory_msgs::JointTrajectoryPoint point) {
  trajectory_msgs::JointTrajectory jointCmd;
  // read subscriber
  ros::spinOnce();
  // give warning (for physical robots)
  ROS_INFO_STREAM("driving");
  // point parameters
  point.time_from_start = ros::Duration(0.1);
  jointCmd.joint_names.push_back("iiwa_joint_1");
  jointCmd.joint_names.push_back("iiwa_joint_2");
  jointCmd.joint_names.push_back("iiwa_joint_3");
  jointCmd.joint_names.push_back("iiwa_joint_4");
  jointCmd.joint_names.push_back("iiwa_joint_5");
  jointCmd.joint_names.push_back("iiwa_joint_6");
  jointCmd.joint_names.push_back("iiwa_joint_7");
  jointCmd.header.seq = 0;
  jointCmd.header.stamp.sec = 0;
  jointCmd.header.stamp = ros::Time::now();
  jointCmd.header.frame_id = kuka::id++;
  // input joint coordinates
  jointCmd.points.push_back(point);
  return jointCmd;
}
// performs forwardr kinematics on the current joint angles
KDL::Frame kuka::evalKinematicsFK() {
  ros::spinOnce();
  // reinitialize chain.
  KDL::Chain chain = kuka::makeChain();
  // initialize solvers
  KDL::ChainFkSolverPos_recursive fksolver =
                                         KDL::ChainFkSolverPos_recursive(chain);
  KDL::Frame cartPos;
  // put joint angles in KDL format
  for (int k = 0; k < numJoints_; ++k) {
    kuka::jointPosKdl_(k) = kuka::jointsState_.position[k];
  }
  // perform FK
  bool status = fksolver.JntToCart(kuka::jointPosKdl_, cartPos);
  kuka::currCartpos_ = cartPos;
  return cartPos;
}
// performs forwardr kinematics on the current joint angles
KDL::JntArray kuka::evalKinematicsIK(KDL::Frame cartpos) {
  // read subscriber
  ros::spinOnce();
  // perform forward kinematics
  kuka::evalKinematicsFK();
  // make chain
  KDL::Chain chain = kuka::makeChain();
  // initiate solvers
  KDL::ChainFkSolverPos_recursive fksolver =
                                         KDL::ChainFkSolverPos_recursive(chain);
  KDL::ChainIkSolverVel_pinv iksolverv = KDL::ChainIkSolverVel_pinv(chain);
  KDL::ChainIkSolverPos_NR iksolver(chain, fksolver, iksolverv, 100, 1e-4);
  // perform IK
  int ret = iksolver.CartToJnt(kuka::jointPosKdl_, cartpos,
                                                         kuka::newJointPosKdl_);
  return kuka::newJointPosKdl_;
}
// this function normalizes the points to robot's joint limits
trajectory_msgs::JointTrajectoryPoint kuka::normalizePoints(
                                                        KDL::JntArray joints) {
  trajectory_msgs::JointTrajectoryPoint point;
  // joints can move between -+: 172,120,172,120,172,120,170
  // double joint_bounds[] = {3.002, 2.0944,3.002, 2.0944,3.002, 2.0944, 3.002};
  for (int i = 0; i < kuka::numJoints_; ++i) {
    while (joints(i) > M_PI) {
      joints(i) -= 2*M_PI;
    }
    while (joints(i) < -M_PI) {
      joints(i) += 2*M_PI;
    }
    point.positions.push_back(joints(i));
  }
  return point;
}
// this is used to return the current joint values from the esubscriber
KDL::JntArray kuka::returnCurrJoints() {
  KDL::JntArray joints;
  joints = kuka::jointPosKdl_;
  return kuka::jointPosKdl_;
}

kuka::kuka() {
  kuka::makeChain();
  kuka::getJointNums();
  kuka::initializeTrajectoryPoint();
  kuka::initializeHomePos();
  kuka::jointPosKdl_ = KDL::JntArray(kuka::numJoints_);
  kuka::newJointPosKdl_ = KDL::JntArray(kuka::numJoints_);
  kuka::initializeJointsKDL();
  kuka::initializeJointsSub();
}
