#pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned char uchar;
typedef unsigned long long ULL;

struct AttemptResult 
{
    int CawCount;
    int BullsCount;
    bool isRigth;
    AttemptResult(bool isRigth, int Caws, int Bulls) : isRigth(isRigth), CawCount(Caws), BullsCount(Bulls) {};
};

class Game
{
    vector<uchar> myTargetDigits;
public:
    void NewGame(unsigned short theNumOfDigits);
    AttemptResult TryToGuess(ULL theAnswer);
    int GetNumOfDigits();
private:
    void GenerateTarget(unsigned short theNumOfDigits);
};

