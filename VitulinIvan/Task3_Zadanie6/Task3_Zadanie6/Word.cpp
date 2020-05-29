#include "Word.h"

Word::Word()
{
}

Word::Word(string theWord, string theTranslate)
{
    myWord = theWord;
    myTranslates.push_back(theTranslate);
}

Word::Word(const Word& copy)
{
    myWord = copy.myWord;
    myTranslates = copy.myTranslates;
}

string Word::getWord()
{
    return myWord;
}

const vector<string>& Word::getTranslates()
{
    return myTranslates;
}

string& Word::operator[](size_t pos)
{
    if (pos >= myTranslates.size()) throw "Out of range";
    return myTranslates[pos];
}

Word& Word::operator+=(string theNextTranslate)
{
    AddTranslate(theNextTranslate);
    return *this;
}

Word& Word::operator-=(string theRemovingTranslete)
{
    DeletTranslate(theRemovingTranslete);
    return *this;
}

bool Word::operator==(const Word& theTarget) const
{
    return myWord == theTarget.myWord;
}

bool Word::AddTranslate(string theNextTranslate)
{
    auto aPosOfTarget = find(myTranslates.begin(), myTranslates.end(), theNextTranslate);
    if (aPosOfTarget == myTranslates.end()) {
        myTranslates.push_back(theNextTranslate);
        return true;
    }
    return false;
}

bool Word::DeletTranslate(string theRemovingTranslete)
{
    auto aPosOfTarget = find(myTranslates.begin(), myTranslates.end(), theRemovingTranslete);
    if (aPosOfTarget == myTranslates.end()) {
        myTranslates.erase(aPosOfTarget);
        return true;
    }
    return false;
}

void Word::ClearTranslates()
{
    myTranslates.clear();
}

void Word::ChangeWord(string theNewWord)
{
    myWord = theNewWord;
}

string Word::ToString()
{
    string aResult = myWord;
    for (size_t i = 0; i < myTranslates.size(); i++)
    {
        aResult +=" " + myTranslates[i];
    }
    return aResult;
}
