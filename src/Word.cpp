
#include "Word.h"

size_t Word::Count() const
{
    return(m_letters.size());
}

bool Word::MissingLetter(size_t index) const
{
    return(m_letters[index].GetChar() == '_');
}
