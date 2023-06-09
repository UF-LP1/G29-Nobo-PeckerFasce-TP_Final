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


	const eTipoTumor tipo;



private:
	eTamanioTumor tamanio;
	unsigned int dosisAcumTumor;






};

#endif