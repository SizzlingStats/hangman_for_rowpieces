
#pragma once

#include "GuessTracker.h"
#include "Word.h"

class HangmanGame
{
public:
    HangmanGame(size_t numGuesses, std::string secret);

    int Run();

private:
    GuessTracker m_guessTracker;
    Word m_secret;
    Word m_answer;
};
