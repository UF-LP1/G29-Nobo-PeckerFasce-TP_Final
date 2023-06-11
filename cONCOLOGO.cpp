#include "cONCOLOGO.h"

cONCOLOGO::cONCOLOGO(string nombre, string dni) :cPERSONA(nombre, dni) {

}

cONCOLOGO::~cONCOLOGO() {

}

void cONCOLOGO::pasar_lista_espera(cPACIENTE paciente) {
	paciente.set_enEspera(true);
}

void cONCOLOGO::atender_paciente(cPACIENTE paciente) {

}

cFICHA cONCOLOGO::generar_ficha_nueva(cPACIENTE paciente) {
	unsigned int dosisMaxPaciente;
	//////
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

	paciente->get_ficha().set_tumores(tumores);
	return;
}

string cONCOLOGO::to_string() {
	stringstream ss;
	ss << "Oncologo " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}
