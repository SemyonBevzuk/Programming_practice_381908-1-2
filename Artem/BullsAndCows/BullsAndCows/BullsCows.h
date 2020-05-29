#pragma once
#include <iostream>
#include <ctime>
#define MAX 9
using namespace std;
class Game {
private:
    int kol = 0;
    int nOurs;       
    int bulls = 0;	 
    int cows = 0;	  
    char mech[MAX];  
    char ours[MAX]; 
    int raz = 0;
public:
    void SetNum(char* n) 
    {
        for (int i = 0; i < kol; i++) {
            mech[i] = n[i];
        }
    }
    Game(int i);
    Game() { kol = 0; }
    ~Game() {}
    void game1();
    void Move2Array(int value, char ar[], int n);
    bool SameDigits(char ar[], int n);
    void rand_4(char ar[], int n);
};