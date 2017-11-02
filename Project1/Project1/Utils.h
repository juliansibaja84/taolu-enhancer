#include <string>
#include <map>
#ifndef Utils_H
#define Utils_H

class Utils {
	private:
		struct Joints_definitions {
			int NUI_SKELETON_POSITION_HIP_CENTER = 0;
			int NUI_SKELETON_POSITION_SPINE = 1;
			int NUI_SKELETON_POSITION_SHOULDER_CENTER = 2;
			int NUI_SKELETON_POSITION_HEAD = 3;
			int NUI_SKELETON_POSITION_SHOULDER_LEFT = 4;
			int NUI_SKELETON_POSITION_ELBOW_LEFT = 5;
			int NUI_SKELETON_POSITION_WRIST_LEFT = 6;
			int NUI_SKELETON_POSITION_HAND_LEFT = 7;
			int NUI_SKELETON_POSITION_SHOULDER_RIGHT = 8;
			int NUI_SKELETON_POSITION_ELBOW_RIGHT = 9;
			int NUI_SKELETON_POSITION_WRIST_RIGHT = 10;
			int NUI_SKELETON_POSITION_HAND_RIGHT = 11;
			int NUI_SKELETON_POSITION_HIP_LEFT = 12;
			int NUI_SKELETON_POSITION_KNEE_LEFT = 13;
			int NUI_SKELETON_POSITION_ANKLE_LEFT = 14;
			int NUI_SKELETON_POSITION_FOOT_LEFT = 15;
			int NUI_SKELETON_POSITION_HIP_RIGHT = 16;
			int NUI_SKELETON_POSITION_KNEE_RIGHT = 17;
			int NUI_SKELETON_POSITION_ANKLE_RIGHT = 18;
			int NUI_SKELETON_POSITION_FOOT_RIGHT = 19;
		};
	public:
		struct Joint { double x; double y; double z;};
		Joints_definitions JD;
		double calculateAngleProjection(Joint inferior, Joint central, Joint superior);
		double dot(double v[], double u[], int size);
		double norm(double v[], int size);
		Joint str2joint(std::string str);
		Utils::Joint Utils::array2joint(double * a);
		std::map<std::string,std::string> classtointeger;
		double* jointsToAnglesarray(std::string str);
		
};
#endif