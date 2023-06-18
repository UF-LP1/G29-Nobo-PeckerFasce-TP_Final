#pragma once
#include "cRADIOTERAPIA.h"

#ifndef _cBRAQUITERAPIA_H
#define _cBRAQUITERAPIA_H

class cBRAQUITERAPIA :
    public cRADIOTERAPIA
{
public:
    static unsigned int dosisMaxPaciente;
    static unsigned int dosisMaxTumor;

    cBRAQUITERAPIA(eTamanioTumor tamanio);
    ~cBRAQUITERAPIA();
    unsigned int ajustar_dosis(eTamanioTumor tamanio);
    string to_string();
};

#endif

