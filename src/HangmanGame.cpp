
#include "HangmanGame.h"

#include "Letter.h"
#include "WordPrinter.h"
#include "Guess.h"
#include <iostream>

HangmanGame::HangmanGame(size_t numGuesses, std::string secret):
    m_guessTracker(numGuesses),
    m_secret()
{
    for(char c : secret)
    {
        Letter<0> letter;
        reinterpret_cast<MutableLetter&>(letter).SetChar(c);
        m_secret.AppendLetter(letter);

        // Reuse letter for efficiency
        reinterpret_cast<MutableLetter&>(letter).SetChar('_');
        m_answer.AppendLetter(letter);
    }
}

int HangmanGame::Run()
{
    WordPrinter printer(m_answer);
    size_t lettersRemaining = m_secret.Count();
    const bool result = m_guessTracker.RunGuessLoop([&]()
    {
        std::cout << "Enter a letter. ";
        printer.PrintWord();
        const Guess guess = Guess::TakeGuess();
        MutableLetter guessLetter;
        guessLetter.SetChar(guess.GetGuess().front());

        size_t occurrences = 0;
        const auto indices = m_secret.HasLetter(guessLetter);

        for (size_t ind : indices)
        {
            if(m_answer.MissingLetter(ind))
            {
                m_answer.SetLetter(ind, guessLetter);
                occurrences += 1;
            }
        }
        if (occurrences == 0)
        {
            // bummer
            std::cout << "Letter not found, try again" << std::endl;
        }

        lettersRemaining -= occurrences;
        if (lettersRemaining == 0)
        {
            return(true);
        }

        return(false);
    });
    if(result)
    {
        std::cout << "Winner" << std::endl;
    }
    else
    {
        std::cout << "Loser" << std::endl;
    }

    WordPrinter secretPrinter(m_secret);
    std::cout << "The word was ";
    secretPrinter.PrintWord();
    return(0);
}
