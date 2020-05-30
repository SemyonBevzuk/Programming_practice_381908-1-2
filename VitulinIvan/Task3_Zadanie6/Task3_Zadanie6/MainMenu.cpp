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
    std::cout << "\t -----�����-������� �������----\t\t����� ���� � �������: " << myDict.GetNumbersOfWords() << "\n\n";
}

void MainMenu::PrintMainMenu()
{
    printHead();
    std::cout <<
        "\t������� ����:\n" <<
        "1-�������� ����� � �������\n" <<
        "2-����� ����� � �������\n" <<
        "3-��������� �������� �����\n" <<
        "4-�������� ������� � �����\n" <<
        "5-������� ����� �� �������\n" <<
        "6-��������� ����� �� �����\n" <<
        "7-��������� ����� � ����\n" <<
        "8-�����\n" <<
        "\n����� �����: ";
}

void MainMenu::IncorrectAnswer()
{
    printHead();
    std::cout << "\n������: �������� �����";
    Waiting();
}

void MainMenu::Waiting()
{
    std::cout << "\n������� ����� ������� ��� �����������...";
    getchar();
}

void MainMenu::AddWord()
{
    setlocale(LC_ALL, "Russian");
    printHead();
    cout << "���������� �����\n\n";
    string aWord, aTranslate;
    getchar();
    cout << "������� ����� �� ���������� �����: ";
    getline(cin, aWord);
    cout << "������� �������: ";
    getline(cin, aTranslate);
    if (myDict.AddWord(aWord, aTranslate))
        cout << "�������!\n";
    else
        cout << "������ ����� ��� ���� � �������!\n";
    Waiting();
}

void MainMenu::FindWord()
{
    printHead();
    cout << "����� �����\n\n";
    string aWord;
    getchar();
    cout << "������� ����� ��� ������: ";
    getline(cin, aWord);
    
    if (myDict.FindWord(aWord)!=-1)
        cout << "����� ����� ���� � �������!\n";
    else
        cout << "������ ����� �� ������� � �������!\n";
    Waiting();
}

void MainMenu::TranslateForWord()
{
    printHead();
    cout << "�������\n\n";
    string aWord;
    getchar();
    cout << "������� ����� ��� ��������: ";
    getline(cin, aWord);

    if (myDict.FindWord(aWord) != -1)
    {
        cout << "�������� ��������: \n";
        auto aTranslates = myDict.GetTranslates(aWord);
        for (size_t i = 0; i < aTranslates.size()-1; i++)
        {
            cout << aTranslates[i] + ", ";
        }
        cout << aTranslates[aTranslates.size() - 1] << "\n\n";
    }
    else
        cout << "������ ����� �� ������� � �������!\n";
    Waiting();
}

void MainMenu::AddTranslateToWord()
{
    setlocale(LC_ALL, "Russian");
    printHead();
    cout << "�������� ������� ��������\n\n";
    string aWord, aTranslate;
    getchar();
    cout << "������� �����: ";
    getline(cin, aWord);
    cout << "������� ������� ��������: \n";
    getline(cin, aTranslate);
    int aPos = myDict.FindWord(aWord);
    if (aPos != -1)
    {
        if (myDict[aPos].AddTranslate(aTranslate)) {
            cout << "�������!\n";
        } else {
            cout << "������ ������ ������� �������� ��� ����!\n";
        }
    } else {
        Word aNewWord(aWord, aTranslate);
        myDict.AddWord(aNewWord);
        cout << "������ ����� �� ������� � �������? � ���� ���������� � ����!\n";
    }
    Waiting();
}

void MainMenu::DeleteWord()
{
    printHead();
    cout << "������� �����\n\n";
    string aWord, aTranslate;
    getchar();
    cout << "������� �����: ";
    getline(cin, aWord);
    int aPos = myDict.FindWord(aWord);
    if (myDict.DeleteWord(aWord))
        cout << "�������!\n";
    else
        cout << "������ ����� �� ������� � �������!\n";
    Waiting();
}

void MainMenu::LoadFromFile()
{
    printHead();
    getchar();
    std::cout << "������ �� �����\n\n";
    std::string aPath;
    std::cout << "������� ����: ";
    std::getline(std::cin, aPath);
    myDict.FillFromFile(aPath);
    std::cout << "���������� " << myDict.GetNumbersOfWords() << " ����";
    Waiting();
    
}

void MainMenu::SaveToFile()
{
    printHead();
    cout << "���������� � ����\n\n";
    string aPath;
    getchar();
    cout << "������� ����: ";
    getline(cin, aPath);
    myDict.SaveToFile(aPath);
    std::cout << "��������� " + aPath;
    Waiting();
}
