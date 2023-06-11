#include "cDOSIMETRISTA.h"

cDOSIMETRISTA::cDOSIMETRISTA(string nombre, string dni):cPERSONA(nombre,dni) {
	
}


cDOSIMETRISTA::~cDOSIMETRISTA() {

}

void cDOSIMETRISTA::generar_dosis(cPACIENTE paciente) {


}

string cDOSIMETRISTA::to_string() {
	stringstream ss;
	ss << "Dosimetrista " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}
