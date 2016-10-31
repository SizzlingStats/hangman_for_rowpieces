
#include "WordPrinter.h"

#include "Word.h"
#include "Letter.h"
#include <iostream>

WordPrinter::WordPrinter(const Word& word):
    m_word(word)
{
}

void WordPrinter::PrintWord() const
{
    for(const Letter<0>& letter : m_word.m_letters)
    {
        // const correctness!
        const char temp[2] = { letter.GetChar(), '\0' };
        std::cout << temp;
    }
    std::cout << std::endl;
}
