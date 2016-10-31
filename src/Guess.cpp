
#include "Guess.h"

#include <iostream>
#include <utility>

const std::string& Guess::GetGuess() const
{
    return(m_guess);
}

Guess Guess::TakeGuess()
{
    Guess g;
    std::cin >> g.m_guess;
    return(std::move(g));
}
