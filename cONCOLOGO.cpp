#include "cONCOLOGO.h"

cONCOLOGO::cONCOLOGO(string nombre, string dni) :cPERSONA(nombre, dni) {

}

cONCOLOGO::~cONCOLOGO() {

}

void cONCOLOGO::pasar_lista_espera(cPACIENTE paciente) {

}

void cONCOLOGO::atender_paciente(cPACIENTE paciente) {

}

string cONCOLOGO::to_string() {
	stringstream ss;
	ss << "Oncologo " << this->get_nombre() << ", con DNI: " << this->get_dni() << " y numero de telefono: " << this->get_telefono();
	return ss.str();
}

