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
	list <cPACIENTE*> pacientes;
	cHOSPITAL(string nombre, string direccion);
	~cHOSPITAL();

	list <cPACIENTE> buscar_por_tratamiento_y_tumor(eRadioterapia tratamiento, eTipoTumor tumor);
	list <cPACIENTE> buscar_por_menos_del_5porciento();
	string to_string();
	friend ostream& operator<<(ostream& out, cHOSPITAL& hospital);
};

#endif

