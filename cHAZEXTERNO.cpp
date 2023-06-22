#include "cHAZEXTERNO.h"
float cHAZEXTERNO::dosisMaxPaciente = 100;
float cHAZEXTERNO::dosisMaxTumor = 60;

cHAZEXTERNO::cHAZEXTERNO(eTamanioTumor tamanio):cRADIOTERAPIA(hazExterno, tamanio) {
	
}

cHAZEXTERNO::~cHAZEXTERNO() {

}

float cHAZEXTERNO::ajustar_dosis(eTamanioTumor tamanio) {
	srand(time(NULL));
	float dosis = rand() % 4; //da un nro entre 0 y 3
	switch (tamanio)
	{
	case pequenio:
	{
		dosis = dosis + 1;
		break;
	}
	case mediano:
	{
		dosis = dosis + 4;
		break;
	}
	case grande:
	{
		dosis = dosis + 7;
		break;
	}

	}
	
	return dosis;
}

string cHAZEXTERNO::to_string() {
	stringstream ss;
	ss << "Terapia de haz externo con dosis maxima de " << cHAZEXTERNO::dosisMaxTumor << ". El tratamiento consta de " << this->frecuenciaSemanalPorTumor << " sesiones por semana, con una dosis de " << this->dosisPorSesion << " en cada una.";
	return ss.str();
}
