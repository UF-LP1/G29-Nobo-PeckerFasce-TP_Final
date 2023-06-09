#pragma once

#ifndef _cRADIOTERAPIA_H
#define _cRADIOTERAPIA_H

#include "eTipoTumor.h"
#include "cTUMOR.h"

class cRADIOTERAPIA
{
private:
	unsigned int dosisPorSesion;
	unsigned int frecuenciaSemanalPorTumor;

public:
	const eRadioterapia tratamiento;

	cRADIOTERAPIA(eRdioterapia tratamiento);
	~cRADIOTERAPIA();

	string to_string();
	void imprimir();

};

#endif

