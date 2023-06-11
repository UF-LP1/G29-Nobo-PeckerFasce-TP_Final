#pragma once

#ifndef _cHOSPITAL_H
#define _cHOSPITAL_H
#include "cPACIENTE.h"

class cHOSPITAL
{
private:

public:
	const string nombre;
	const string direccion;
	vector <cPACIENTE> pacientes;
	cHOSPITAL(string nombre, string direccion);
	~cHOSPITAL();

	vector <cPACIENTE> buscar_por_tratamiento_y_tumor(eRadioterapia tratamiento, eTipoTumor tumor);
	vector <cPACIENTE> buscar_por_menos_del_5porciento();
	void imprimirListado();
	string to_string();
	void imprimir();
};

#endif

