#pragma once

#ifndef _cRADIOTERAPIA_H
#define _cRADIOTERAPIA_H

#include "eTipoTumor.h"
#include <string>
#include <sstream>
using namespace std;
class cRADIOTERAPIA
{
protected:
	unsigned int dosisPorSesion;
	unsigned int frecuenciaSemanalPorTumor;

public:
	const eRadioterapia tratamiento;

	cRADIOTERAPIA(eRadioterapia tratamiento, eTamanioTumor tamanio);
	~cRADIOTERAPIA();

	void set_dosisPorSesion(unsigned int dosisPorSesion);
	void set_frecuenciaSemanalPorTumor(unsigned int frecuenciaSemanalPorTumor);
	unsigned int get_dosisPorSesion();
	unsigned int get_frecuenciaSemanalPorTumor();
	virtual unsigned int ajustar_dosis(eTamanioTumor tamanio) = 0; //genero con random una dosis maxima para cada tumor
	virtual string to_string()=0;
	friend ostream& operator<<(ostream& out, cRADIOTERAPIA& radioterapia);

};

#endif

