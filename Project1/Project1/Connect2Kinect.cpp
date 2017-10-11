//------------------------------------------------------------------------------
// Proyecto Final
// Autores: 
// Karolay Ardila Salazar
// Julián Sibaja García
//------------------------------------------------------------------------------
#include "Connect2Kinect.h"

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
	//cli::pin_ptr <HANDLE> ptr = &(Connect2Kinect::rgbStream);
	//static_cast<HANDLE *>(ptr)
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

std::string Connect2Kinect::getData(void)
{
	if (NULL == m_pNuiSensor)
	{
		return Connect2Kinect::datos;
	}
	else {
		// Access to ProcessData method
		if (WAIT_OBJECT_0 == WaitForSingleObject(m_hNextSkeletonEvent, 0))
		{
			// Create the frame
			NUI_SKELETON_FRAME skeletonFrame = { 0 };
			HRESULT hr = m_pNuiSensor->NuiSkeletonGetNextFrame(0, &skeletonFrame);
			if (FAILED(hr)) {
				return Connect2Kinect::datos;
			}

			// Smooth the obtained skeleton data
			m_pNuiSensor->NuiTransformSmooth(&skeletonFrame, NULL);

			getJoints(&skeletonFrame);
			//string Saludo("Successful, we have data\n");
			//std::cout << Saludo;

		}
		return Connect2Kinect::datos;
	}
}

void Connect2Kinect::getJoints(NUI_SKELETON_FRAME* sframe)
{
	int drop_frame;
	Connect2Kinect::datos = "";
	for (int i = 0; i < NUI_SKELETON_COUNT; ++i) {
		//std::cout << "nuevo: "<<i<<" ----------------------------\n";

		const NUI_SKELETON_DATA &skeleton = sframe->SkeletonData[i];
		std::string joints;
		// Extract skeleton joints
		drop_frame = 0;
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
		for (int k = 0; k < 20; ++k) {
			Connect2Kinect::x = skeleton.SkeletonPositions[index_joint[k]].x;
			Connect2Kinect::y = skeleton.SkeletonPositions[index_joint[k]].y;
			Connect2Kinect::z = skeleton.SkeletonPositions[index_joint[k]].z;
			std::ostringstream oss;
			if (Connect2Kinect::x != 0 && Connect2Kinect::y != 0 && Connect2Kinect::z != 0) {

				if (k == 19) {
					
					oss << "'" << Connect2Kinect::x << "," << Connect2Kinect::y << "," << Connect2Kinect::z << "'";
					
				}
				else {
					oss << "'" << Connect2Kinect::x << "," << Connect2Kinect::y << "," << Connect2Kinect::z << "',";
					
				}
				joints = joints + oss.str();
			}
			else {
				drop_frame = 1;
				break;
			}
		}
		if (joints != "") {
			Connect2Kinect::datos = joints;
		}
	}

}

int Connect2Kinect::getDataRGB(array<unsigned char>^ RGBADATA, int without_alpha) {
	if (NULL == m_pNuiSensor)
	{
		return 0;
	}
	NUI_IMAGE_FRAME imageFrame;
	NUI_LOCKED_RECT LockedRect; // Pointer to the data
	if (m_pNuiSensor->NuiImageStreamGetNextFrame(Connect2Kinect::rgbStream, 0, &imageFrame) < 0) return 0;
	INuiFrameTexture* texture = imageFrame.pFrameTexture;

	texture->LockRect(0, &LockedRect, NULL, 0);
	// Check if not empty, if its not the save data into "RGBADATA"
	if (LockedRect.Pitch != 0)
	{
		BYTE* prgba = (BYTE*)LockedRect.pBits;	// Esto de aquí es el puntero hacia la esquína izquierda superior de la imágen
												// (int)*curr accedes a el valor al que apunta el cursor
												// el tamaño total es (width*height)*4 , se ve así las posiciones de memoria R,G,B,A,R,G,B,A...
		INT32 size_stream = width*height * 4;
		//System::Byte DATA[width*height * 3];
		if (without_alpha == 1) {
			// No guardar alpha
			int j = 0;
			for (int i = 0; i < size_stream; i += 4) {
				RGBADATA[j] = *(prgba + i);      // R
				RGBADATA[j + 1] = *(prgba + i + 1);  // G
				RGBADATA[j + 2] = *(prgba + i + 2);  // B
				j += 3;
			}
		}else if (without_alpha == 0) {
			// Guardar alpha
			for (int i = 0; i < size_stream; i++) {
			RGBADATA[i] = *(prgba + i);
			}
		}

		texture->UnlockRect(0);
		m_pNuiSensor->NuiImageStreamReleaseFrame(Connect2Kinect::rgbStream, &imageFrame);
		return 1;
	}
	texture->UnlockRect(0);
	m_pNuiSensor->NuiImageStreamReleaseFrame(Connect2Kinect::rgbStream, &imageFrame);
	return 0;
	
}