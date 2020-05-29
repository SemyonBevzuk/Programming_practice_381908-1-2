#include "Dictionary.h"
#include <fstream>
#include <string>
#include <locale>

Dictionary::Dictionary()
{
}

Word Parse(string theLine) {
    setlocale(LC_ALL, "Russian");
    Word aRes;
    string aWord = "";
    bool aStartTranslate = false;
    for (size_t i = 0; i < theLine.size(); i++)
    {
        if (theLine[i] == ' ')
        {
            if (aWord != "")
            {
                if (aStartTranslate)
                    aRes.AddTranslate(aWord);
                else
                {
                    aRes.ChangeWord(aWord);
                    aStartTranslate = true;
                }
                aWord = "";
            }

        }
        else
            aWord += theLine[i];
    }
    if (aWord != "")
    {
        if (aStartTranslate)
            aRes.AddTranslate(aWord);
        else
            aRes.ChangeWord(aWord);
    }
    return aRes;
}

Dictionary::Dictionary(string theWordsDataFilePath)
{
    ifstream fin;
    fin.open(theWordsDataFilePath);
    string aLine;
    while (getline(fin, aLine))
    {
        AddWord(Parse(aLine));
    }
    
}

bool Dictionary::AddWord(string theWord, string theTranslate)
{
    Word aTargetWord(theWord, theTranslate);
    auto aPosOfTarget = find(myWords.begin(), myWords.end(), aTargetWord);
    if (aPosOfTarget == myWords.end()) {
        myWords.push_back(aTargetWord);
        return true;
    }
    return false;
}

bool Dictionary::AddWord(Word theWord)
{
    auto aPosOfTarget = find(myWords.begin(), myWords.end(), theWord);
    if (aPosOfTarget == myWords.end()) {
        myWords.push_back(theWord);
        return true;
    }
    return false;
}

bool Dictionary::DeleteWord(string theWord)
{
    Word aTargetWord(theWord, "");
    auto aPosOfTarget = find(myWords.begin(), myWords.end(), aTargetWord);
    if (aPosOfTarget != myWords.end()) {
        myWords.erase(aPosOfTarget);
        return true;
    }
    return false;
}

bool Dictionary::DeleteWord(Word theWord)
{
    auto aPosOfTarget = find(myWords.begin(), myWords.end(), theWord);
    if (aPosOfTarget != myWords.end()) {
        myWords.erase(aPosOfTarget);
        return true;
    }
    return false;
}

bool Dictionary::ChangeWord(string theWord, string theTargetTranslate, string theNewTranslate)
{
    int aPos = FindWord(theWord);
    if (aPos == -1) return false;
    (myWords[aPos] -= theTargetTranslate) += theNewTranslate;
}

vector<string> Dictionary::GetTranslates(string theWord)
{
    int aPos = FindWord(theWord);
    if (aPos == -1) throw "Cant find the target word in dictionary!";
    return myWords[aPos].getTranslates();
}

int Dictionary::FindWord(string theWord)
{
    for (size_t i = 0; i < myWords.size(); i++)
    {
        if (theWord == myWords[i].getWord()) return i;
    }
    return -1;
}

size_t Dictionary::GetNumbersOfWords()
{
    return myWords.size();
}

void Dictionary::SaveToFile(string thePath)
{
    ofstream fout;
    fout.open(thePath);
    for (int i = 0; i < myWords.size(); i++)
    {
        fout << myWords[i].ToString() << endl;
    }
}

void Dictionary::FillFromFile(string thePath)
{
    myWords.clear();
    ifstream fin;
    fin.open(thePath);
    string aLine;
    while (getline(fin, aLine))
    {
        AddWord(Parse(aLine));
    }
}

Word& Dictionary::operator[](size_t pos)
{
    if (pos >= myWords.size()) throw "Out of range";
    return myWords[pos];
}
