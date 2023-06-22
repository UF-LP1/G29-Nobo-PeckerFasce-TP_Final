#include "cBRAQUITERAPIA.h"
unsigned int cBRAQUITERAPIA::dosisMaxPaciente = 180;
unsigned int cBRAQUITERAPIA::dosisMaxTumor = 150;

cBRAQUITERAPIA::cBRAQUITERAPIA(eTamanioTumor tamanio):cRADIOTERAPIA(braquiterapia, tamanio) {
	
}


cBRAQUITERAPIA::~cBRAQUITERAPIA() {

}

unsigned int cBRAQUITERAPIA::ajustar_dosis(eTamanioTumor tamanio) {
	srand(time(NULL));
	unsigned int dosis = rand() % 21; //da un nro del 0 al 20
	switch (tamanio) {
	case pequenio: {
		dosis = dosis + 100;
		break;
	}
	case mediano: {
		dosis = dosis + 120;
		break;
	}
	case grande: {
		dosis = dosis + 140;
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
