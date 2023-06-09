#pragma once
#include "cONCOLOGO.h"

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
	eTamanioTumor get_tamanio();
	unsigned int get_dosisAcumTumor();

	const eTipoTumor tipo;

private:
	eTamanioTumor tamanio;
	unsigned int dosisAcumTumor;

};

#endif