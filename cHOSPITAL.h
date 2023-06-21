#pragma once

#include "cPACIENTE.h"
#include "cONCOLOGO.h"
#ifndef _cHOSPITAL_H
#define _cHOSPITAL_H

class cHOSPITAL
{
private:
	list <cPACIENTE*> pacientes;
	list<cONCOLOGO*>oncologos;
	list < cDOSIMETRISTA* > dosimetristas;
public:
	const string nombre;
	const string direccion;
	cHOSPITAL(string nombre, string direccion);
	~cHOSPITAL();
	list<cPACIENTE*> get_pacientes();
	list <cPACIENTE*> buscar_por_tratamiento_y_tumor(eRadioterapia tratamiento, eTipoTumor tumor);
	list <cPACIENTE*> buscar_por_menos_del_5porciento();
	string to_string();

	void operator+(cPACIENTE* paciente);
	void operator-(cPACIENTE* paciente);
	void buscar(cPACIENTE* paciente);

	void operator+(cONCOLOGO* oncologo);
	void operator-(cONCOLOGO* oncologo);
	void buscar(cONCOLOGO* oncologo);


	void operator+(cDOSIMETRISTA* dosimetrista);
	void operator-(cDOSIMETRISTA* dosimetrista);
	void buscar(cDOSIMETRISTA* dosimetrista);

	friend ostream& operator<<(ostream& out, cHOSPITAL& hospital);
};

#endif

