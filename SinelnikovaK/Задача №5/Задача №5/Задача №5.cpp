#include "RailTicketOffice.h"
using namespace std;

// Информация по работе с инструментами
void info()
{
    cout << "    /help - помощь\n    /new - создание нового билета\n"
        << "    /clear - очистка экрана\n    /print - вывод билета\n    /exit - выход\n";
}

// Очистка экрана
void clrscr()
{
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    CONSOLE_SCREEN_BUFFER_INFO buf;
    GetConsoleScreenBufferInfo(Console, &buf);

    WORD Attr;
    DWORD Count;
    COORD pos = buf.dwCursorPosition;
    ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

    int col = Attr;
    int width = buf.dwSize.X;
    int height = buf.dwSize.Y;

    COORD zpos;
    zpos.X = 0;
    zpos.Y = 0;
    SetConsoleCursorPosition(Console, zpos);

    FillConsoleOutputAttribute(Console, col, width * height, zpos, &Count);
    FillConsoleOutputCharacter(Console, ' ', width * height, zpos, &Count);
}

// Обработка команд
void check(string& str)
{
    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
        i++;
    }
}

int main()
{
    // Добавление кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    RailTicketOffice office;
    Ticket ticket;
    string command;

    clrscr();
    cout << "/help - помощь\n    Введите команду: ";
    cin >> command;

    check(command);
    while (command != "/exit")
    {
        if (command == "/help")
            info();
        else if (command == "/clear")
            clrscr();
        else if (command == "/new")
        {
            office.clearTicket();
            ticket = office.newTicket();
            clrscr();
            if (!(ticket == Ticket()))
                cout << "Билет сформирован!\n";
        }
        else if (command == "/print")
        {
            if (!ticket.Print())
                cout << "Нет информации о билетах";
            else
                ticket.saveTicket();
        }
        else
            cout << "    Данной команды нет!\n";
        cout << "    Введите команду: ";
        cin >> command;
        check(command);
    }
    clrscr();

    return 0;
}
