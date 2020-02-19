//
// Created by Kirill Lakhov on 19.02.2020.
//
#include "Word.h"
#include "vector"
#include "iostream"
#include "string"

int main(){
    //Работа со словами

    //Создание слова
    auto word1 = new Word(); //без перевода и слова
    auto word2 = new Word("cat","кот"); //слово и один перевод
    auto word3 = new Word("cake", vector<string>{"торт","пирожное"}); //слово и несколько перводов

    //установить слово
    word1->setWord("dog");

    //уставновить перевод(заменяет имеющиеся) (можно задать несколько переводов вектором)
    word1->setTranslation("собака");

    //добавить перевод(если такого еще нет, добавит) (можно задать несколько переводов вектором)
    word1->addTranslation("собачка");



    return 0;
}

