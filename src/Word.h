
#pragma once

#include "MutableLetter.h"
#include "Letter.h"
#include <vector>

class Word
{
public:
    template<char L>
    void AppendLetter(const Letter<L>& letter)
    {
        m_letters.emplace_back();
        reinterpret_cast<MutableLetter&>(m_letters.back()).SetChar(letter.GetChar());
    }

    template<char L>
    std::vector<size_t> HasLetter(const Letter<L>& letter) const
    {
        std::vector<size_t> indices;
        for(size_t i = 0; i < m_letters.size(); ++i)
        {
            if(m_letters[i] == static_cast<const Letter<0>&>(letter))
            {
                indices.emplace_back(i);
            }
        }
        return(indices);
    }

    size_t Count() const;

    template<char L>
    void SetLetter(size_t index, const Letter<L>& letter)
    {
        static_cast<MutableLetter&>(m_letters[index]).SetChar(letter.GetChar());
    }

    bool MissingLetter(size_t index) const;

private:
    std::vector<Letter<0>> m_letters;

    friend class WordPrinter;
};
