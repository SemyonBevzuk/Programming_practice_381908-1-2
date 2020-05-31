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
    std::cout << "\t -----�������� �����----\t\t������� � ��������� �������: " << myLastPurchase.size() << "\n\n";
}

void Cinema::PrintMainMenu()
{
    printHead();
    std::cout <<
        "\t������� ����:\n" <<
        "1-�������� ��� ������\n" <<
        "2-�������� ��� ������ �� �����\n" <<
        "3-������ ������\n" <<
        "4-�������� �������\n" <<
        "5-�����\n" <<
        "\n����� �����: ";
}

void Cinema::IncorrectAnswer()
{
    printHead();
    std::cout << "\n������: �������� �����";
    Waiting();
}

void Cinema::Waiting()
{
    std::cout << "\n������� ����� ������� ��� �����������...";
    getchar();
    getchar();
}

void Cinema::ShowAllSession()
{
    printHead();
    vector<Session> aSessions = myOffice.GetSessions();
    if (aSessions.empty()) cout << "��� �������!\n";
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
    cout << "������� �������� ������: ";
    getline(cin, name);
    vector<Session> aSessions = myOffice.GetSessions(name);
    if (aSessions.empty()) cout << "��� �������!\n";
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
    cout << "������� �������� ������: ";
    getline(cin, name);
    int day, hour, minut;
    cout << "������� ����� � �����(���� ��� ������): ";
    cin >> day >> hour >> minut;
    int tickets, Viptickets;
    cout << "������� ���-�� ����(������� vip): ";
    cin >> tickets>> Viptickets;
    double price = 0;
    myLastPurchase.clear();
    myLastPurchase = myOffice.GetTickets(name, DateTime(2020, 6, day, hour, minut), tickets, Viptickets, price);
    if (myLastPurchase.empty()) cout << "�� ������� ����!\n";
    else {
        cout << "���� ������:\n";
        for (size_t i = 0; i < myLastPurchase.size(); i++)
        {
            cout << myLastPurchase[i].ToString() << "\n";
        }
        cout << "����� ��������� " << price;
    }
    Waiting();
}

void Cinema::Cancle()
{
    printHead();
    if (myLastPurchase.size() == 0) cout << "��� ��������� �������!\n";
    else {
        myOffice.ReturnTickets(myLastPurchase);
        myLastPurchase.clear();
        cout << "������ ����������!\n";
    }
    Waiting();
}

