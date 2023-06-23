#include "cTUMOR.h"

//this->carrito = vector<PRODUCTO*>(carrito.begin(), carrito.end());

cTUMOR::cTUMOR(eTipoTumor tipo):tipo(tipo)
{
	this->tamanio = eTamanioTumor(0);//por defecto pero despues hago set
	cRADIOTERAPIA* aux=new cSISTEMICA(this->tamanio); //dummy
	this->tratamiento = aux;
	this->dosisAcumTumor = 0;
	
}

cTUMOR::~cTUMOR(){
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
	//hago el tratamiento
	string tratamiento_aux = this->to_string_terapia();
	//hago el tamanio
	string tamanio_aux=this->to_string_tamanio();
	//hago el tipo
	string tipo_aux=this->to_string_tipo();
	ss << "Tumor de " << tipo_aux << ", de tamanio " << tamanio_aux <<", tratado con "<<tratamiento_aux << ". Dosis acumuladas hasta ahora: " << this->dosisAcumTumor;
	return ss.str();

}

string cTUMOR::to_string_tamanio()
{
	string tamanio_aux;
	switch (this->tamanio) {
	case 0: {

		tamanio_aux = "pequenio";
		break;
	}
	case 1: {
		tamanio_aux = "mediano";
		break;
	}
	case 2: {
		tamanio_aux = "grande";
		break;
	}
	}
	return tamanio_aux;
}

string cTUMOR::to_string_terapia()
{
	string tratamiento;
	if (dynamic_cast<cBRAQUITERAPIA*>(this->tratamiento) != nullptr)
		tratamiento = "braquiterapia";
	else if (dynamic_cast<cHAZEXTERNO*>(this->tratamiento) != nullptr)
		tratamiento = "radioterapia de haz externo";
	else if (dynamic_cast<cHAZEXTERNO*>(this->tratamiento) != nullptr)
		tratamiento = "radioterapia sistemica";
	return tratamiento;
}

string cTUMOR::to_string_tipo()
{
	string tipo_aux;
	switch (this->tipo) {
	case 0: {
		tipo_aux = "cabeza";
		break;
	}
	case 1: {
		tipo_aux = "pulmon";
		break;
	}
	case 2: {
		tipo_aux = "cuello";
		break;
	}
	case 3: {
		tipo_aux = "mama";
		break;
	}
	case 4: {
		tipo_aux = "utero";
		break;
	}
	case 5: {
		tipo_aux = "ojo";
		break;
	}
	case 6: {
		tipo_aux = "tiroides";
		break;
	}
	case 7: {
		tipo_aux = "prostata";
		break;
	}
	case 8: {
		tipo_aux = "intestino";
		break;
	}
	}
	return tipo_aux;
}

