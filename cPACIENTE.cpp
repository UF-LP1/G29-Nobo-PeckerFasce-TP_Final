#include "cPACIENTE.h"

cPACIENTE::cPACIENTE(string nombre, string dni, eTipoSangre tipoSangre, char sexo) : nombre(nombre), dni(dni), sexo(sexo), tipoSangre(tipoSangre) {
	cFICHA* aux=new cFICHA("");
	this->enEspera = false;
	this->ficha = aux;
	this->salud = 0;
}

cPACIENTE::~cPACIENTE() {
	delete this->ficha;
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

float cPACIENTE::get_salud() const
{
	return this->salud;
}

char cPACIENTE::get_sexo() const
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

string cPACIENTE::get_telefono() const
{
	return this->telefono;
}

string cPACIENTE::get_nombre() const
{
	return this->nombre;
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
	string auxSangre = TipoSangre(this->tipoSangre);
	ss << "El paciente " << this->nombre <<"("<<auxsexo<<"), tipo de sangre: "<<auxSangre << ", con DNI : " << this->dni << " y telefono : " << this->telefono << ", actualmente se encuentra en " << auxenespera << ". Su estado de salud actual (0-1) es: " << this->salud;
	return ss.str();
}

 ostream& operator<<(ostream& out, cPACIENTE& paciente) {
	 out << paciente.to_string()<<endl;
	 return out;
}

 bool cPACIENTE:: operator==(string oncologo_dni) {
	 return (this->ficha->get_oncologo_dni()== oncologo_dni);

 }

 string cPACIENTE::get_dni() const
 {
	 return this->dni;
 }

 string cPACIENTE::TipoSangre(eTipoSangre sangre) {
	 string ts;
	 switch (sangre) {
	 case Op: {
		 ts = "0+";
		 break;
	 }
	 case On: {
		 ts = "0-";			
		 break;
	  }
	 case Ap: {
		 ts = "A+";
		 break;
	 }
	 case An: {
		 ts = "A-";
		 break;
	 }
	 case Bn: {
		 ts = "B-";
		 break;
	 }
	 case Bp: {
		 ts = "B+";
		 break;
	 }
	 case ABp: {
		 ts = "AB+";
		 break;
	 }
	 case ABn: {
		 ts = "AB-";
		 break;
	 }
	 
	 }
	 return ts;
 }