#include "cSISTEMICA.h"
float cSISTEMICA::dosisMaxPaciente = 100;
float cSISTEMICA::dosisMaxTumor = 60;

cSISTEMICA::cSISTEMICA(eTamanioTumor tamanio) :cRADIOTERAPIA(sistemica, tamanio) {
	
}

cSISTEMICA::~cSISTEMICA() {

}

float cSISTEMICA::ajustar_dosis(eTamanioTumor tamanio) {
	srand(time(NULL));
	float dosis = (rand() %10)/10; 
	switch (tamanio) {
	case pequenio: {
		dosis = dosis + 2;
		break;
	}
	case mediano: {
		dosis = dosis + 2.5;
		
		break;
	}
	case grande: {
		dosis = dosis + 3;
		
		break;
	}
	}
	return dosis;
}

string cSISTEMICA::to_string() {
	stringstream ss;
	ss << "Terapia sistemica con dosis maxima de " << cSISTEMICA::dosisMaxTumor << ". El tratamiento consta de " << this->frecuenciaSemanalPorTumor << " sesiones por semana, con una dosis de " << this->dosisPorSesion << " en cada una.";
	return ss.str();
}


