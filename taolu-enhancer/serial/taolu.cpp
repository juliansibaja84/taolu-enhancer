#include "Connect2Kinect.h"
#include <iostream>
#include "DBhandle.h"
#include <string>

int main(int argc, char* argv[]) {
	Connect2Kinect cc;
	DBhandle dbh;
	cc.Initialize();
	std::string joints;
	std::cout << "hola" << std::endl;
	while (1) {
		joints = cc.getData();
		if (joints != "") {
			std::cout << joints.c_str() << "\n";
			dbh.saveJoints("'move1',"+ joints);
			dbh.convertJoints2Angles();
		}
	}

	system("pause");
	return 0;
}