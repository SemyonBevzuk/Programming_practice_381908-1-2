#pragma once
#include"Dictionary.h"
class MainMenu {
public:
    MainMenu();
    void Start();
private:

    void MenuHandler();
    int Menu();

    void printHead();
    void PrintMainMenu();
    void IncorrectAnswer();
    void Waiting();

    void AddWord();
    void FindWord();
    void TranslateForWord();
    void AddTranslateToWord();
    void DeleteWord();
    void LoadFromFile();
    void SaveToFile();

    Dictionary myDict;
};

//добавить в словарь слово и его перевод
//изменить перевод указанного слова,
//узнать перевод выбранного слова,
//проверить наличие слова в словаре,
//узнать число слов в словаре,
//сохранить словарь в файл, считать словарь из файла.
//перегрузить операции присваивания и объединения словарей.