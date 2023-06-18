#pragma once
#include "cRADIOTERAPIA.h"

#ifndef _cSISTEMICA_H
#define _cSISTEMICA_H

class cSISTEMICA :
    public cRADIOTERAPIA
{
public:
    static unsigned int dosisMaxPaciente;
    static unsigned int dosisMaxTumor;


    cSISTEMICA();
    ~cSISTEMICA();
    unsigned int ajustar_dosis(eTamanioTumor tamanio);
    string to_string();
};

#endif
