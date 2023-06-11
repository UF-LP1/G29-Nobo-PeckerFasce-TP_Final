#include "cHAZEXTERNO.h"

cHAZEXTERNO::cHAZEXTERNO():cRADIOTERAPIA(hazExterno) {

}

cHAZEXTERNO::~cHAZEXTERNO() {

}

unsigned int cHAZEXTERNO::ajustar_dosis(eTamanioTumor tamanio) {

}

string cHAZEXTERNO::to_string() {
	stringstream ss;
	ss << "Terapia de haz externo con dosis maxima de " << cHAZEXTERNO::dosisMax << ". El tratamiento consta de " << this->frecuenciaSemanalPorTumor << " sesiones por semana, con una dosis de " << this->dosisPorSesion << " en cada una.";
	return ss.str();
}
