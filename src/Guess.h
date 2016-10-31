
#pragma once

#include <string>

class Guess
{
public:
    const std::string& GetGuess() const;

    static Guess TakeGuess();

private:
    std::string m_guess;
};
