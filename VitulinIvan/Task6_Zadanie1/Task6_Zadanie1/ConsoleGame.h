#pragma once
#include"Game.h"

class ConsoleGame
{
    Game myGame;
    int myNumberOfAttempts = 0;
    void printHead();
    void NewGame();
    void PrintRules();
    void MenuHandler();
    int Menu();
    void PrintMainMenu();
    void IncorrectAnswer();
    void Waiting();

    int ReadNumOfDigit();
    ULL ReadAnswer();
    bool PrintAttemptResult(AttemptResult theRes);
public:
    void StartGame();
};

