#pragma once
#include "cRADIOTERAPIA.h"

#ifndef _cHAZEXTERNO_H
#define _cHAZEXTERNO_H

class cHAZEXTERNO :
    public cRADIOTERAPIA
{
public:
    static float dosisMaxPaciente;
    static float dosisMaxTumor;

    cHAZEXTERNO(eTamanioTumor tamanio);
    ~cHAZEXTERNO();
    float ajustar_dosis(eTamanioTumor tamanio);
    string to_string();
};

#endif

