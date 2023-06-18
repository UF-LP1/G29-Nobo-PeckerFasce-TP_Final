#include "cMEDICO.h"

cMEDICO::cMEDICO(string nombre, string dni): nombre(nombre), dni(dni)
{
	this->telefono = "";
}

cMEDICO::~cMEDICO()
{
}

void cMEDICO::set_telefono(string telefono)
{
	this->telefono = telefono;
	return;
}

string cMEDICO::get_telefono()
{
	return this->telefono;
}

string cMEDICO::get_nombre()
{
	return this->nombre;
}
string cMEDICO::get_dni()
{
	return this->dni;
}

ostream& operator<<(ostream& out, cMEDICO& medico) {
	out << medico.to_string();
	return out;
}

