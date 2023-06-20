#include "cDOSIMETRISTA.h"

cDOSIMETRISTA::cDOSIMETRISTA(string nombre, string dni):nombre(nombre), dni(dni) {
	
}


cDOSIMETRISTA::~cDOSIMETRISTA() {

}

void cDOSIMETRISTA::set_telefono(string telefono)
{
	this->telefono = telefono;
}

string cDOSIMETRISTA::get_telefono()
{
	return this->telefono;
}

string cDOSIMETRISTA::get_nombre()
{
	return this->nombre;
}

string cDOSIMETRISTA::get_dni()
{
	return this->dni;
}

void cDOSIMETRISTA::generar_dosis(cPACIENTE *paciente) {


	for (int i = 0; i < paciente->get_ficha()->get_tumores().size();i++)
	{
		unsigned int dosis;
		dosis = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->ajustar_dosis(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
		paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->set_dosisPorSesion(dosis);
	}

	return;

}

string cDOSIMETRISTA::to_string() {
	stringstream ss;
	ss << "Dosimetrista " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}

ostream& operator<<(ostream& out, cDOSIMETRISTA& dosimetrista)
{
	out << dosimetrista.to_string();
	return out;
}
