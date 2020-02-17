//
// Created by Kirill Lakhov on 17.02.2020.
//

#ifndef TASK3_WORD_H
#define TASK3_WORD_H

#include <string>
#include <vector>

class Word {
public:
    Word();
    Word(std::string eng, std::string translation);
    Word(std::string eng, std::vector<std::string> translations);
    void setTranslation(std::string translation);
    void setTranslation(std::vector<std::string> translations);
    void addTranslation(std::string translation);
    void addTranslation(std::vector<std::string> translations);
    void setWord(std::string word);
private:
    int id;
    std::string word;
    std::vector<std::string> translations;
    bool haveTranslation(std::string translation);
};


#endif //TASK3_WORD_H
