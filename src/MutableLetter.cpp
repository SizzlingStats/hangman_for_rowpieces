
#include "MutableLetter.h"

MutableLetter::MutableLetter():
    Letter()
{
}

void MutableLetter::SetChar(char c)
{
    const_cast<char&>(m_char) = c;
}
