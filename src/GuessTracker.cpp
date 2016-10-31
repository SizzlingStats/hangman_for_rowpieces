
#include "GuessTracker.h"

GuessTracker::GuessTracker(size_t numGuesses):
    m_numGuesses(numGuesses)
{
}

bool GuessTracker::RunGuessLoop(std::function<bool()> guessFn)
{
    bool result = true;
    if(m_numGuesses > 0)
    {
        while(m_numGuesses --> 0)
        {
            result = guessFn();
            if(result || m_numGuesses == 0)
            {
                break;
            }
        }
    }
    return(result);
}
