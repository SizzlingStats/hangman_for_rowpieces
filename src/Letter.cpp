
#include "Letter.h"

template<char L>
Letter<L>::Letter():
    m_char(L)
{
}

template<char L>
char Letter<L>::GetChar() const
{
    return(m_char);
}

template<char L>
bool Letter<L>::operator==(const Letter<L>& other) const
{
    return(other.m_char == m_char);
}

template class Letter<0>;
