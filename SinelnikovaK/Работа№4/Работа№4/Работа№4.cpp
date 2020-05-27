#include "FilmLibrary.h"
using namespace std;
// Информация по работе с инструментами
void info()
{
    cout << "    /add - Добавить фильм\n    /change - изменить фильм по названию\n"
        << "    /search - найти фильм по названию и году\n    /producer - выдать фильмы заданного режиссёра\n"
        << "    /year - выдать фильмы за указанный год\n    /fund - выдать указанное количество самых кассовых фильмов\n"
        << "    /fundyear - выдать указанное количество самых кассовых фильмов за указанный год\n"
        << "    /count - выдать количество фильмов в библиотеке\n    /delete - удалить фильм по названию\n"
        << "    /print - вывести весь список фильмов\n    /clear - очистить экран\n    /help - помощь\n    /exit - выход\n";
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

// Переход в новую строку (считывание мусора)
void bin(istream& in)
{
    string bin;
    getline(in, bin);
}

int main()
{
    // Добавление кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Подготовка к работе... ";

    string command, filename;
    FilmLibrary library;

    filename = "Фильмы.txt";

    ReadFilms(library, filename);

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
        else if (command == "/add")
        {
            if (library.AddFilm())
                cout << "    Готово!\n";
            else
                cout << "    Такой фильм уже есть!\n";
        }
        else if (command == "/change")
        {
            string name;
            bin(cin);
            cout << "Введите название: ";
            getline(cin, name);
            if (library.ChangeFilm(name))
                cout << "    Готово!\n";
            else
                cout << "    Фильм не найден!\n";
        }
        else if (command == "/search")
        {
            string name;
            int year;
            bin(cin);
           cout << "Введите название фильма: ";
            getline(cin, name);
            cout << "Введите год премьеры фильма: ";
            cin >> year;
            if (!library.SearchFilm(name, year).Write())
                cout << "Фильм не найден!\n";
        }
        else if (command == "/producer")
        {
            string producer;
            bin(cin);
            cout << "Введите режиссера: ";
            getline(cin, producer);
            if (!library.ProducerFilms(producer).PrintLibrary())
                cout << "Фильмы данного режиссера не найдены!\n";
        }
        else if (command == "/year")
        {
            int year;
            cout << "Введите год: ";
            cin >> year;
            if (!library.YearFilms(year).PrintLibrary())
                cout << "Фильмов за указанный год нет!\n";
        }
        else if (command == "/fund")
        {
            int fund;
            cout << "Введите количество фильмов: ";
            cin >> fund;
            if (!library.FundFilms(fund).PrintLibrary())
                cout << "    Нет фильмов!\n";
        }
        else if (command == "/fundyear")
        {
            int year, fund;
           cout << "Введите количество фильмов и год: ";
            cin >> fund >> year;
            if (!library.FundYearFilms(fund, year).PrintLibrary())
               cout << "Фильмов за указанный год нет!\n";
        }
        else if (command == "/count")
        {
            cout << "Количество фильмов: " << library.CountFilms() << endl;
        }
        else if (command == "/delete")
        {
            string name;
            bin(cin);
            cout << "Введите название фильма: ";
            getline(cin, name);
            if (library.DeleteFilm(name))
                cout << "    Готово!\n";
            else
                cout << "    Фильм для удаления не найден!\n";
        }
        else if (command == "/print")
        {
            if (!library.PrintLibrary())
                cout << "    Нет фильмов!\n";
        }
        else
            cout << "    Данной команды нет!\n";
        cout << "    Введите команду: ";
        cin >> command;
        check(command);
    }

    clrscr();
    cout << "Завершение работы...\n";
    SaveFilms(library, filename);

    return 0;
}

