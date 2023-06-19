#pragma once

#ifndef _cONCOLOGO_H
#define _cONCOLOGO_H

#include "cMEDICO.h"

class cONCOLOGO :
    public cMEDICO
{
public:
    cONCOLOGO(string nombre, string dni);
    ~cONCOLOGO();

    void pasar_lista_espera(cPACIENTE* paciente);
    void sacar_lista_espera(cPACIENTE* paciente, cDOSIMETRISTA* dosimetrista);
    void atender_paciente(cPACIENTE* paciente);
    void generar_ficha_nueva(cPACIENTE* paciente, cDOSIMETRISTA* dosimetrista);
    void generar_diagnostico(cPACIENTE* paciente);
    void generar_tratamiento(cPACIENTE* paciente);
    unsigned int generar_frecuenciaSemanal(cPACIENTE*paciente);
    string to_string();
    unsigned int calcular_dosisMax(cPACIENTE* paciente);
};

#endif

