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
	
	//pido que me inventen dosis para los tratamientos
	dosimetrista.generar_dosis(paciente);
	
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
	for (int i = 0; i < paciente->get_ficha().get_tumores().size(); i++) {
		eTipoTumor aux = paciente->get_ficha().get_tumores()[i].tipo;
		srand (time(NULL));
		int hazExt = rand() % 2;
		if(hazExt==1||aux==pulmon||aux==intestino)

		switch (aux){
			case 
		}
	}
}
/*
haz externo -->ante la duda
braquiterapia --> cabeza, cuello, mama, cuello uterino, ojo
sistemica --> tiroides, protata
enum eTipoTumor { cabeza, pulmon, cuello, mama, utero, ojo, tiroides, prostata, intestino};

*/