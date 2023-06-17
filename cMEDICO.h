#pragma once

#ifndef _cPERSONA_H
#define _cPERSONA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <ctime>

#include "eTipoTumor.h"
#include "cBRAQUITERAPIA.h"
#include "cHAZEXTERNO.h"
#include "cSISTEMICA.h"

using namespace std;

class cMEDICO
{

public:

    cMEDICO(string nombre, string dni);
    ~cMEDICO();

    void set_telefono(string telefono);
    string get_telefono();
    string get_nombre();
    string get_dni();
    virtual string to_string()=0;
    void imprimir();//SOBRECARGA

protected:
    const string nombre;
    const string dni;
    string telefono;

};
#endif