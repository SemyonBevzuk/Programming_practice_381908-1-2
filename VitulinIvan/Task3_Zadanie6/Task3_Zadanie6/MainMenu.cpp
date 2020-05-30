#include "MainMenu.h"
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

MainMenu::MainMenu()
{
}

void MainMenu::Start()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    MenuHandler();
}

void MainMenu::MenuHandler()
{
    bool toContinue = true;
    while (toContinue)
    {
        switch (Menu())
        {
        case 1: AddWord();                          break;
        case 2: FindWord();                         break;
        case 3: TranslateForWord();                 break;
        case 4: AddTranslateToWord();               break;
        case 5: DeleteWord();                       break;
        case 6: LoadFromFile();                     break;
        case 7: SaveToFile();                       break;
        case 8: toContinue = false;                 break;
        default: IncorrectAnswer();                 break;
        }
    }
}

int MainMenu::Menu()
{
    PrintMainMenu();
    int answer;
    std::cin >> answer;
    return answer;
}

void MainMenu::printHead()
{
    system("cls");
    std::cout << "\t -----АНГЛО-РУССКИЙ СЛОВАРЬ----\t\tВсего слов в словаре: " << myDict.GetNumbersOfWords() << "\n\n";
}

void MainMenu::PrintMainMenu()
{
    printHead();
    std::cout <<
        "\tГлавное меню:\n" <<
        "1-Добавить слово в словарь\n" <<
        "2-Найти слово в словаре\n" <<
        "3-Перевести введённое слово\n" <<
        "4-Добавить перевод к слову\n" <<
        "5-Удалить слово из словаря\n" <<
        "6-Загрузить слова из файла\n" <<
        "7-Сохранить слова в файл\n" <<
        "8-Выход\n" <<
        "\nВыбор опции: ";
}

void MainMenu::IncorrectAnswer()
{
    printHead();
    std::cout << "\nОшибка: неверная опция";
    Waiting();
}

void MainMenu::Waiting()
{
    std::cout << "\nНажмите любую клавишу для продолжения...";
    getchar();
}

void MainMenu::AddWord()
{
    setlocale(LC_ALL, "Russian");
    printHead();
    cout << "Добавление слова\n\n";
    string aWord, aTranslate;
    getchar();
    cout << "Введите слово на английском языке: ";
    getline(cin, aWord);
    cout << "Введите перевод: ";
    getline(cin, aTranslate);
    if (myDict.AddWord(aWord, aTranslate))
        cout << "Успешно!\n";
    else
        cout << "Данное слово уже есть в словаре!\n";
    Waiting();
}

void MainMenu::FindWord()
{
    printHead();
    cout << "Поиск слова\n\n";
    string aWord;
    getchar();
    cout << "Введите слово для поиска: ";
    getline(cin, aWord);
    
    if (myDict.FindWord(aWord)!=-1)
        cout << "Такое слово есть в словаре!\n";
    else
        cout << "Данное слово не найдено в словаре!\n";
    Waiting();
}

void MainMenu::TranslateForWord()
{
    printHead();
    cout << "Перевод\n\n";
    string aWord;
    getchar();
    cout << "Введите слово для перевода: ";
    getline(cin, aWord);

    if (myDict.FindWord(aWord) != -1)
    {
        cout << "Варианты перевода: \n";
        auto aTranslates = myDict.GetTranslates(aWord);
        for (size_t i = 0; i < aTranslates.size()-1; i++)
        {
            cout << aTranslates[i] + ", ";
        }
        cout << aTranslates[aTranslates.size() - 1] << "\n\n";
    }
    else
        cout << "Данное слово не найдено в словаре!\n";
    Waiting();
}

void MainMenu::AddTranslateToWord()
{
    setlocale(LC_ALL, "Russian");
    printHead();
    cout << "Добавить вариант перевода\n\n";
    string aWord, aTranslate;
    getchar();
    cout << "Введите слово: ";
    getline(cin, aWord);
    cout << "Введите вариант перевода: \n";
    getline(cin, aTranslate);
    int aPos = myDict.FindWord(aWord);
    if (aPos != -1)
    {
        if (myDict[aPos].AddTranslate(aTranslate)) {
            cout << "Успешно!\n";
        } else {
            cout << "Данное данный вариант перевода уже есть!\n";
        }
    } else {
        Word aNewWord(aWord, aTranslate);
        myDict.AddWord(aNewWord);
        cout << "Данное слово не найдено в словаре? и было добавленно в него!\n";
    }
    Waiting();
}

void MainMenu::DeleteWord()
{
    printHead();
    cout << "Удалить слова\n\n";
    string aWord, aTranslate;
    getchar();
    cout << "Введите слово: ";
    getline(cin, aWord);
    int aPos = myDict.FindWord(aWord);
    if (myDict.DeleteWord(aWord))
        cout << "Успешно!\n";
    else
        cout << "Данное слово не найдено в словаре!\n";
    Waiting();
}

void MainMenu::LoadFromFile()
{
    printHead();
    getchar();
    std::cout << "Чтение из файла\n\n";
    std::string aPath;
    std::cout << "Укажите путь: ";
    std::getline(std::cin, aPath);
    myDict.FillFromFile(aPath);
    std::cout << "Прочитанно " << myDict.GetNumbersOfWords() << " слов";
    Waiting();
    
}

void MainMenu::SaveToFile()
{
    printHead();
    cout << "Сохранение в файл\n\n";
    string aPath;
    getchar();
    cout << "Укажите путь: ";
    getline(cin, aPath);
    myDict.SaveToFile(aPath);
    std::cout << "Записанно " + aPath;
    Waiting();
}
