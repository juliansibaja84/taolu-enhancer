#include "Utils.h"
#include <math.h>
#include <string>
#include <iostream>

Utils::Utils() {
	formmap.insert(std::pair<std::string, std::string>("Strike the hearth with fist", "horse-with-separate-palms,bow-with-grip,heart-strike"));
	formmap.insert(std::pair<std::string, std::string>("Brush hand and fist in bow stance", "hit-with-elbows,rush-hand,thrust-fist"));
	formmap.insert(std::pair<std::string, std::string>("Twist body and thrust fist in rest stance", "thrust-fist,circular-hammer-fist,left-fist-rest-stance"));
}

float Utils::calculateAngleProjection(Utils::Joint inferior, Utils::Joint central, Utils::Joint superior) {
	float angle, cos_angle;
	float sup_vector[] = { superior.x - central.x, superior.y - central.y, superior.z - central.z };
	float inf_vector[] = { inferior.x - central.x, inferior.y - central.y, inferior.z - central.z };

	cos_angle = Utils::dot(sup_vector, inf_vector,3) / (Utils::norm(sup_vector,3)*Utils::norm(inf_vector,3));
	angle = acos(cos_angle);

	if (isnan(angle)) { angle = 0; }
	return angle;
}

float Utils::dot(float v[], float u[],int size){
	float result = 0;
	for (int i = 0; i < size; i++) {
		result += v[i] * u[i];
	}
	return result;
}

float Utils::norm(float v[], int size) {
	float result = 0;
	for (int i = 0; i < size; i++) {
		result += pow(v[i],2);
	}
	result = pow(result, 0.5);
	return result;
}

Utils::Joint Utils::str2joint(std::string str) {
	Utils::Joint J;
	int pf = static_cast<int>(str.find(","));
	int pl = static_cast<int>(str.rfind(","));
	J.x = std::stof(str.substr(0, pf));
	J.y = std::stof(str.substr(pf + 1, pl - pf - 1));
	J.z = std::stof(str.substr(pl + 1));
	return J;
}
Utils::Joint Utils::array2joint(float * a) {
	Utils::Joint J;
	J.x = a[0];
	J.y = a[1];
	J.z = a[2];
	return J;
}

float* Utils::jointsToAnglesarray(std::string str, float a[]) {
	float jointsArray[20][3];
	//float a[13];
	int i = 0, idx;
	size_t pos = 0;
	size_t post = 0;
	std::string delimiter = "'";
	std::string token;
	str.pop_back();
	str.erase(0, 1);
	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + 3);
		token.pop_back();
		token.erase(0, 1);
		for (int j = 0; j < 2; j++) {
			post = token.find(",");
			jointsArray[i][j] = strtof((token.substr(0, pos)).c_str(), 0);
			token.erase(0, pos + 1);
		}
		jointsArray[i][2] = strtof(token.c_str(), 0);
		i++;
	}
	str.pop_back();
	str.erase(0, 1);
	for (int j = 0; j < 2; j++) {
		post = str.find(",");
		jointsArray[i][j] = strtof((str.substr(0, pos)).c_str(), 0);
		str.erase(0, pos + 1);
	}
	jointsArray[i][2] = strtod(str.c_str(), NULL);
	Utils::Joint J1, J2, J3;
	// Neck - Head Angle :
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SPINE]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_CENTER]);
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HEAD]);
	a[0] = calculateAngleProjection(J1, J2, J3);
	// Neck - Elbow - Right Angle :
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_CENTER]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_RIGHT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_ELBOW_RIGHT]);
	a[1] = calculateAngleProjection(J1, J2, J3);
	//  Neck-Elbow-Left Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_CENTER]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_LEFT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_ELBOW_LEFT]);
	a[2] = calculateAngleProjection(J1, J2, J3);
	// Elbow-Hand-Right Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_RIGHT]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_ELBOW_RIGHT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HAND_RIGHT]);
	a[3] = calculateAngleProjection(J1, J2, J3);
	// Elbow-Hand-Left Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_LEFT]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_ELBOW_LEFT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HAND_LEFT]);
	a[4] = calculateAngleProjection(J1, J2, J3);
	// Hip-Leg-Right Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_CENTER]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_RIGHT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_KNEE_RIGHT]);
	a[5] = calculateAngleProjection(J1, J2, J3);
	// Hip-Leg-Left Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_CENTER]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_LEFT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_KNEE_LEFT]);
	a[6] = calculateAngleProjection(J1, J2, J3);
	// Leg-Leg-Right Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_RIGHT]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_KNEE_RIGHT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_FOOT_RIGHT]);
	a[7] = calculateAngleProjection(J1, J2, J3);
	// Leg-Leg-Left Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_LEFT]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_KNEE_LEFT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_FOOT_LEFT]);
	a[8] = calculateAngleProjection(J1, J2, J3);
	// Arm-Hip-Right Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_ELBOW_RIGHT]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_RIGHT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_RIGHT]);
	a[9] = calculateAngleProjection(J1, J2, J3);
	// Arm-Hip-Left Angle:
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_ELBOW_LEFT]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_SHOULDER_LEFT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_LEFT]);
	a[10] = calculateAngleProjection(J1, J2, J3);
	// Thigh-Hipline-Right
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_LEFT]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_RIGHT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_KNEE_RIGHT]);
	a[11] = calculateAngleProjection(J1, J2, J3);
	// Thigh-Hipline-Left
	J1 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_RIGHT]);
	J2 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_HIP_LEFT]);
	J3 = array2joint(jointsArray[JD.NUI_SKELETON_POSITION_KNEE_LEFT]);
	a[12] = calculateAngleProjection(J1, J2, J3);

	return a;
}

