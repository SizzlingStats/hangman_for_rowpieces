
#pragma once

template<char L>
class Letter
{
public:
    Letter():
        m_char(L)
    {
    }

    char GetChar() const
    {
        return(m_char);
    }

    bool operator==(const Letter<L>& other) const
    {
        return(other.m_char == m_char);
    }

protected:
    const char m_char;
};
