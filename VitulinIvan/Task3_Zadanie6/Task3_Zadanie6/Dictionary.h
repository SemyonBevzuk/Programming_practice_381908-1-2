#pragma once
#include"Word.h"
class Dictionary
{
    vector<Word> myWords;
public:
    Dictionary();
    Dictionary(string theWordsDataFilePath);
    bool AddWord(string theWord, string theTranslate);
    bool AddWord(Word theWord);
    bool DeleteWord(string theWord);
    bool DeleteWord(Word theWord);
    bool ChangeWord(string theWord, string theTargetTranslate, string theNewTranslate);
    vector<string> GetTranslates(string theWord);
    int FindWord(string theWord);
    size_t GetNumbersOfWords();
    void SaveToFile(string thePath);
    void FillFromFile(string thePath);
    Word& operator[] (size_t pos);


};

