#pragma once

#ifndef _cONCOLOGO_H
#define _cONCOLOGO_H

#include "cPACIENTE.h"

class cONCOLOGO :
    public cPERSONA
{
public:
    cONCOLOGO(string nombre, string dni);
    ~cONCOLOGO();

    void pasar_lista_espera(cPACIENTE paciente);
    void atender_paciente(cPACIENTE paciente);
    cFICHA generar_ficha_nueva(cPACIENTE paciente);
    void generar_diagnostico(cPACIENTE* paciente);
    string to_string();
};

#endif

