#include "cSISTEMICA.h"

cSISTEMICA::cSISTEMICA() :cRADIOTERAPIA(sistemica) {

}

cSISTEMICA::~cSISTEMICA() {

}

unsigned int cSISTEMICA::ajustar_dosis(eTamanioTumor tamanio) {

}

string cSISTEMICA::to_string() {
	stringstream ss;
	ss << "Terapia sistemica con dosis maxima de " << cSISTEMICA::dosisMax << ". El tratamiento consta de " << this->frecuenciaSemanalPorTumor << " sesiones por semana, con una dosis de " << this->dosisPorSesion << " en cada una.";
	return ss.str();
}


