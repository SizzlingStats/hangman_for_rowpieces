
#pragma once

#include "Letter.h"

class MutableLetter: public Letter<0>
{
public:
    MutableLetter();

    void SetChar(char c);
};
