#include "cDOSIMETRISTA.h"

cDOSIMETRISTA::cDOSIMETRISTA(string nombre, string dni):cMEDICO(nombre,dni) {
	
}


cDOSIMETRISTA::~cDOSIMETRISTA() {

}

void cDOSIMETRISTA::generar_dosis(cPACIENTE *paciente) {


	for (int i = 0; i < paciente->get_ficha()->get_tumores().size();i++)
	{
		unsigned int dosis;
		dosis = paciente->get_ficha()->get_tumores()[i].get_tratamiento()->ajustar_dosis(paciente->get_ficha()->get_tumores()[i].get_tamanio());
		paciente->get_ficha()->get_tumores()[i].get_tratamiento()->set_dosisPorSesion(dosis);
	}

	return;

}

string cDOSIMETRISTA::to_string() {
	stringstream ss;
	ss << "Dosimetrista " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}
