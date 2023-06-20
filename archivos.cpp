#include "archivos.h"

ifstream leerArchivo(string nombre_archivo, list<cPACIENTE*> lista_pacientes)
{
	ifstream fp;
	fp.open(nombre_archivo, ios::in);
	if (!(fp.is_open()))
		throw exArchivoNoExistente();

	string nombre, dni, telefono, tipo_sangre, dummy;
	char sexo;
	float salud;
	eTipoSangre tipo;
	bool espera;

	int i = 0;
	fp >> dummy;

	while (!fp.eof()) {
		fp >> nombre >> dummy >> dni >> dummy >> tipo_sangre >> dummy >> sexo >> dummy >> salud >> dummy >> espera >> dummy >> telefono;
		try {
			tipo = leerSangre(tipo_sangre);
		}
		catch (exSangreInexistente& error) {
			cout << error.what()<<endl;
		}
		cPACIENTE* aux = new cPACIENTE(nombre, dni, tipo, sexo);
		aux->set_enEspera(espera);
		aux->set_salud(salud);
		aux->set_telefono(telefono);
		lista_pacientes.push_back(aux);

		delete aux;
	}
	fp.close();
	return fp;
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

/*
bool leerEnEspera(int enEspera)
{
	bool en_espera;
	if (enEspera == 1)
		en_espera = true;
	else if (enEspera == 0)
		en_espera = false;
	else
		throw exNoEsBool();

	return en_espera;
}

*/
