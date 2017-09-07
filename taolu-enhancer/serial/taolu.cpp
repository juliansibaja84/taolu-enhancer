#include "Connect2Kinect.h"
#include <iostream>
#include <string>

#define STANDBY_CODE 0
#define JOINTS_CODE 1
#define RGB_CODE 2

int py_message = RGB_CODE;

int main(int argc, char* argv[]) {
	Connect2Kinect cc;
	int ini = cc.Initialize();

	if (ini == 1) {
		std::string Fail1("No se ha encontrado kinect");
		std::cout << Fail1;
	}
	else if (ini == 2) {
		std::string Fail("No se encuentra disponible Kinect");
		std::cout << Fail;
	}
	else if (ini == 0) {
		std::string Saludo("Conexion exitosa\n");
		std::cout << Saludo;


		while (1) {
			if (py_message == STANDBY_CODE) {
				// :v pos no hago nada
			}
			else if (py_message == JOINTS_CODE) {
				cc.Update(JOINTS_CODE);
			}
			else if (py_message == RGB_CODE) {
				cc.Update(RGB_CODE);
			}
			if (py_message == JOINTS_CODE) { py_message = RGB_CODE; }
			else if (py_message == RGB_CODE) { py_message = JOINTS_CODE; }
		}
	}

	return 0;
}