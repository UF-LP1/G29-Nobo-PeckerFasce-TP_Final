#pragma once
#include "cONCOLOGO.h"
#include "cTUMOR.h"
#include "excepciones.h"
#ifndef _cFICHA_H
#define _FICHA_H

class cFICHA
{
public:

	cFICHA();
	~cFICHA();

	void set_dosisAcumTotal(unsigned int dosisAcumTotal);
	void set_dosisMax(unsigned int dosisMax);
	void set_fechaProxSesion(time_t fechaProxSesion);
	void set_fechaUltimaSesion(time_t fechaUltimaSesion);
	void set_frecuenciaSemanal(unsigned int frecuenciaSemanal);
	void set_tumores(vector<cTUMOR> tumores);
	unsigned int get_dosisAcumTotal();
	unsigned int get_dosisMax();
	unsigned int get_frecuenciaSemanal();
	time_t get_fechaUltimaSesion();
	time_t get_fechaProxSesion();
	vector <cTUMOR> get_tumores();
	string to_string();
	friend ostream& operator<<(ostream& out, cFICHA& ficha);

private:

	unsigned int dosisAcumTotal;
	unsigned int dosisMax;
	time_t fechaUltimaSesion;
	time_t fechaProxSesion;
	unsigned int frecuenciaSemanal;
	vector < cTUMOR > tumores;

};

#endif