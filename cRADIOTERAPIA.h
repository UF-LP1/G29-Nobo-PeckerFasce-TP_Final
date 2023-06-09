#pragma once

#ifndef _cRADIOTERAPIA_H
#define _cRADIOTERAPIA_H

#include "eTipoTumor.h"
#include "cTUMOR.h"
#include <sstream>

class cRADIOTERAPIA
{
protected:
	unsigned int dosisPorSesion;
	unsigned int frecuenciaSemanalPorTumor;

public:
	const eRadioterapia tratamiento;

	cRADIOTERAPIA(eRadioterapia tratamiento);
	~cRADIOTERAPIA();

	void set_dosisPorSesion(unsigned int dosisPorSesion);
	void set_frecuenciaSemanalPorTumor(unsigned int frecuenciaSemanalPorTumor);
	unsigned int get_dosisPorSesion();
	unsigned int get_frecuenciaSemanalPorTumor();
	string to_string();
	void imprimir();

};

#endif

