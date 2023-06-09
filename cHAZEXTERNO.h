#pragma once
#include "cRADIOTERAPIA.h"

#ifndef _cHAZEXTERNO_H
#define _cHAZEXTERNO_H

class cHAZEXTERNO :
    public cRADIOTERAPIA
{
public:
    static unsigned int dosisMax;

    cHAZEXTERNO();
    ~cHAZEXTERNO();
    unsigned int ajustar_dosis();
    string to_string();
};

#endif

