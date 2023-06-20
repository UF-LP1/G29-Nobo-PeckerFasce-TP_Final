#include "cRADIOTERAPIA.h"

cRADIOTERAPIA::cRADIOTERAPIA(eRadioterapia tratamiento, eTamanioTumor tamanio):tratamiento(tratamiento) {
	
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

ostream& operator<<(ostream& out, cRADIOTERAPIA& radioterapia) {
	out << radioterapia.to_string();
	return out;
}
