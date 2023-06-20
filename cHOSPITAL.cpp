#include "cHOSPITAL.h"

cHOSPITAL::cHOSPITAL(string nombre, string direccion):nombre(nombre), direccion(direccion) {
	this->pacientes = list<cPACIENTE*>(pacientes.begin(), pacientes.end());
}

cHOSPITAL::~cHOSPITAL() {
	for (cPACIENTE* aux : this->pacientes) {
		if (aux != nullptr) {
			delete aux;
		}
	}
}

list<cPACIENTE*> cHOSPITAL::get_pacientes()
{
	return this->pacientes;
}

list <cPACIENTE*> cHOSPITAL::buscar_por_tratamiento_y_tumor(eRadioterapia tratamiento, eTipoTumor tumor) {
	list<cPACIENTE*>::iterator it = this->pacientes.begin();
	list<cPACIENTE*> aux;
	
	for (it; it != this->pacientes.end(); it++) {
		for (int i = 0; i < (*it)->get_ficha()->get_tumores().size(); i++) {
			if ((*it)->get_ficha()->get_tumores()[i]->get_tratamiento()->tratamiento == tratamiento && (*it)->get_ficha()->get_tumores()[i]->tipo == tumor)
				aux.push_back((*it));
		}
	}
	return aux;
}

list <cPACIENTE*> cHOSPITAL::buscar_por_menos_del_5porciento() {
	list<cPACIENTE*>::iterator it = this->pacientes.begin();
	list<cPACIENTE*> aux;
	float porcentaje = 0;

	for (it; it != this->pacientes.end(); it++) {
		for (int i = 0; i < (*it)->get_ficha()->get_tumores().size(); i++) {
			if (dynamic_cast<cBRAQUITERAPIA*>((*it)->get_ficha()->get_tumores()[i]->get_tratamiento()) != nullptr) 
				 porcentaje = (float)((*it)->get_ficha()->get_tumores()[i]->get_dosisAcumTumor() * 100 / cBRAQUITERAPIA::dosisMaxTumor);
			else if (dynamic_cast<cHAZEXTERNO*>((*it)->get_ficha()->get_tumores()[i]->get_tratamiento()) != nullptr)
				porcentaje = (float)((*it)->get_ficha()->get_tumores()[i]->get_dosisAcumTumor() * 100 / cHAZEXTERNO::dosisMaxTumor);
			else if (dynamic_cast<cSISTEMICA*>((*it)->get_ficha()->get_tumores()[i]->get_tratamiento()) != nullptr)
				porcentaje = (float)((*it)->get_ficha()->get_tumores()[i]->get_dosisAcumTumor() * 100 / cSISTEMICA::dosisMaxTumor);
	
			if (porcentaje>95)				
				aux.push_back((*it));
		
		}
	}
	return aux;
}


string cHOSPITAL::to_string() {
	stringstream ss;
	ss << "El hospital " << this->nombre << ", ubicado en " << this->direccion << " cuenta actualmente con " << this->pacientes.size() << " pacientes." << endl << endl << "Los pacientes son: " << endl;;
	
	list<cPACIENTE*>::iterator it = this->pacientes.begin();

	for (it; it != this->pacientes.end(); it++) {
		string enEspera = "";
		if ((*it)->get_enEspera())
			enEspera = "en espera";
		else
			enEspera = "en tratamiento";
		ss << (*it)->get_nombre() << '\t' << "Estado: " << enEspera << endl<< "Ficha medica del paciente: "<<(*it)->get_ficha()->to_string();
	}

	return ss.str();
}

void cHOSPITAL::operator+(cPACIENTE* paciente)
{
	try {
		buscar(paciente);
	}
	catch (exPacienteYaExistente& error) {
		cout <<endl << error.what() << endl;
		return;
	}

	this->pacientes.push_back(paciente);
	return;

}

void cHOSPITAL::operator-(cPACIENTE* paciente)
{
	try {
		buscar(paciente);
	}
	catch (exPacienteNoEncontrado& error) {
		cout << endl << error.what() << endl;
		return;
	}

	this->pacientes.remove(paciente);
	return;
}

void cHOSPITAL::buscar(cPACIENTE* paciente)
{
	list<cPACIENTE*>::iterator it = this->pacientes.begin();
	bool flag = false;

	for (it; it != this->pacientes.end(); it++) {
		if ((*it) == paciente)
			flag = true;
	}

	if (flag)
		throw exPacienteYaExistente();
	else
		throw exPacienteNoEncontrado();

	return;
}

ostream& operator<<(ostream& out, cHOSPITAL& hospital)
{
	out << hospital.to_string();
	return out;
}
