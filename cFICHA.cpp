#include "cFICHA.h"

cFICHA::cFICHA(string oncologo_dni):oncologo_dni(oncologo_dni) {
	this->dosisAcumTotal = 0;
	this->dosisMax = 0;
	this->fechaProxSesion = 0;
	this->fechaUltimaSesion = 0;
	this->frecuenciaSemanal = 0;
}

cFICHA::~cFICHA() {
	for (int i = 0; i < this->tumores.size(); i++) {
		delete[] this->tumores[i];
	}
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

void cFICHA::set_tumores(vector<cTUMOR*> tumores) {
	this->tumores = tumores;
}

void cFICHA::set_dniOncologo(string dni_oncologo){
	this->oncologo_dni = dni_oncologo;
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

vector <cTUMOR*> cFICHA::get_tumores() {
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
		ss << endl << error.what() << endl;
		return ss.str();
	}

	if (this->dosisMax != 0)
	{
		float porcentaje = (float)(this->dosisAcumTotal * 100 / this->dosisMax);
		for (int i = 0; i < this->tumores.size();i++) {
			string aux= this->tumores[i]->to_string();
			ssaux <<'\t' << "Tumor " << i + 1 << ": " << aux << endl;
		}
		ss << "DNI del oncologo a cargo: " << this->oncologo_dni << endl;
		string fechaUltAux = convertir_fecha(this->fechaUltimaSesion);
		string fechaProxAux = convertir_fecha(this->fechaProxSesion);
		ss << "La dosis maxima del paciente es de " << this->dosisMax << ", de la cual se trato un " << porcentaje << "%. "<<endl<<"La ultima sesion fue el dia " << fechaUltAux << ". La proxima sesion sera el dia " << fechaProxAux << "." <<endl<<"Diagnostico: "<< ssaux.str() << endl;
	}
	return ss.str();
}

string cFICHA::get_oncologo_dni(){
	return this->oncologo_dni;
}

void cFICHA::acomodar_fechas()
{
	this->fechaUltimaSesion = time(NULL);
	unsigned int dia_vuelta;
	switch (this->frecuenciaSemanal) {
	case 1: {
		dia_vuelta = 7;
		break;
	}
	case 2: {
		dia_vuelta = 3;
		break;
	}
	case 3: {
		dia_vuelta = 2;
		break;
	}
	}
	this->fechaProxSesion = time(NULL) + dia_vuelta * dia;
	return;
}

ostream& operator<<(ostream& out, cFICHA& ficha) {
	out << ficha.to_string();
	return out;
}

string cFICHA::convertir_fecha(time_t fecha)
{
	tm tiempo;
	localtime_s(&tiempo, &fecha);
	int dia_ = tiempo.tm_mday;
	int mes_ = tiempo.tm_mon + 1;
	int anio_ = tiempo.tm_year + 1900;
	stringstream strfecha;
	strfecha << dia_ << "/" << mes_ << "/" << anio_;
	return strfecha.str();
}