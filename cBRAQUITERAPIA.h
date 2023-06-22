#pragma once
#include "cRADIOTERAPIA.h"

#ifndef _cBRAQUITERAPIA_H
#define _cBRAQUITERAPIA_H

class cBRAQUITERAPIA :
    public cRADIOTERAPIA
{
public:
    static float dosisMaxPaciente;
    static float dosisMaxTumor;

    cBRAQUITERAPIA(eTamanioTumor tamanio);
    ~cBRAQUITERAPIA();
   float ajustar_dosis(eTamanioTumor tamanio);
    string to_string();
};

#endif

