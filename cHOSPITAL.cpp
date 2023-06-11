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

}

void cHOSPITAL::imprimir() {

}
