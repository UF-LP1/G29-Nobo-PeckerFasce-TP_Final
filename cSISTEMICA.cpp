#include "cSISTEMICA.h"
unsigned int cSISTEMICA::dosisMaxPaciente = 100;
unsigned int cSISTEMICA::dosisMaxPaciente = 60;
cSISTEMICA::cSISTEMICA() :cRADIOTERAPIA(sistemica) {

}

cSISTEMICA::~cSISTEMICA() {

}

unsigned int cSISTEMICA::ajustar_dosis(eTamanioTumor tamanio) {
	srand(time(NULL));
	unsigned int dosis = rand() % 8; //da un nro del 0 al 7
	switch (tamanio) {
	case pequenio: {
		dosis = dosis + 20;
		break;
	}
	case mediano: {
		dosis = dosis + 26;
		break;
	}
	case grande: {
		dosis = dosis + 33;
		break;
	}
	}
	return dosis;
}

string cSISTEMICA::to_string() {
	stringstream ss;
	ss << "Terapia sistemica con dosis maxima de " << cSISTEMICA::dosisMax << ". El tratamiento consta de " << this->frecuenciaSemanalPorTumor << " sesiones por semana, con una dosis de " << this->dosisPorSesion << " en cada una.";
	return ss.str();
}


