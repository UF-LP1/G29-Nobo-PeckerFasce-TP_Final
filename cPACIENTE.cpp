#include "cPACIENTE.h"

cPACIENTE::cPACIENTE(string nombre, string dni, eTipoSangre tipoSangre, char sexo) : sexo(sexo), tipoSangre(tipoSangre) {
	this->enEspera = false;
}

cPACIENTE::~cPACIENTE() {

}

void cPACIENTE::set_enEspera(bool enEspera)
{
	this->enEspera = enEspera;
	return;
}
void cPACIENTE::set_ficha(cFICHA* ficha) {
	this->ficha = ficha;
}
void cPACIENTE::set_salud(float salud)
{
	this->salud = salud;
}
eTipoSangre cPACIENTE::get_tipoSangre()
{
	return this->tipoSangre;
}
cFICHA* cPACIENTE::get_ficha() {
	return this->ficha;
 }
float cPACIENTE::get_salud()
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

void cPACIENTE::set_telefono(string telefono)
{
	this->telefono = telefono;
}

string cPACIENTE::get_telefono()
{
	return this->telefono;
}

string cPACIENTE::get_nombre()
{
	return this->nombre;
}

string cPACIENTE::get_dni()
{
	return this->dni;
}

string cPACIENTE::to_string() {
	stringstream ss;
	string auxsexo, auxenespera;

	if (this->sexo == 'f')
	{
		auxsexo = "femenino";
	}
	else auxsexo = "masculino";

	if (enEspera)
	{
		auxenespera = "espera";
	}
	else auxenespera = "tratamiento";

	ss << "El paciente " << this->nombre <<"("<<auxsexo<<"), tipo de sangre: "<<this->tipoSangre<<", con DNI : " << this->dni << " y telefono : " << this->telefono << ", actualmente se encuentra en " << auxenespera<<". Su estado de salud actual (0-1) es: "<<this->salud;
	return ss.str();
}

 ostream& operator<<(ostream& out, cPACIENTE& paciente) {
	 out << paciente.to_string();
	 return out;
}

 bool cPACIENTE:: operator==(cONCOLOGO& miOncologo) {
	 return (this->ficha->get_oncologo().get_dni() == miOncologo.get_dni());
 }