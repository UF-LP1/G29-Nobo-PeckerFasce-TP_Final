#pragma once

#include "eTipoSangre.h"
#include "cFICHA.h"
#include "cPERSONA.h"
#ifndef _cPACIENTE_H
#define _cPACIENTE_H

class cPACIENTE :
    public cPERSONA
{
public:

    cPACIENTE(string nombre, string dni, eTipoSangre tipoSangre, char sexo);
    ~cPACIENTE();

    void set_enEspera(bool enEspera);
    void set_salud(float salud);
    void set_ficha(cFICHA ficha)
    eTipoSangre get_tipoSangre();
    float get_salud();
    char get_sexo();
    bool get_enEspera();
    cFICHA get_ficha();
    string to_string();


private:

    const eTipoSangre tipoSangre;
    const char sexo;
    float salud;
    bool enEspera;
    cFICHA ficha;
};

#endif

