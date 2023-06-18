#pragma once
#include "cRADIOTERAPIA.h"

#ifndef _cHAZEXTERNO_H
#define _cHAZEXTERNO_H

class cHAZEXTERNO :
    public cRADIOTERAPIA
{
public:
    static unsigned int dosisMaxPaciente;
    static unsigned int dosisMaxTumor;

    cHAZEXTERNO();
    ~cHAZEXTERNO();
    unsigned int ajustar_dosis(eTamanioTumor tamanio);
    string to_string();
};

#endif

