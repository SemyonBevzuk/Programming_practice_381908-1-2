//
// Created by Kirill Lakhov on 13.03.2020.
//

#include <codecvt>
#include <utility>
#include "../include/Film.h"
#include "regex"

Film::Film(string name, string producer, string screenwriter, string composer, Date date, int fees) {
    this->name =name;
    this->producer = Film::parser(producer) ? producer : "НеУстановлено";
    this->screenwriter = Film::parser(screenwriter) ? screenwriter : "НеУстановлено";
    this->composer = Film::parser(composer) ? composer : "НеУстановлено";
    this->date = date;
    this->fees = fees;
}

bool Film::parser(const string &str) {
    regex oneWord(R"(^[a-zA-Z]+$)");
    smatch match;
    return regex_search(str,match,oneWord);
}
