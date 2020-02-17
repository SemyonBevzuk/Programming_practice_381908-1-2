//
// Created by Kirill Lakhov on 17.02.2020.
//
#include "Word.h"
#include <vector>

Word::Word(){
    this->word = "";
    this->translations = std::vector<std::string>();
}

Word::Word(std::string eng, std::string translation) {
    this->word = eng;
    std::vector<std::string> a;
    a.push_back(translation);
    this->translations = a;
}

Word::Word(std::string eng, std::vector<std::string> translations) {
    this->word = eng;
    this->translations = translations;
}

void Word::setTranslation(std::string translation) {
    std::vector<std::string> a;
    a.push_back(translation);
    this->translations = a;
}
void Word::setTranslation(std::vector<std::string> translations) {
    this->translations = translations;
}

void Word::setWord(std::string word){
    this->word = word;
}
void Word::addTranslation(std::string translation) {
    if(this->haveTranslation(translation)) return;
    this->translations.push_back(translation);
}

void Word::addTranslation(std::vector<std::string> translations) {
    for (const auto & translation : translations) {
        if(this->haveTranslation(translation)) continue;
        this->translations.push_back(translation);
    }
}

bool Word::haveTranslation(std::string translation) {
    for (const auto & i : this->translations) {
        if(i == translation) return false;
    }
    return true;
}