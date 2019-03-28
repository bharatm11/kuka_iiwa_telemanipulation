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
* @file kuka.hpp
* @author Bharat Mathur [bharatm11] - driver
* @author Royneal Rayess [royneal] - navigator
* @date 27 Nov 2018
* @copyright 2018 Bharat Mathur, Royneal Rayess
* @brief This file defines the methods for class "kuka" to control a KUKA IIWA
* manipulator using on IIWA_STACK using OROCOS KDL
*/
#ifndef MY_GIT_KITTING_CELL_WS_SRC_KITTING_CELL_INCLUDE_KITTING_CELL_KUKA_HPP_
#define MY_GIT_KITTING_CELL_WS_SRC_KITTING_CELL_INCLUDE_KITTING_CELL_KUKA_HPP_


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

/**
* @brief Class to calculate forward and inverse kinematics for KUKA IIWA
*/

class kuka {
 private:
  int id;
  sensor_msgs::JointState jointsState_;  ///< sensor_msgs::JointState tye
                                ///< variable to read current joint states
  KDL::Chain kinematicChain_;  ///< KDL::Chain type vaiable for robot chain
  unsigned int numJoints_;  ///< unsigned int variable to hold number of
                            ///< kinematic joints
  KDL::JntArray jointPosKdl_;  ///< KDL joint array current for FK
  KDL::JntArray newJointPosKdl_;  ///< KDL joint array new from IK
  KDL::Frame currCartpos_;  ///< KDL::Frame variable for current cartesianpose
  trajectory_msgs::JointTrajectory jointCommands_;
    ///< trajectory_msgs::JointTrajectory variable for final jointCommands
  trajectory_msgs::JointTrajectoryPoint homePos_;

 public:
  /**
   * @brief This is the constructor for the class
   */
  kuka();
  /**
    * @brief This initializes kuka::jointCommands_ to 0.0
    * @param none
    * @return trajectory_msgs::JointTrajectory type variable initialized to robot
    *         joint names, header, and time stamp
    */
  trajectory_msgs::JointTrajectory initializeTrajectoryPoint();
  /**
    * @brief This initializes the home position for the robot
    * @param none
    * @return trajectory_msgs::JointTrajectoryPoint type variable to define
    *         robot's destination
    */
  trajectory_msgs::JointTrajectoryPoint initializeHomePos();
  /**
    * @brief This initializes the variable that takes in the joint values from
    *        the subscriber
    * @param none
    * @return sensor_msgs::JointState variable to hold joint values
    */
  sensor_msgs::JointState initializeJointsSub();
  /**
    * @brief This initializes the joint arrays that are fed to the kinematic
    *        solvers
    * @param none
    * @return initialized joint arrays for KDL solvers
    */
  KDL::JntArray initializeJointsKDL();
  /**
    * @brief This defines the kinematic chain for KDL
    * @param none
    * @return KDL::Chain variable that holds the kinematic chain
    */
  KDL::Chain makeChain();
  /**
    * @brief This normalizes the joint angles after Inverse Kinematics
    * @param the joint array calculated frm inverse kinematics
    * @return trajectory_msgs::JointTrajectoryPoint variable tha holds
    *         joint trajectory point to move the robot to
    */
  trajectory_msgs::JointTrajectoryPoint normalizePoints(KDL::JntArray);
  /**
    * @brief This is the subscriber to read joint values for the robot
    * @param jointsState_ is the variable that holds the current joint values
    * @return void
    * @details
  */
  void getJoints(const sensor_msgs::JointState::ConstPtr& jointsState_);

  /**
    * @brief This performs the inverse kinematics to get joint angles from
    *        cartesian pose
    * @param the cartesian pose
    * @return KDL::JntArray type joint array calculated from IK
    */
  KDL::JntArray evalKinematicsIK(KDL::Frame);

  /**
    * @brief This performs the forward kinematics to get cartesian pose from
    *        joint angles
    * @param none
    * @return KDL::Frame type cartesian pose from FK
    */
  KDL::Frame evalKinematicsFK();

  /**
    * @brief This calculates the number of joints in the chain and also
    *        preallocates jointPosKdl_ and newJointPosKdl_ data members
    * @param none
    * @return number of joints as unsigned int variable
    */
  unsigned int getJointNums();

  /**
    * @brief This forms the JointTrajectory message to whoch the robot is supposed
    *        to move
    * @param JointTrajectoryPoint containing joint angles
    * @return JointTrajectory to drive the robot
    */
  trajectory_msgs::JointTrajectory driveRobot(
                                         trajectory_msgs::JointTrajectoryPoint);
  /**
    * @brief This returns the current joint of the robot
    * @param none
    * @return KDL::JntArray type variable of joint angles
    */
  KDL::JntArray returnCurrJoints();
};

#endif  // MY_GIT_KITTING_CELL_WS_SRC_KITTING_CELL_INCLUDE_KITTING_CELL_KUKA_HPP_
