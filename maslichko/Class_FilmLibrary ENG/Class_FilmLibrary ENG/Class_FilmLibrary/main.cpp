#include <iostream>
#include <fstream>
#include <cstdlib>
#include "FilmLibrary.h"
#include <windows.h>
#include <string>

int main()
{
    SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); //� ����� ������
    string title, producer, screenwriter, composer, data;
    long long fees;
    int menu, year, quantity;

    FilmLibrary f1;

    while (1)
    {
        cout << endl;
        cout << "1. Add film" << endl;
        cout << "2. Change film data selected by name" << endl;
        cout << "3. Find a film by title and year" << endl;
        cout << "4. Issue all films of a given director" << endl;
        cout << "5. Issue all films released in the selected year" << endl;
        cout << "6. Issue a given number of films with the highest fees" << endl;
        cout << "7. Issue a given number of films with the highest fees in the selected year" << endl;
        cout << "8. Find out the current number of films" << endl;
        cout << "9. Delete film by name" << endl;
        cout << "10. Save film library to file" << endl;
        cout << "11. Read film library from file" << endl;

        cout << endl << "Select the desired action: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cin.get(); // Eliminate the unextracted delimiter in the keyboard buffer (line feed character)
            cout << endl << "Enter film title: ";
            getline(cin, title);
            cout << endl << "Enter Director: ";
            getline(cin, producer);
            cout << endl << "Enter screenwriter: ";
            getline(cin, screenwriter);
            cout << endl << "Enter composer: ";
            getline(cin, composer);
            cout << endl << "Enter release date: ";
            getline(cin, data);
            cout << endl << "Enter fees: ";
            cin >> fees;
            
            f1.Add(title, producer, screenwriter, composer, data, fees);
            break;
        case 2:
            cin.get();
            cout << endl << "Enter the name of the film whose data you want to change: ";
            getline(cin, title);
            f1.Change(title);
            break;
        case 3:
            cin.get();
            cout << endl << "Enter film title: ";
            getline(cin, title);
            cout << endl << "Enter film release year: ";
            cin >> year;
            f1.Find(title, year);
            break;
        case 4:
            cin.get();
            cout << endl << "Enter Director: ";
            getline(cin, producer);
            f1.MovieSearch(producer);
            break;
        case 5:
            cin.get();
            cout << endl << "Enter year: ";
            cin >> year;
            f1.MovieSearch(year);
            break;
        case 6:
            cin.get();
            cout << endl << "Enter the number of film to display: ";
            cin >> quantity;
            f1.NumberFilms(quantity);
            break;
        case 7:
            cin.get();
            cout << endl << "Enter the number of film to display: ";
            cin >> quantity;
            cout << endl << "Enter year: ";
            cin >> year;
            f1.NumberFilms(quantity, year);
            break;
        case 8:
            cin.get();
            cout << endl << "The number of films in the library: " << f1.Total();
            break;
        case 9:
            cin.get();
            cout << endl << "Enter the name of the film you want to remove: ";
            getline(cin, title);
            f1.DeleteMovie(title);
            break;
        case 10:
            f1.SaveLibraru();
            break;
        case 11:
            f1.ReadLibraryr();
            break;
        }
    }

    system("pause");

}
