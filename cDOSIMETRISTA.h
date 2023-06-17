#pragma once
#include "cMEDICO.h"
#include "cFICHA.h"

#ifndef _cDOSIMETRISTA_H
#define _cDOSIMETRISTA_H

class cDOSIMETRISTA :
    public cMEDICO
{
public:

    cDOSIMETRISTA(string nombre, string dni);
    ~cDOSIMETRISTA();

    void generar_dosis(cPACIENTE *paciente);
    string to_string();
};

#endif