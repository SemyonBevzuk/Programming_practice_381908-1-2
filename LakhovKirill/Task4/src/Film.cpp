//
// Created by Kirill Lakhov on 13.03.2020.
//

#include <codecvt>
#include <utility>
#include "../include/Film.h"
#include "regex"

Film::Film(string name, string producer, string writer, string composer, Date date, int fees) {
    this->name = Film::parser(name) ? name : "НеУстановлено";
    this->producer = Film::parser(producer) ? producer : "НеУстановлено";
    this->writer = Film::parser(writer) ? writer : "НеУстановлено";
    this->composer = Film::parser(composer) ? composer : "НеУстановлено";
    this->date = date;
    this->fees = fees;
}

bool Film::parser(const string &str) {
    wregex oneWord(L"(^[a-zA-Zа-яА-ЯёЁ]+$)");
    smatch match;
    return regex_search(wstring_convert<codecvt_utf8<wchar_t>, wchar_t>().from_bytes(str), oneWord);
}
