#include "cTUMOR.h"

cTUMOR::cTUMOR(eTipoTumor tipo)
{
	this->tipo = tipo;
	this->dosisAcumTumor = 0;
	this->tamanio = eTamanioTumor (0);//por defecto pero despues hago set
}
