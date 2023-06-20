#include "archivos.h"

ifstream leerArchivo(string nombre_archivo, list<cPACIENTE*> lista_pacientes)
{
	ifstream fp;
	fp.open(nombre_archivo, ios::in);
	if (!(fp.is_open()))
		throw exArchivoNoExistente();
	/*
		const string nombre;
		const string dni;
		string telefono;
		const eTipoSangre tipoSangre;
		const char sexo;
		float salud;
		bool enEspera;
	*/

	string nombre, dni, telefono, tipo_sangre, dummy;
	char sexo;
	float salud;
	int en_espera;
	eTipoSangre tipo;

	//DESP PASO TIPO_SANGRE Y EN_ESPERA

	int i = 0;
	fp >> dummy;
	while (!fp.eof()) {
		fp >> nombre >> dummy >> dni >> dummy >> tipo_sangre >> dummy >> sexo >> dummy >> salud >> dummy >> en_espera >> dummy >> telefono;
		tipo = leerSangre(tipo_sangre);

		cPACIENTE* aux = new cPACIENTE(nombre, dni, tipo, sexo);
	}



	return ifstream();
}

eTipoSangre leerSangre(string tipoSangre)
{
	eTipoSangre tipo;
	if (tipoSangre == "0p")
		tipo = eTipoSangre(0);
	else if (tipoSangre == "0n")
		tipo = eTipoSangre(1);
	else if (tipoSangre == "Ap")
		tipo = eTipoSangre(2);
	else if (tipoSangre == "An")
		tipo = eTipoSangre(3);
	else if (tipoSangre == "Bp")
		tipo = eTipoSangre(4);
	else if (tipoSangre == "Bn")
		tipo = eTipoSangre(5);
	else if (tipoSangre == "ABp")
		tipo = eTipoSangre(6);
	else if (tipoSangre == "ABn")
		tipo = eTipoSangre(7);
	else
		throw exSangreInexistente();

	return tipo;
}

bool leerEnEspera(int enEspera)
{
	bool en_espera;
	if (enEspera == 1)
		en_espera = true;
	else if (enEspera == 0)
		en_espera = false;
	else
		throw exNoEsBool();

	return false;
}

