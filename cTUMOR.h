#pragma once
#include "cSISTEMICA.h"
#include "cBRAQUITERAPIA.h"
#include "cHAZEXTERNO.h"

#ifndef _cTUMOR_H
#define _cTUMOR_H

class cTUMOR
{
public:
	cTUMOR(eTipoTumor tipo);
	~cTUMOR();
	string to_string();
	string to_string_tamanio();
	string to_string_terapia();
	string to_string_tipo();
	void set_tamanio(eTamanioTumor tamanio);
	void set_dosisAcumTumor(float dosisAcumTumor);
	void set_tratamiento(cRADIOTERAPIA*tratamiento);
	cRADIOTERAPIA* get_tratamiento();
	eTamanioTumor get_tamanio();
	float get_dosisAcumTumor();
	const eTipoTumor tipo;

private:
	eTamanioTumor tamanio;
	float dosisAcumTumor;
	cRADIOTERAPIA* tratamiento;
};

#endif