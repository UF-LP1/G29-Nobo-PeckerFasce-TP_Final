#pragma once

#include "cPACIENTE.h"

#ifndef _cDOSIMETRISTA_H
#define _cDOSIMETRISTA_H

class cDOSIMETRISTA 
{
    const string nombre;
    const string dni;
    string telefono;
public:

    cDOSIMETRISTA(string nombre, string dni);
    ~cDOSIMETRISTA();

    void set_telefono(string telefono);
    string get_telefono() const;
    string get_nombre() const;
    string get_dni() const;
    void generar_dosis(cPACIENTE *paciente);
    string to_string();
    friend ostream& operator<<(ostream& out, cDOSIMETRISTA& dosimetrista);
};

#endif