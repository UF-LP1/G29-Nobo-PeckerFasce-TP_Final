#include "cFICHA.h"

cFICHA::cFICHA(cONCOLOGO* oncologo):oncologo(oncologo) {
	this->dosisAcumTotal = 0;
	this->dosisMax = 0;
	this->fechaProxSesion = 0;
	this->fechaUltimaSesion = 0;
	this->frecuenciaSemanal = 0;
}

cFICHA::~cFICHA() {

}

void cFICHA::set_dosisAcumTotal(unsigned int dosisAcumTotal) {
	//CUANDO CALCULE LA DOSIS ACUM TOTAL 
	//Radiacion_paciente = Tumores_RTPHazExterno * 0.3 + Tumores_Braquiterapia * 0.6 +Tumores_Sistemico * 0.1

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

void cFICHA::set_tumores(vector<cTUMOR> tumores) {
	this->tumores = tumores;
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

vector <cTUMOR> cFICHA::get_tumores() {
	return this->tumores;
}

time_t cFICHA::get_fechaProxSesion() {
	return this->fechaProxSesion;
}

string cFICHA::to_string() {
	stringstream ss, ssaux;

	try {
		if (this->dosisAcumTotal == 0)
			throw exTratamientoNoComenzado();
	}
	catch (exTratamientoNoComenzado& error){
		ss << error.what();
		return ss.str();
	}

	if (this->dosisMax != 0)
	{
		float porcentaje = (float)(this->dosisAcumTotal * 100 / this->dosisMax);
		for (int i = 0; i < this->tumores.size();i++) {
			string aux= this->tumores[i].to_string();
			ssaux << "Tumor " << i + 1 << ": " << aux;
		}
		ss << "La dosis maxima es de " << this->dosisMax << ", de la cual se trato un " << porcentaje << "%. La ultima sesion fue el dia " << ctime(&(this->fechaUltimaSesion)) << ". La proxima sesion sera el dia " << ctime(&(this->fechaProxSesion)) << "." << ssaux.str();
	}
	return ss.str();
}

cONCOLOGO cFICHA::get_oncologo(){
	return this->oncologo;
}

ostream& operator<<(ostream& out, cFICHA& ficha) {
	out << ficha.to_string();
	return out;
}