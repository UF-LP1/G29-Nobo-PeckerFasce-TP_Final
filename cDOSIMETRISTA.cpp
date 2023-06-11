#include "cDOSIMETRISTA.h"
#include <ctime>

cDOSIMETRISTA::cDOSIMETRISTA(string nombre, string dni):cPERSONA(nombre,dni) {
	
}


cDOSIMETRISTA::~cDOSIMETRISTA() {

}

void cDOSIMETRISTA::generar_dosis(cPACIENTE paciente) {
	srand(time(NULL));

	for (int i = 0; i < ; i++)
	{

	}


}

string cDOSIMETRISTA::to_string() {
	stringstream ss;
	ss << "Dosimetrista " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}
