#pragma once
#include "cPACIENTE.h"
#include "cDOSIMETRISTA.h"
#ifndef _cONCOLOGO_H
#define _cONCOLOGO_H


class cONCOLOGO
{
    const string nombre;
    const string dni;
    string telefono;

public:
    cONCOLOGO(string nombre, string dni);
    ~cONCOLOGO();

    void set_telefono(string telefono);
    string get_telefono() const;
    string get_nombre() const;
    string get_dni() const;
    void pasar_lista_espera(cPACIENTE* paciente);
    void sacar_lista_espera(cPACIENTE* paciente, cDOSIMETRISTA* dosimetrista);
    void atender_paciente(cPACIENTE* paciente);
    void generar_ficha_nueva(cPACIENTE* paciente, cDOSIMETRISTA* dosimetrista);
    void generar_diagnostico(cPACIENTE* paciente);
    void generar_tratamiento(cPACIENTE* paciente);
    unsigned int generar_frecuenciaSemanal(cPACIENTE*paciente);
    string to_string();
    unsigned int calcular_dosisMax(cPACIENTE* paciente);
    friend ostream& operator<<(ostream& out, cONCOLOGO& oncologo);
};

#endif

