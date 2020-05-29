#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Word
{
    string myWord;
    vector<string> myTranslates;
public:
    Word();
    Word(string theWord, string theTranslate);
    Word(const Word& copy);
    string getWord();
    const vector<string>& getTranslates();
    string& operator[](size_t pos);
    Word& operator+=(string theNextTranslate);
    Word& operator-=(string theRemovingTranslete);
    bool operator==(const Word& theTarget) const;
    bool AddTranslate(string theNextTranslate);
    bool DeletTranslate(string theRemovingTranslete);
    void ClearTranslates();
    void ChangeWord(string theNewWord);
    string ToString();
};

