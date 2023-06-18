#include "cONCOLOGO.h"

cONCOLOGO::cONCOLOGO(string nombre, string dni) :cMEDICO(nombre, dni) {

}

cONCOLOGO::~cONCOLOGO() {

}

void cONCOLOGO::pasar_lista_espera(cPACIENTE paciente) {
	paciente.set_enEspera(true);
}

void cONCOLOGO::atender_paciente(cPACIENTE paciente) {

}

void cONCOLOGO::generar_ficha_nueva(cPACIENTE* paciente, cDOSIMETRISTA dosimetrista) {
	unsigned int dosisMaxPaciente;
	cFICHA fichaaux;
	//me invento tumores
	generar_diagnostico(paciente);
	//me invento tratamientos 
	generar_tratamiento(paciente);
	//pido que me inventen dosis para los tratamientos
	dosimetrista.generar_dosis(paciente);
	//digo que la fecha de la ultima sesion fue hoy y te digo cuando tiene que volver el paciente 
	
	//le doy la ficha al paciente
	return;
}

void cONCOLOGO::generar_diagnostico(cPACIENTE* paciente) {
	srand(time(NULL));
	unsigned int cantTumores = rand() % 4+1;
	vector<eTipoTumor> tipos_tumores;
	for (int i = 0; i < cantTumores; i++) {
		do {
			tipos_tumores.push_back(eTipoTumor(rand() % 10));
		} while ((paciente->get_sexo() == 'f' && tipos_tumores[i] == prostata) || (paciente->get_sexo() == 'm' && (tipos_tumores[i] == mama || tipos_tumores[i] == utero)));
	}

	vector<cTUMOR> tumores;
	for (int j = 0; j < cantTumores; j++)
	{
		cTUMOR aux(tipos_tumores[j]);
		tumores.push_back(aux);
		tumores[j].set_tamanio(eTamanioTumor(rand() % 3));
	}
	cFICHA fichaaux = paciente->get_ficha();
	fichaaux.set_tumores(tumores);
	paciente->set_ficha(fichaaux);
	return;
}

string cONCOLOGO::to_string() {
	stringstream ss;
	ss << "Oncologo " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}

void cONCOLOGO::generar_tratamiento(cPACIENTE* paciente) {
	if (paciente->get_ficha().get_tumores().empty()) {
		throw exNoHayTumores();
	}
	for (int i = 0; i < paciente->get_ficha().get_tumores().size(); i++) {
		
		cRADIOTERAPIA* tratamiento;
		eTipoTumor aux = paciente->get_ficha().get_tumores()[i].tipo;
		srand(time(NULL));
		int hazExt = rand() % 2;
		//como el haz externo trata todos los tumores primero veo si lo trato con esto y sino le pongo el tratamiento especifico para el tipo de tumor del paciente 
		if (hazExt == 1 || aux == pulmon || aux == intestino) {
			tratamiento = new cHAZEXTERNO();
			
		}
		else {
			switch (aux) {
			case cabeza: {
				tratamiento = new cBRAQUITERAPIA();
				break;
			}
			case cuello: {
				tratamiento = new cBRAQUITERAPIA();
				break;
			}
			case mama: {
				tratamiento = new cBRAQUITERAPIA();
				break;
			}
			case utero: {
				tratamiento = new cBRAQUITERAPIA();
				break;
			}
			case ojo: {
				tratamiento = new cBRAQUITERAPIA();
				break;
			}
			case tiroides: {
				tratamiento = new cSISTEMICA();
				break;
			}
			case prostata: {
				tratamiento = new cSISTEMICA();
				break;
			}
			}
		}

		paciente->get_ficha().get_tumores()[i].set_tratamiento(tratamiento);
	}
	return;
}
/*
haz externo -->ante la duda
braquiterapia --> cabeza, cuello, mama, cuello uterino, ojo
sistemica --> tiroides, protata
enum eTipoTumor { cabeza, pulmon, cuello, mama, utero, ojo, tiroides, prostata, intestino};

*/