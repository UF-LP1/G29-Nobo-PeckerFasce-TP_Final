#include "cBRAQUITERAPIA.h"

cBRAQUITERAPIA::cBRAQUITERAPIA():cRADIOTERAPIA(braquiterapia) {

}


cBRAQUITERAPIA::~cBRAQUITERAPIA() {

}

unsigned int cBRAQUITERAPIA::ajustar_dosis(eTamanioTumor tamanio) {

}

string cBRAQUITERAPIA::to_string() {
	stringstream ss;
	ss << "Braquiterapia con dosis maxima de " << cBRAQUITERAPIA::dosisMax<<". El tratamiento consta de "<<this->frecuenciaSemanalPorTumor<<" sesiones por semana, con una dosis de "<<this->dosisPorSesion<<" en cada una.";
	return ss.str();	
}
