#include "cHOSPITAL.h"

cHOSPITAL::cHOSPITAL(string nombre, string direccion):nombre(nombre), direccion(direccion) {
	this->pacientes = list<cPACIENTE*>(pacientes.begin(), pacientes.end());
}

cHOSPITAL::~cHOSPITAL() {

}

list <cPACIENTE> cHOSPITAL::buscar_por_tratamiento_y_tumor(eRadioterapia tratamiento, eTipoTumor tumor) {

}

list <cPACIENTE> cHOSPITAL::buscar_por_menos_del_5porciento() {

}


string cHOSPITAL::to_string() {
	stringstream ss;
	ss << "El hospital " << this->nombre << ", ubicado en " << this->direccion << " cuenta actualmente con " << this->pacientes.size() << " pacientes." << endl << endl << "Los pacientes son: " << endl;;
	
	list<cPACIENTE*>::iterator it = this->pacientes.begin();
	int i = 0;

	for (it; it != this->pacientes.end(); it++) {
		/*
		ss << (this->pacientes.begin() + i)->get_nombre();
		ss << it->get_nombre();
		*/
	}

	return ss.str();
}

ostream& operator<<(ostream& out, cHOSPITAL& hospital)
{
	out << hospital.to_string();
	return out;
}
