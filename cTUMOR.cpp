#include "cTUMOR.h"

cTUMOR::cTUMOR(eTipoTumor tipo):tipo(tipo)
{
	this->dosisAcumTumor = 0;
	this->tamanio = eTamanioTumor (0);//por defecto pero despues hago set
}

cTUMOR::~cTUMOR()
{
}

void cTUMOR::set_tamanio(eTamanioTumor tamanio)
{
	this->tamanio = tamanio;
	return;
}
