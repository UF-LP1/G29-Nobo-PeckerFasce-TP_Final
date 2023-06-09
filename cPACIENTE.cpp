#include "cPACIENTE.h"

cPACIENTE::cPACIENTE(string nombre, string dni, eTipoSangre tipoSangre, char sexo) :cPERSONA(nombre, dni) {
	this->sexo = sexo;
	this->tipoSangre = tipoSangre;
	this->enEspera = false;
}

void cPACIENTE::set_enEspera(bool enEspera)
{
	this->enEspera = enEspera;
	return;
}

void cPACIENTE::set_salud(unsigned int salud)
{
	this->salud = salud;
}
eTipoSangre cPACIENTE::get_tipoSangre()
{
	return this->tipoSangre;
}

unsigned int cPACIENTE::get_salud()
{
	return this->salud;
}

char cPACIENTE::get_sexo()
{
	return this->sexo;
}

bool cPACIENTE::get_enEspera()
{
	return this->enEspera;
}

cPACIENTE::~cPACIENTE();


