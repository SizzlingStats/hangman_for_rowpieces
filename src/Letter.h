
#pragma once

template<char L>
class Letter
{
public:
    Letter();

    char GetChar() const;

    bool operator==(const Letter<L>& other) const;

protected:
    const char m_char;
};
