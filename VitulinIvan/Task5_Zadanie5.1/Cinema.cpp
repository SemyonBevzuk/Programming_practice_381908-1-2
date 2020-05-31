#include "Cinema.h"

Cinema::Cinema(TicketOffice to) {
    myOffice = to;
}
void Cinema::Start()
{
    MenuHandler();
}

void Cinema::MenuHandler()
{
    bool toContinue = true;
    while (toContinue)
    {
        switch (Menu())
        {
        case 1: ShowAllSession();             break;
        case 2: ShowAllSessionByFilm();             break;
        case 3: BuyTickets();                       break;
        case 4: Cancle();                           break;
        case 5: toContinue = false;                 break;
        default: IncorrectAnswer();                 break;
        }
    }
}

int Cinema::Menu()
{
    PrintMainMenu();
    int answer;
    std::cin >> answer;
    getchar();
    return answer;
}

void Cinema::printHead()
{
    system("cls");
    std::cout << "\t -----БИЛЕТНАЯ КАССА----\t\tБилетов в последней покупке: " << myLastPurchase.size() << "\n\n";
}

void Cinema::PrintMainMenu()
{
    printHead();
    std::cout <<
        "\tГлавное меню:\n" <<
        "1-Показать все сеансы\n" <<
        "2-Показать все сеансы на фильм\n" <<
        "3-Купить билеты\n" <<
        "4-Отменить покупку\n" <<
        "5-Выход\n" <<
        "\nВыбор опции: ";
}

void Cinema::IncorrectAnswer()
{
    printHead();
    std::cout << "\nОшибка: неверная опция";
    Waiting();
}

void Cinema::Waiting()
{
    std::cout << "\nНажмите любую клавишу для продолжения...";
    getchar();
    getchar();
}

void Cinema::ShowAllSession()
{
    printHead();
    vector<Session> aSessions = myOffice.GetSessions();
    if (aSessions.empty()) cout << "Нет сеансов!\n";
    else {
        for (size_t i = 0; i < aSessions.size(); i++)
        {
            cout << aSessions[i].ToString() << "\n";
        }
    }
    Waiting();
}

void Cinema::ShowAllSessionByFilm()
{
    printHead();
    string name;
    cout << "Введите название фильма: ";
    getline(cin, name);
    vector<Session> aSessions = myOffice.GetSessions(name);
    if (aSessions.empty()) cout << "Нет сеансов!\n";
    else {
        for (size_t i = 0; i < aSessions.size(); i++)
        {
            cout << aSessions[i].ToString() << "\n";
        }
    }
    
    Waiting();
}

void Cinema::BuyTickets()
{
    printHead();
    string name;
    cout << "Введите название фильма: ";
    getline(cin, name);
    int day, hour, minut;
    cout << "Введите число и время(день час минуты): ";
    cin >> day >> hour >> minut;
    int tickets, Viptickets;
    cout << "Введите кол-во мест(обычные vip): ";
    cin >> tickets>> Viptickets;
    double price = 0;
    myLastPurchase.clear();
    myLastPurchase = myOffice.GetTickets(name, DateTime(2020, 6, day, hour, minut), tickets, Viptickets, price);
    if (myLastPurchase.empty()) cout << "Не хватило мест!\n";
    else {
        cout << "Ваши билеты:\n";
        for (size_t i = 0; i < myLastPurchase.size(); i++)
        {
            cout << myLastPurchase[i].ToString() << "\n";
        }
        cout << "Общая стоимость " << price;
    }
    Waiting();
}

void Cinema::Cancle()
{
    printHead();
    if (myLastPurchase.size() == 0) cout << "Нет купленных билетов!\n";
    else {
        myOffice.ReturnTickets(myLastPurchase);
        myLastPurchase.clear();
        cout << "Билеты возвращены!\n";
    }
    Waiting();
}

