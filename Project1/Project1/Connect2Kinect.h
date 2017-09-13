#include <string>
#include <strsafe.h>
#include <stdint.h>
#include <string>
#include <sstream>
#include <iostream>
#include "resource.h"
#include "stdafx.h"
#include "NuiApi.h"

#ifndef Connect2Kinect_H
#define Connect2Kinect_H

#define width 640
#define height 480

#define  g_JointThickness 3.0f
#define g_TrackedBoneThickness 6.0f
#define  g_JointThickness 3.0f
#define g_InferredBoneThickness 1.0f
#define N height*width * 3 * 2

class Connect2Kinect {
	// Current Kinect
	INuiSensor * m_pNuiSensor;
	// Handles
	HANDLE m_pSkeletonStreamHandle;
	HANDLE m_hNextSkeletonEvent;
public:
	int Initialize(void);
	std::string getData(void);
	void getJoints(NUI_SKELETON_FRAME* pf);
	BYTE* getDataRGB();
	HANDLE rgbStream;

	int index_joint[20] = {
		NUI_SKELETON_POSITION_HIP_CENTER,
		NUI_SKELETON_POSITION_SPINE,
		NUI_SKELETON_POSITION_SHOULDER_CENTER,
		NUI_SKELETON_POSITION_HEAD,
		NUI_SKELETON_POSITION_SHOULDER_LEFT,
		NUI_SKELETON_POSITION_ELBOW_LEFT,
		NUI_SKELETON_POSITION_WRIST_LEFT,
		NUI_SKELETON_POSITION_HAND_LEFT,
		NUI_SKELETON_POSITION_SHOULDER_RIGHT,
		NUI_SKELETON_POSITION_ELBOW_RIGHT,
		NUI_SKELETON_POSITION_WRIST_RIGHT,
		NUI_SKELETON_POSITION_HAND_RIGHT,
		NUI_SKELETON_POSITION_HIP_LEFT,
		NUI_SKELETON_POSITION_KNEE_LEFT,
		NUI_SKELETON_POSITION_ANKLE_LEFT,
		NUI_SKELETON_POSITION_FOOT_LEFT,
		NUI_SKELETON_POSITION_HIP_RIGHT,
		NUI_SKELETON_POSITION_KNEE_RIGHT,
		NUI_SKELETON_POSITION_ANKLE_RIGHT,
		NUI_SKELETON_POSITION_FOOT_RIGHT
	};
	float x;
	float y;
	float z;
	std::string datos = "";
};
#endif