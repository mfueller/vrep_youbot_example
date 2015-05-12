//============================================================================
// Name        : RobotManipulation.cpp
// Author      : Matthias
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
using namespace std;
#include "extApi.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <math.h>
#include "vrep/VRepJointInterface.h"

#include <kdl/chain.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolverpos_nr.hpp>

#include <kdl/frames_io.hpp>
#include <kdl/frames.hpp>
#include <kdl/chainiksolverpos_lma.hpp>
#include <kdl/chainiksolverpos_nr_jl.hpp>
#include <kdl/chainiksolvervel_wdls.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainiksolvervel_pinv_givens.hpp>
#include <kdl/chainiksolvervel_pinv_nso.hpp>

#include <Eigen/Core>

const char* connection_ip = "127.0.0.1";
const int connection_port = 19997;

const char* joint_names[] = {
		"arm_joint_1",
		"arm_joint_2",
		"arm_joint_3",
		"arm_joint_4",
		"arm_joint_5",
		"gripper_finger_joint_l",
		"gripper_finger_joint_r"
};

double d2r(double v) {
	return v / 180 * M_PI;
}

int main() {

	double positions[5] = {
		  //some example position
	          //d2r(169),d2r(65),d2r(-152),d2r(102.5),d2r(165)
		  //2.9496, 1.13446, -2.54818, 1.78896, 2.93075 //candle
                  //2.9496, 1.13446, -2.54818, 1.78896, 2.93075
	          //2.94958, 0.01564, -2.59489, 2.38586, 2.93068 // out of view
		  //3.02221, 2.48996, -1.53309, 1.17502, 2.92980 // pre grasping stangding
		  //2.93836, 2.020597, -1.88253, 3.36243, 3.01283 // grasp standing
                  //2.5061, 0.0935881, -2.60509, 1.42038, 2.93033 // tower_right
		  2.71339, 0.156002, -3.15581, 1.04624, 3.09898 //platform_right
		  //2.96494, 0.134162, -2.97261, 0.745996, 3.04407
		  //2.9496, 1.03446, -2.54818, 1.78896, 2.93075
		  //0,0,0,0,0
		  //2.9319, 1.21288, -0.56446, 2.7036, 3.00853
	};

	// connect with V-rep
	VRepJointInterface* jointInterface = new VRepJointInterface(connection_ip, connection_port, joint_names);
	int index[7] = {0, 1, 2, 3, 4, 5, 6};
	double offset[5] = {d2r(-169),d2r(-65),d2r(146),d2r(-102.5),d2r(-165)};

    for (int i=0; i<5;i++) {
		jointInterface->setJointPosition(index[i], positions[i]);
    }

    sleep(2);

    return 0;
}







