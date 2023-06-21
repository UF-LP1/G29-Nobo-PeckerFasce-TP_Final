#include "cTUMOR.h"

//this->carrito = vector<PRODUCTO*>(carrito.begin(), carrito.end());

cTUMOR::cTUMOR(eTipoTumor tipo):tipo(tipo)
{
	cRADIOTERAPIA* aux = new cSISTEMICA(pequenio);//dummy
	this->tratamiento = aux;
	this->dosisAcumTumor = 0;
	this->tamanio = eTamanioTumor (0);//por defecto pero despues hago set
}

cTUMOR::~cTUMOR()
{
	delete this->tratamiento;
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

	string tratamiento = "";
	if (dynamic_cast<cBRAQUITERAPIA*>(this->tratamiento) != nullptr)
		tratamiento = "braquiterapia";
	else if (dynamic_cast<cHAZEXTERNO*>(this->tratamiento) != nullptr)
		tratamiento = "radioterapia de haz externo";
	else if (dynamic_cast<cHAZEXTERNO*>(this->tratamiento) != nullptr)
		tratamiento = "radioterapia sistemica";

	ss << "Tumor de " << this->tipo << ", de tamanio " << this->tamanio <<", tratado con "<<tratamiento << ". Dosis acumuladas hasta ahora: " << this->dosisAcumTumor;
	return ss.str();

}

