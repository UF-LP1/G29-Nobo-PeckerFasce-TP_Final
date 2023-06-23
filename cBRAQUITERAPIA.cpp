#include "cBRAQUITERAPIA.h"
float cBRAQUITERAPIA::dosisMaxPaciente = 180;
float cBRAQUITERAPIA::dosisMaxTumor = 150;

cBRAQUITERAPIA::cBRAQUITERAPIA(eTamanioTumor tamanio):cRADIOTERAPIA(braquiterapia, tamanio) {
	
}


cBRAQUITERAPIA::~cBRAQUITERAPIA() {

}

float cBRAQUITERAPIA::ajustar_dosis(eTamanioTumor tamanio) {
	srand(time(NULL));
	float dosis = (rand() % 10)/20; 
	switch (tamanio) {
	case pequenio: {
		dosis = dosis + 1;
		break;
	}
	case mediano: {
		dosis = dosis + 1.2;
		break;
	}
	case grande: {
		dosis = dosis + 1.55;
		break;
	}
	}
	return dosis;
}

string cBRAQUITERAPIA::to_string() {
	stringstream ss;
	ss << "Braquiterapia con dosis maxima de " << cBRAQUITERAPIA::dosisMaxPaciente<<". El tratamiento consta de "<<this->frecuenciaSemanalPorTumor<<" sesiones por semana, con una dosis de "<<this->dosisPorSesion<<" en cada una.";
	return ss.str();	
}
