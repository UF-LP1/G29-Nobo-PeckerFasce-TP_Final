#pragma once

#include "eTipoTumor.h"
#include "cFICHA.h"


#ifndef _cPACIENTE_H
#define _cPACIENTE_H

class cPACIENTE     
{
    const string nombre;
    const string dni;
    string telefono;
    const eTipoSangre tipoSangre;
    const char sexo;
    float salud;
    bool enEspera;
    cFICHA* ficha;

public:

    cPACIENTE(string nombre, string dni, eTipoSangre tipoSangre, char sexo);
    ~cPACIENTE();

    void set_enEspera(bool enEspera);
    void set_salud(float salud);
    void set_ficha(cFICHA* ficha);
    eTipoSangre get_tipoSangre();
    float get_salud();
    char get_sexo();
    bool get_enEspera();
    cFICHA* get_ficha();
    string to_string();
    void set_telefono(string telefono);
    string get_telefono();
    string get_nombre();
    string get_dni();
    string TipoSangre(eTipoSangre sangre);
    friend ostream& operator<<(ostream& out, cPACIENTE& paciente);
    bool operator==(string oncologo_dni);
};

#endif

