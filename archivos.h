#pragma once

#include <fstream>
#include "cHOSPITAL.h"

ifstream leerArchivo(string nombre_archivo, list<cPACIENTE*> lista_pacientes);

eTipoSangre leerSangre(string tipoSangre);

//bool leerEnEspera(int enEspera);