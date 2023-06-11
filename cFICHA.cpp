#include "cFICHA.h"

cFICHA::cFICHA() {
	this->dosisAcumTotal = 0;
	this->dosisMax = 0;
	this->fechaProxSesion = 0;
	this->fechaUltimaSesion = 0;
	this->frecuenciaSemanal = 0;
}

cFICHA::~cFICHA() {

}

void cFICHA::set_dosisAcumTotal(unsigned int dosisAcumTotal) {
	this->dosisAcumTotal = dosisAcumTotal;
	return;
}

void cFICHA::set_dosisMax(unsigned int dosisMax) {
	this->dosisMax = dosisMax;
	return;
}



void cFICHA::set_fechaProxSesion(time_t fechaProxSesion) {
	this->fechaProxSesion = fechaProxSesion;
	return;
}

void cFICHA::set_fechaUltimaSesion(time_t fechaUltimaSesion) {
	this->fechaUltimaSesion = fechaUltimaSesion;
	return;
}

void cFICHA::set_frecuenciaSemanal(unsigned int frecuenciaSemanal) {
	this->frecuenciaSemanal = frecuenciaSemanal;
	return;
}

unsigned int cFICHA::get_dosisAcumTotal() {
	return this->dosisAcumTotal;
}

unsigned int cFICHA::get_dosisMax() {
	return this->dosisMax;
}


unsigned int cFICHA::get_frecuenciaSemanal() {
	return this->frecuenciaSemanal;
}

time_t cFICHA::get_fechaUltimaSesion() {
	return this->fechaUltimaSesion;
}

time_t cFICHA::get_fechaProxSesion() {
	return this->fechaProxSesion;
}

string cFICHA::to_string() {
	stringstream ss, ssaux;
	if (this->dosisMax != 0)
	{
		float porcentaje = this->dosisAcumTotal * 100 / this->dosisMax;
		for (int i = 0; i < this->tumores.size();i++) {
			string aux= this->tumores[i].to_string();
			ssaux << "Tumor " << i + 1 << ": " << aux;
		}
		ss << "La dosis maxima es de " << this->dosisMax << ", de la cual se trato un " << porcentaje << "%. La ultima sesion fue el dia " << ctime(&(this->fechaUltimaSesion)) << ". La proxima sesion sera el dia " << ctime(&(this->fechaProxSesion)) << "." << ssaux;
	}
//AGREGAR EX --> tratamiento no comenzado
	return ss.str();
}
	//vector < cTUMOR > tumores;*/

void cFICHA::imprimir() {

}
