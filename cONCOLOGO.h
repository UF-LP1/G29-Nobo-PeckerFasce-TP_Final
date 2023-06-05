#pragma once
#include "cPERSONA.h"
class cONCOLOGO :
    public cPERSONA
{
public:
    cONCOLOGO();
    ~cONCOLOGO();
    void pasar_lista_espera(cPACIENTE paciente);
    void atender_paciente(cPACIENTE paciente);
};

