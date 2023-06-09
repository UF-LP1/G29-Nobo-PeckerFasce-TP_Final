#pragma once


#include "cBRAQUITERAPIA.h"
#include "cHAZEXTERNO.h"
#include "cSISTEMICA.h"
#include "cTUMOR.h"

#ifndef _cMEDICO_H
#define _cMEDICO_H

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
    friend ostream& operator<<(ostream& out, cMEDICO& medico);

protected:
    const string nombre;
    const string dni;
    string telefono;

};
#endif