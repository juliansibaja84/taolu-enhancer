#include "Utils.h"
#include <math.h>
#include <string>
#include <iostream>

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