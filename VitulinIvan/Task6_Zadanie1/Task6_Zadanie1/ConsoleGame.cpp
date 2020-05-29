#include "ConsoleGame.h"

void ConsoleGame::printHead()
{
    system("cls");
    std::cout << "\t -----БЫКИ И КОРОВЫ----\t\tКол-во цифр в загаданном числе " << myGame.GetNumOfDigits() << "\n\n";
}


void ConsoleGame::PrintMainMenu()
{
    printHead();
    std::cout <<
        "\tГлавное меню:\n" <<
        "1-Начать игру\n" <<
        "2-Правила игры\n" <<
        "3-Выход из игры\n" <<
        "\nВыбор опции: ";
}

void ConsoleGame::IncorrectAnswer()
{
    printHead();
    std::cout << "\nОшибка: неверная опция";
    Waiting();
}

void ConsoleGame::Waiting()
{
    std::cout << "\nНажмите любую клавишу для продолжения...";
    getchar();
    getchar();
}

int ConsoleGame::ReadNumOfDigit()
{
    int aNumberOfDigits;
    cout << "Введите кол-во цифр в загадываемом числе (1-10): ";
    cin >> aNumberOfDigits;
    while (aNumberOfDigits > 10 || aNumberOfDigits < 1)
    {
        cout << "Кол-во должно быть больше в диапозоне от 1 до 10!\n";
        cout << "Введите кол-во цифр в загадываемом числе (1-10): ";
        cin >> aNumberOfDigits;
    }
    return aNumberOfDigits;
}

ULL ConsoleGame::ReadAnswer()
{
    cout << "\nПопробуйте угадать число: ";
    ULL anAnswer;
    cin >> anAnswer;
    return anAnswer;
}

bool ConsoleGame::PrintAttemptResult(AttemptResult theRes)
{
    if (theRes.isRigth)
    {
        cout << "\nВы угадали!\n";
        return true;
    }
    cout << "\nКоров: " << theRes.CawCount << "\tБыков: " << theRes.BullsCount<<"\n";
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
    cout << "Правила игры:\nИгрок выбирает длину загадываемого числа\n" <<
        "Компьютер «задумывает» n - значное число с неповторяющимися цифрами.\n" <<
        "Игрок делает попытку отгадать число – вводит n - значное число с неповторяющимися цифрами.\n" <<
        "Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе(т.е количество коров)\n" <<
        "и сколько угадано вплоть до позиции в загаданном числе(т.е. количество быков).\n" <<
        "Игрок делает попытки, пока не отгадает всю последовательность.\n\n" <<
        "Пример:\n" <<
        "Пусть n = 4.\n" <<
        "Пусть задумано тайное число «3219».\n" <<
        "Игрок ввел число «2310».\n" <<
        "Результат : две «коровы»(две цифры : «2» и «3» — угаданы на неверных позициях)\n" <<
        "и один «бык»(одна цифра «1» угадана вплоть до позиции).\n";
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

