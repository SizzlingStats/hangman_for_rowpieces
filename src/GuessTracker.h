
#pragma once

#include <functional>

class GuessTracker
{
public:
    GuessTracker(size_t numGuesses);

    bool RunGuessLoop(std::function<bool()> guessFn);

private:
    size_t m_numGuesses;
};
