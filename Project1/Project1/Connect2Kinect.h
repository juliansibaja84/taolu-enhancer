#include <string>
#include <strsafe.h>
#include <stdint.h>
#include <string>
#include <sstream>
#include <iostream>
#include "resource.h"
#include "stdafx.h"
#include "NuiApi.h"
#include "Utils.h"

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

private:
	Connect2Kinect() {};
	// Current Kinect
	INuiSensor * m_pNuiSensor;
	// Handles
	HANDLE m_pSkeletonStreamHandle;
	HANDLE m_hNextSkeletonEvent;
	HANDLE rgbStream;

public:
	static Connect2Kinect *instance;
	int Initialize(void);	const char * getData(void);
	void getJoints(NUI_SKELETON_FRAME* pf);
	int Connect2Kinect::getDataRGB(BYTE * RGBADATA);
	float x;
	float y;
	float z;
	const char * datos = "";

	static Connect2Kinect getPInstance() {
		if (!instance) {
			instance = new Connect2Kinect;
			(*instance).Initialize();
		}
		return *instance;
	}
};
#endif