#pragma once

#ifndef _cPERSONA_H
#define _cPERSONA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "TipoTumor.h"

using namespace std;

class cPERSONA
{

public:

    cPERSONA(string nombre, string dni);
    ~cPERSONA();

    void set_telefono(string telefono);
    string get_telefono();
    string get_nombre();
    string get_dni();
    virtual string to_string();
    void imprimir();

protected:
    const string nombre;
    const string dni;
    string telefono;

};
#endif