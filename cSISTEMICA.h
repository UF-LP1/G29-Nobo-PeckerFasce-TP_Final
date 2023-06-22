#pragma once
#include "cRADIOTERAPIA.h"

#ifndef _cSISTEMICA_H
#define _cSISTEMICA_H

class cSISTEMICA :
    public cRADIOTERAPIA
{
public:
    static float dosisMaxPaciente;
    static float dosisMaxTumor;


    cSISTEMICA(eTamanioTumor tamanio);
    ~cSISTEMICA();
    float ajustar_dosis(eTamanioTumor tamanio);
    string to_string();
};

#endif
