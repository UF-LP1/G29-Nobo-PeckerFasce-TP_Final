#pragma once

#ifndef _cFICHA_H
#define _FICHA_H

class cFICHA
{
public:

	cFICHA();
	~cFICHA();

	void set_dosisAcumTotal(unsigned int dosisAcumTotal);
	void set_dosisMax(unsigned int dosisMax);
	void set_porcentajeTratado(float porcentajeTratado);
	void set_fechaProxSesion(time_t fechaProxSesion);
	void set_fechaUltimaSesion(time_t fechaUltimaSesion);
	void set_frecuenciaSemanal(unsigned int frecuenciaSemanal);
	unsigned int get_dosisAcumTotal();
	unsigned int get_dosisMax();
	float get_porcentajeTratado();
	unsigned int get_frecuenciaSemanal();
	time_t get_fechaUltimaSesion();
	time_t get_fechaProxSesion();
	string to_string();
	void imprimir();

private:

	unsigned int dosisAcumTotal;
	unsigned int dosisMax;
	float porcentajeTratado;
	time_t fechaUltimaSesion;
	time_t fechaProxSesion;
	unsigned int frecuenciaSemanal;


};

#endif