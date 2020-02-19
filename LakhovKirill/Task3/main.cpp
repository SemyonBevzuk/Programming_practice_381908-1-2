//
// Created by Kirill Lakhov on 19.02.2020.
//
#include "Word.h"
#include "Dictionary.h"
#include "vector"
#include "iostream"
#include "string"

int main(){
    setlocale(LC_ALL, "Russian");
    //Работа со словами

    //Создание слова
    auto word1 = new Word(); //без перевода и слова
    auto word2 = new Word("cat","кот"); //слово и один перевод
    auto word3 = new Word("cake", vector<string>{"торт","пирожное"}); //слово и несколько перводов

    //установить слово
    word1->setWord("dog");

    //уставновить перевод(заменяет имеющийся) (можно задать несколько переводов вектором)
    word1->setTranslation("собака");

    //добавить перевод(если такого еще нет, добавит) (можно задать несколько переводов вектором)
    word1->addTranslation("собачка");

    word3->setTranslation(vector<string>{"торт123","!@#."}); //строки не из букв не будут допущены

    //Работа со словарем

    //Пустой словарь
    auto dictionary  = new Dictionary();

    //Словарь из файла

    //**Все операции над словарем возвращают true/false означающие успех или неудачу операции**

    //Добавить слова в словарь
    dictionary->addWord(word1);
    dictionary->addWord(word2);
    dictionary->addWord(word3);
    //изменения на слове влияют на него внутри словаря (если они добавлены, разумеется)
    word1->addTranslation("пес");

    //Если слово с таким значением уже существует, оно будет полностью перезаписано
    auto word4 = new Word("cat", "кошка");
    dictionary->addWord(word4);

    //Используя специальный метод добавления слова, в случае его существования в словаре, переводы будут смешаны
    dictionary->mergeAddWord(word2);

    //проверить наличие слова в словаре (0 - если слова нет, иначе его id)
    dictionary->find("cat");

    //Получить ссылку на слово в словаре (перед этим желательно проверить его наличие в словаре)
    if(dictionary->find("dog")) auto word5 = dictionary->get("dog");

    //Узнать количество слов в словаре
    int amount = dictionary->wordsCount();

    //Записать словарь со всеми изменениями в текстовый файл (.txt)
    dictionary->out("myDictionary.txt");
    return 0;
}

