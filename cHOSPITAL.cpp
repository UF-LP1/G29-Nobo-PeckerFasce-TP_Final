#include "cHOSPITAL.h"

cHOSPITAL::cHOSPITAL(string nombre, string direccion):nombre(nombre), direccion(direccion) {
	this->pacientes = vector<cPACIENTE>(pacientes.begin(), pacientes.end());
}

cHOSPITAL::~cHOSPITAL() {

}

list <cPACIENTE> cHOSPITAL::buscar_por_tratamiento_y_tumor(eRadioterapia tratamiento, eTipoTumor tumor) {

}

list <cPACIENTE> cHOSPITAL::buscar_por_menos_del_5porciento() {

}

void cHOSPITAL::imprimirListado() {

}

string cHOSPITAL::to_string() {
	stringstream ss;
	ss << "El hospital " << this->nombre << ", ubicado en " << this->direccion << " cuenta actualmente con " << this->pacientes.size() << " pacientes.";
	return ss.str();
}

ostream& operator<<(ostream& out, cHOSPITAL& hospital)
{
	out << hospital.to_string();
	return out;
}
