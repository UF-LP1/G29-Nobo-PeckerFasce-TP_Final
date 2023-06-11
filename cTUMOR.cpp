#include "cTUMOR.h"

//this->carrito = vector<PRODUCTO*>(carrito.begin(), carrito.end());

cTUMOR::cTUMOR(eTipoTumor tipo):tipo(tipo)
{
	this->dosisAcumTumor = 0;
	this->tamanio = eTamanioTumor (0);//por defecto pero despues hago set
}

cTUMOR::~cTUMOR()
{
}

void cTUMOR::set_tamanio(eTamanioTumor tamanio)
{
	this->tamanio = tamanio;
	return;
}

void cTUMOR::set_dosisAcumTumor(unsigned int dosisAcumTumor) {
	this->dosisAcumTumor = dosisAcumTumor;
	return;
}
void cTUMOR::set_tratamiento(cRADIOTERAPIA* tratamiento) {
	this->tratamiento = tratamiento;
}
cRADIOTERAPIA* cTUMOR::get_tratamiento() {
	return this->tratamiento;
}

eTamanioTumor cTUMOR::get_tamanio() {
	return this->tamanio;
}

unsigned int cTUMOR::get_dosisAcumTumor() {
	return this->dosisAcumTumor;
}

string cTUMOR::to_string() {
	stringstream ss;
	ss << "Tumor de " << this->tipo << ", de tamanio " << this->tamanio << ". Dosis acumuladas hasta ahora: " << this->dosisAcumTumor;
	return ss.str();

}

void cTUMOR::imprimir() {

}


