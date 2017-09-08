//------------------------------------------------------------------------------
// Proyecto Final PDI
// Autores: 
// Karolay Ardila Salazar
// Julián Sibaja García
// Andrés Simancas Mateus
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Connect2Kinect.h"
#include "resource.h"
#include <strsafe.h>
#include <stdint.h>
#include <string>
#include <sstream>
#include <iostream>


int Connect2Kinect::Initialize()
{
	INuiSensor * pNuiSensor;

	// Look for kinect
	int iSensorCount = 0;
	HRESULT hr = NuiGetSensorCount(&iSensorCount);
	if (FAILED(hr)) {
		return 1;
	}

	// Iterate over the kinects found
	for (int i = 0; i < iSensorCount; ++i) {
		// Create the sensor to check the status, if we can not, move onto the next
		hr = NuiCreateSensorByIndex(i, &pNuiSensor);
		if (FAILED(hr)) {
			continue;
		}

		// Check status, if connected, we can initialize it.
		hr = pNuiSensor->NuiStatus();
		if (S_OK == hr)
		{
			m_pNuiSensor = pNuiSensor;
			break;
		}

		// If this line is reached the sensor was not ok, so release it
		pNuiSensor->Release();
	}

	if (NULL != m_pNuiSensor) {
		// Initialize the Kinect and use it for skeleton and RGB image
		hr = m_pNuiSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON | NUI_INITIALIZE_FLAG_USES_COLOR);
		if (SUCCEEDED(hr)) {
			// Create an event that will be called each time there is data available
			m_hNextSkeletonEvent = CreateEventW(NULL, TRUE, FALSE, NULL);

			// Open a skeleton stream to receive skeleton data
			hr = m_pNuiSensor->NuiSkeletonTrackingEnable(m_hNextSkeletonEvent, 0);
			m_pNuiSensor->NuiImageStreamOpen(
				NUI_IMAGE_TYPE_COLOR,            // Depth camera or rgb camera?
				NUI_IMAGE_RESOLUTION_640x480,    // Image resolution
				0,      // Image stream flags, e.g. near mode
				2,      // Number of frames to buffer
				NULL,   // Event handle
				&(Connect2Kinect::rgbStream));
		}
	}

	if (NULL == m_pNuiSensor || FAILED(hr)) {
		return 2;
	}

	return 0;
};

void Connect2Kinect::Update(int data_type)
{
	if (NULL == m_pNuiSensor)
	{
		return;
	}

	// Access to ProcessData method
	if (WAIT_OBJECT_0 == WaitForSingleObject(m_hNextSkeletonEvent, 0))
	{
		if (data_type == JOINTS_CODE) {
			ProcessData();
		}
		else {
			getDataRGB(Connect2Kinect::p_data);
			char dummy[3 * width * height];

			// Pointer to the first element of array
			char * ini_ptr = &dummy[0];

			// Expand array
			int j;
			//for (int i = 0; i < height; ++i) {
			j = 0;
			for (int k = 0; k < 4 * width * height; k = k + 4) {
				// r,g,b,a,r,g,b,a,...
				dummy[j] = Connect2Kinect::p_data[k];
				dummy[j + 1] = Connect2Kinect::p_data[k + 1];
				dummy[j + 2] = Connect2Kinect::p_data[k + 2];
				j = j + 3;
			}
			fwrite(ini_ptr, sizeof(char), 3 * width * height, stdout);
			fflush(stdout);
			std::cout << std::endl;
			//}
			// [¡] Send to python here [!]
		}
	}
}

void Connect2Kinect::ProcessData(void)
{
	// Create the frame
	NUI_SKELETON_FRAME skeletonFrame = { 0 };
	HRESULT hr = m_pNuiSensor->NuiSkeletonGetNextFrame(0, &skeletonFrame);
	if (FAILED(hr)) {
		return;
	}

	// Smooth the obtained skeleton data
	m_pNuiSensor->NuiTransformSmooth(&skeletonFrame, NULL);

	getData(&skeletonFrame);

	//string Saludo("Successful, we have data\n");
	//std::cout << Saludo;
}

void Connect2Kinect::getData(NUI_SKELETON_FRAME* sframe)
{
	int drop_frame;
	for (int i = 0; i < NUI_SKELETON_COUNT; ++i) {
		const NUI_SKELETON_DATA &skeleton = sframe->SkeletonData[i];

		// Extract skeleton joints
		drop_frame = 0;
		for (int k = 0; k < 20; ++k) {
			Connect2Kinect::x = skeleton.SkeletonPositions[index_joint[k]].x;
			Connect2Kinect::y = skeleton.SkeletonPositions[index_joint[k]].y;
			Connect2Kinect::z = skeleton.SkeletonPositions[index_joint[k]].z;

			if (Connect2Kinect::x != 0 && Connect2Kinect::y != 0 && Connect2Kinect::z != 0) {
				std::ostringstream oss;
				oss << Connect2Kinect::x << "," << Connect2Kinect::y << "," << Connect2Kinect::z << ";";
				Connect2Kinect::datos = oss.str() + Connect2Kinect::datos;
			}
			else {
				drop_frame = 1;
				break;
			}
		}
		//printf(Connect2Kinect::datos);
		if (drop_frame == 0 && !Connect2Kinect::datos.empty()) {
			std::cout << Connect2Kinect::datos << "\n";
		}
		Connect2Kinect::datos = "";
	}
}

int Connect2Kinect::getDataRGB(char *pdata) {
	NUI_IMAGE_FRAME imageFrame;
	NUI_LOCKED_RECT LockedRect; // Pointer to the data
	if (m_pNuiSensor->NuiImageStreamGetNextFrame(Connect2Kinect::rgbStream, 0, &imageFrame) < 0) return 1;
	INuiFrameTexture* texture = imageFrame.pFrameTexture;
	texture->LockRect(0, &LockedRect, NULL, 0);
	// Check if if not empty, if its not the save data into "data"
	if (LockedRect.Pitch != 0)
	{
		BYTE* curr = (BYTE*)LockedRect.pBits;
		BYTE* dataEnd = curr + (width*height) * 4;

		for (int i = 0; i < width*height * 4; ++i) {
			if (((int)*curr) > 216 && ((int)*curr) < 222) {
				pdata[i] = '0' + 255;
			}
			else {
				pdata[i] = '0' + (((int)*curr));
			}
			++curr;
		}
	}
	texture->UnlockRect(0);
	m_pNuiSensor->NuiImageStreamReleaseFrame(Connect2Kinect::rgbStream, &imageFrame);
	return 0;
}
