#include "cDOSIMETRISTA.h"

cDOSIMETRISTA::cDOSIMETRISTA(string nombre, string dni):cMEDICO(nombre,dni) {
	
}


cDOSIMETRISTA::~cDOSIMETRISTA() {

}

void cDOSIMETRISTA::generar_dosis(cPACIENTE paciente) {


	for (int i = 0; i < paciente.get_ficha().get_tumores().size();i++)
	{
		unsigned int dosis;
		//dynamic_cast del puntero de radioterapia para que llame al ajustar dosis correspondiente
		if (dynamic_cast<cBRAQUITERAPIA*>(paciente.get_ficha().get_tumores()[i].get_tratamiento()) != nullptr)
		{
			dosis=dynamic_cast<cBRAQUITERAPIA*>(paciente.get_ficha().get_tumores()[i].get_tratamiento())->ajustar_dosis(paciente.get_ficha().get_tumores()[i].get_tamanio());
		}
		else if (dynamic_cast<cSISTEMICA*>(paciente.get_ficha().get_tumores()[i].get_tratamiento()) != nullptr)
		{
			dosis = dynamic_cast<cSISTEMICA*>(paciente.get_ficha().get_tumores()[i].get_tratamiento())->ajustar_dosis(paciente.get_ficha().get_tumores()[i].get_tamanio());
		}
		else if (dynamic_cast<cHAZEXTERNO*>(paciente.get_ficha().get_tumores()[i].get_tratamiento()) != nullptr)
		{
			dosis = dynamic_cast<cHAZEXTERNO*>(paciente.get_ficha().get_tumores()[i].get_tratamiento())->ajustar_dosis(paciente.get_ficha().get_tumores()[i].get_tamanio());
		}
		
		//guardo la dosis que me devuelva la funcion en la maxima de ese tumor
		paciente.get_ficha().get_tumores()[i].set_dosisMaxTumor(dosis);

	}

	return;

}

string cDOSIMETRISTA::to_string() {
	stringstream ss;
	ss << "Dosimetrista " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}
