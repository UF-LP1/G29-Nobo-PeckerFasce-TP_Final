#include "cPERSONA.h"

cPERSONA::cPERSONA(string nombre, string dni)
{
	this->nombre = nombre;
	this->dni = dni;
	this->telefono = 0;

}

cPERSONA::~cPERSONA()
{
}

void cPERSONA::set_telefono(string telefono)
{
	this->telefono = telefono;
	return;
}

string cPERSONA::get_telefono()
{
	return this->telefono;
}

string cPERSONA::get_nombre()
{
	return this->nombre;
}
string cPERSONA::get_dni()
{
	return this->dni;
}

void cPERSONA::imprimir()
{
}
