#include "ConsoleGame.h"

void ConsoleGame::printHead()
{
    system("cls");
    std::cout << "\t -----���� � ������----\t\t���-�� ���� � ���������� ����� " << myGame.GetNumOfDigits() << "\n\n";
}


void ConsoleGame::PrintMainMenu()
{
    printHead();
    std::cout <<
        "\t������� ����:\n" <<
        "1-������ ����\n" <<
        "2-������� ����\n" <<
        "3-����� �� ����\n" <<
        "\n����� �����: ";
}

void ConsoleGame::IncorrectAnswer()
{
    printHead();
    std::cout << "\n������: �������� �����";
    Waiting();
}

void ConsoleGame::Waiting()
{
    std::cout << "\n������� ����� ������� ��� �����������...";
    getchar();
    getchar();
}

int ConsoleGame::ReadNumOfDigit()
{
    int aNumberOfDigits;
    cout << "������� ���-�� ���� � ������������ ����� (1-10): ";
    cin >> aNumberOfDigits;
    while (aNumberOfDigits > 10 || aNumberOfDigits < 1)
    {
        cout << "���-�� ������ ���� ������ � ��������� �� 1 �� 10!\n";
        cout << "������� ���-�� ���� � ������������ ����� (1-10): ";
        cin >> aNumberOfDigits;
    }
    return aNumberOfDigits;
}

ULL ConsoleGame::ReadAnswer()
{
    cout << "\n���������� ������� �����: ";
    ULL anAnswer;
    cin >> anAnswer;
    return anAnswer;
}

bool ConsoleGame::PrintAttemptResult(AttemptResult theRes)
{
    if (theRes.isRigth)
    {
        cout << "\n�� �������!\n";
        return true;
    }
    cout << "\n�����: " << theRes.CawCount << "\t�����: " << theRes.BullsCount<<"\n";
    return false;

}

void ConsoleGame::NewGame()
{
    printHead();
    int aNumberOfDigits = ReadNumOfDigit();
    myGame.NewGame(aNumberOfDigits);
    while (!PrintAttemptResult(myGame.TryToGuess(ReadAnswer())));
    Waiting();

}

void ConsoleGame::PrintRules()
{
    printHead();
    cout << "������� ����:\n����� �������� ����� ������������� �����\n" <<
        "��������� ����������� n - ������� ����� � ���������������� �������.\n" <<
        "����� ������ ������� �������� ����� � ������ n - ������� ����� � ���������������� �������.\n" <<
        "��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����(�.� ���������� �����)\n" <<
        "� ������� ������� ������ �� ������� � ���������� �����(�.�. ���������� �����).\n" <<
        "����� ������ �������, ���� �� �������� ��� ������������������.\n\n" <<
        "������:\n" <<
        "����� n = 4.\n" <<
        "����� �������� ������ ����� �3219�.\n" <<
        "����� ���� ����� �2310�.\n" <<
        "��������� : ��� ��������(��� ����� : �2� � �3� � ������� �� �������� ��������)\n" <<
        "� ���� ����(���� ����� �1� ������� ������ �� �������).\n";
    Waiting();
}

void ConsoleGame::StartGame()
{
    MenuHandler();
}

void ConsoleGame::MenuHandler()
{
    bool toContinue = true;
    while (toContinue)
    {
        switch (Menu())
        {
        case 1: NewGame();                          break;
        case 2: PrintRules();                       break;
        case 3: toContinue = false;                 break;
        default: IncorrectAnswer();                 break;
        }
    }
}

int ConsoleGame::Menu()
{
    PrintMainMenu();
    int answer;
    std::cin >> answer;
    return answer;
}

