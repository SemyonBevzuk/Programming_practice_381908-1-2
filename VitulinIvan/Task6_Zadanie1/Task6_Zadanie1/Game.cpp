#include "Game.h"
#include <time.h>
#include <algorithm>
#include <string>

void Game::NewGame(unsigned short theNumOfDigits)
{
    if (theNumOfDigits > 10) throw "The number of digits must be less or equal 10!";
    GenerateTarget(theNumOfDigits);
}

AttemptResult Game::TryToGuess(ULL theAnswer)
{
    vector<uchar> anAnswerDigits;
    while (theAnswer!=0)
    {
        anAnswerDigits.push_back(theAnswer % 10);
        theAnswer /= 10;
    }
    if (anAnswerDigits.size() != myTargetDigits.size()) 
        throw "The number of digits must be equal to" + to_string(myTargetDigits.size());
    reverse(anAnswerDigits.begin(), anAnswerDigits.end());
    int aBulls = 0, aCaws = 0;
    for (size_t i = 0; i < myTargetDigits.size(); i++)
    {
        if (anAnswerDigits[i] == myTargetDigits[i]) aBulls++;
        else {
            for (size_t j = 0; j < myTargetDigits.size(); j++)
                if (anAnswerDigits[i] == myTargetDigits[j]) 
					aCaws++;
        }
    }
    bool isRigth = false;
    if (aBulls == myTargetDigits.size()) isRigth = true;
    return AttemptResult(isRigth, aCaws, aBulls);
}

int Game::GetNumOfDigits()
{
    return myTargetDigits.size();
}

void Game::GenerateTarget(unsigned short theNumOfDigits)
{
    srand(time(0));
    vector<uchar> aDigits = { 0,1,2,3,4,5,6,7,8,9 };
    for (size_t i = 0; i < theNumOfDigits; i++)
    {
        int aNextDigitIndex = rand() % aDigits.size();
        myTargetDigits.push_back(aDigits[aNextDigitIndex]);
        aDigits.erase(aDigits.begin() + aNextDigitIndex);
    }
}
