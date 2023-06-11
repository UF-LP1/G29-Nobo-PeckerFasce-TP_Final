#pragma once
#include "cPERSONA.h"
#include "cFICHA.h"

#ifndef _cDOSIMETRISTA_H
#define _cDOSIMETRISTA_H

class cDOSIMETRISTA :
    public cPERSONA
{
public:

    cDOSIMETRISTA(string nombre, string dni);
    ~cDOSIMETRISTA();

    void generar_dosis(cPACIENTE paciente);
    string to_string();
};

#endif