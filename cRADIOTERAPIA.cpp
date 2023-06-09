#include "cRADIOTERAPIA.h"

cRADIOTERAPIA::cRADIOTERAPIA(eRadioterapia tratamiento):tratamiento(tratamiento) {
	this->dosisPorSesion = 0;
	this->frecuenciaSemanalPorTumor = 0;
}

cRADIOTERAPIA::~cRADIOTERAPIA() {

}

void cRADIOTERAPIA::set_dosisPorSesion(unsigned int dosisPorSesion) {
	this->dosisPorSesion = dosisPorSesion;
	return;
}

void cRADIOTERAPIA::set_frecuenciaSemanalPorTumor(unsigned int frecuenciaSemanalPorTumor) {
	this->frecuenciaSemanalPorTumor = frecuenciaSemanalPorTumor;
	return;
}

unsigned int cRADIOTERAPIA:: get_dosisPorSesion() {
	return this->dosisPorSesion;
}

unsigned int cRADIOTERAPIA::get_frecuenciaSemanalPorTumor() {
	return this->frecuenciaSemanalPorTumor;
}

string cRADIOTERAPIA::to_string() {

}

void cRADIOTERAPIA::imprimir() {

}
