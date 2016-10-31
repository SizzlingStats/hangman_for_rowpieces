
#pragma once

class Word;

class WordPrinter
{
public:
    WordPrinter(const Word& word);

    void PrintWord() const;

private:
    const Word& m_word;
};
