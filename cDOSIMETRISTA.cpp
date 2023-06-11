#include "cDOSIMETRISTA.h"

cDOSIMETRISTA::cDOSIMETRISTA(string nombre, string dni):cPERSONA(nombre,dni) {
	
}


cDOSIMETRISTA::~cDOSIMETRISTA() {

}

void cDOSIMETRISTA::generar_dosis(cPACIENTE paciente) {


	for (int i = 0; i < paciente.get_ficha().get_tumores().size();i++)
	{
		unsigned int dosis;
	//dynamic_cast del puntero de radioterapia 
		if (dynamic_cast<cBRAQUITERAPIA*>(paciente.get_ficha().get_tumores()[i].get_tratamiento()) != nullptr)
		{
			//dynamic_cast<Cuadrado*>(aux)->imprimir();
			dosis=dynamic_cast<cBRAQUITERAPIA*>(paciente.get_ficha().get_tumores()[i].get_tratamiento())->ajustar_dosis(paciente.get_ficha().get_tumores()[i].get_tamanio());
		}
			
			


	}


}

string cDOSIMETRISTA::to_string() {
	stringstream ss;
	ss << "Dosimetrista " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}
