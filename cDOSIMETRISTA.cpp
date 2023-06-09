#include "cDOSIMETRISTA.h"

cDOSIMETRISTA::cDOSIMETRISTA(string nombre, string dni):cPERSONA(nombre,dni) {
	
}


cDOSIMETRISTA::~cDOSIMETRISTA() {

}

void cDOSIMETRISTA::generar_dosis(cFICHA ficha) {

}

string cDOSIMETRISTA::to_string() {
	stringstream ss;
	ss << "Dosimetrista " << this->get_nombre() << ", con DNI: " << this->get_dni() << " y numero de telefono: " << this->get_telefono();
	return ss.str();
}
