#pragma once
#include "cONCOLOGO.h"
#include "cRADIOTERAPIA.h"

#ifndef _cTUMOR_H
#define _cTUMOR_H

class cTUMOR
{
public:
	cTUMOR(eTipoTumor tipo);
	~cTUMOR();
	string to_string();
	void imprimir();
	void set_tamanio(eTamanioTumor tamanio);
	void set_dosisAcumTumor(unsigned int dosisAcumTumor);
	void set_tratamiento(cRADIOTERAPIA*tratamiento);
	cRADIOTERAPIA* get_tratamiento();
	eTamanioTumor get_tamanio();
	unsigned int get_dosisAcumTumor();

	const eTipoTumor tipo;

private:
	eTamanioTumor tamanio;
	unsigned int dosisAcumTumor;
	cRADIOTERAPIA* tratamiento;
};

#endif