#include "cFICHA.h"

cFICHA::cFICHA() {
	this->dosisAcumTotal = 0;
	this->dosisMax = 0;
	this->fechaProxSesion = 0;
	this->fechaUltimaSesion = 0;
	this->frecuenciaSemanal = 0;
	this->porcentajeTratado = 0;
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

void cFICHA::set_porcentajeTratado(float porcentajeTratado) {
	this->porcentajeTratado = porcentajeTratado;
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

float cFICHA::get_porcentajeTratado() {
	return this->porcentajeTratado;
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

}

void cFICHA::imprimir() {

}
