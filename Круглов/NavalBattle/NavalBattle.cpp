#include <iostream>
#include <string>
#include"Battlefield.h"
#include"ArtInt.h"
#include<locale>

using namespace std;

int stocoor(string s) {
    if (s[0] > 64 && s[0] < 75)
        return s[0]-65;
    return 65000;
}

string coortos(int a) {
    switch (a){
    case 0:
        return "A";
    case 1:
        return "B";
    case 2:
        return "C";
    case 3:
        return "D";
    case 4:
        return "E";
    case 5:
        return "F";
    case 6:
        return "G";
    case 7:
        return "H";
    case 8:
        return "I";
    case 9:
        return "J";
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    Battlefield field;
    cout << field;
    // создание кораблей ------------------------------------------------------------------------
    //             ------------------------------------------------------------------------------
    //             ------------------------------------------------------------------------------
    string x, x1;
    int y, y1;
    bool correctness = false;
    while (!correctness) {
        cout << "Введите координаты 4-х палубного корабля через пробел (Например A 1 A 4): ";
        cin >> x >> y >> x1 >> y1;
        y--;
        y1--;
        if (((y - y1 == 0 && abs(stocoor(x) - stocoor(x1)) == 3)) || ((abs(y - y1) == 3 && abs(stocoor(x) - stocoor(x1)) == 0)))
            if (field.isCorrectlyLocation(stocoor(x), y, stocoor(x1), y1, true)) {
                Ship ship4(stocoor(x), y, stocoor(x1), y1);
                field.addShip(ship4, true);
                correctness = true;
                system("cls");
                cout << field;
            }
        if (!correctness)
            cout << "Координаты введены неверно\n";
    }
    for (int i = 0; i < 2; i++) {
        correctness = false;
        while (!correctness) {
            cout << "Введите координаты 3-х палубного корабля через пробел: ";
            cin >> x >> y >> x1 >> y1;
            y--;
            y1--;
            if (((y - y1 == 0 && abs(stocoor(x) - stocoor(x1)) == 2)) || ((abs(y - y1) == 2 && abs(stocoor(x) - stocoor(x1)) == 0)))
                if (field.isCorrectlyLocation(stocoor(x), y, stocoor(x1), y1, true)) {
                    Ship ship3(stocoor(x), y, stocoor(x1), y1);
                    field.addShip(ship3, true);
                    correctness = true;
                    system("cls");
                    cout << field;
                }
            if (!correctness)
                cout << "Координаты введены неверно\n";
        }
    }
    for (int i = 0; i < 3; i++) {
        correctness = false;
        while (!correctness) {
            cout << "Введите координаты 2-х палубного корабля через пробел: ";
            cin >> x >> y >> x1 >> y1;
            y--;
            y1--;
            if (((y - y1 == 0 && abs(stocoor(x) - stocoor(x1)) == 1)) || ((abs(y - y1) == 1 && abs(stocoor(x) - stocoor(x1)) == 0)))
                if (field.isCorrectlyLocation(stocoor(x), y, stocoor(x1), y1, true)) {
                    Ship ship2(stocoor(x), y, stocoor(x1), y1);
                    field.addShip(ship2, true);
                    correctness = true;
                    system("cls");
                    cout << field;
                }
            if (!correctness)
                cout << "Координаты введены неверно\n";
        }
    }
    for (int i = 0; i < 4; i++) {
        correctness = false;
        while (!correctness) {
            cout << "Введите координаты однопалубного корабля через пробел (Например A 1): ";
            cin >> x >> y;
            y--;
            x1 = x;
            y1 = y;
            if (field.isCorrectlyLocation(stocoor(x), y, stocoor(x1), y1, true)) {
                Ship ship1(stocoor(x), y, stocoor(x1), y1);
                field.addShip(ship1, true);
                correctness = true;
                system("cls");
                cout << field;
            }
            if (!correctness)
                cout << "Координаты введены неверно\n";
        }
    }
    // добавление кораблей компьютера
    field.addCompShip(4);
    field.addCompShip(3);
    field.addCompShip(3);
    field.addCompShip(2);
    field.addCompShip(2);
    field.addCompShip(2);
    field.addCompShip(1);
    field.addCompShip(1);
    field.addCompShip(1);
    field.addCompShip(1);
    system("cls");
    cout << field;

    // начало игры ------------------------------------------------------------------------------
    //             ------------------------------------------------------------------------------
    //             ------------------------------------------------------------------------------
    int turn = 0;// очередь хода
    string xs;
    string comp = "Comp";
    string user = "User";
    AI ai;
    int x_hit, y_hit;
    bool random=true;// определяет стрельбу компьютера
    bool game_over = false;
    while (!game_over) {
        if (!(turn % 2)) { // ход пользователя
            int xc;
            correctness = false;
            while (!correctness) {
                cout << "Введите координаты выстрела: ";
                cin >> xs >> y;
                xc = stocoor(xs);
                if (xc != 65000) {//неверное значение x
                    y--;
                    if (field(xc, y, comp) == -1 || field(xc, y, comp) == -2 || xc > 9 || y > 9 || xc < 0 || y < 0)
                        cout << "Введены неверные координаты";
                    else
                        correctness = true;
                }
            }
            if (field.userShot(xc, y)) {
                turn++;
                if (ai.isCompShipDestroyed(field, xc, y))
                    cout << "Корабль уничтожен,";
                else 
                    cout << "Есть попадание,";
                cout << " нажмите любую клавишу для продолжения\n";
                getchar();
                getchar();
            }
            else {
                cout << "Промах, нажмите любую клавишу для продолжения\n";
                getchar();
                getchar();
            }
        }
        else { // ход компьютера
            if (random == true) {
                if (ai.randomShoot(field, x_hit, y_hit)) {
                    cout << "ИИ попал по кораблю в клетке: " << coortos(x_hit) << y_hit+1 << ", нажмите любую клавишу для продолжения\n";
                    getchar();
                    turn++;
                    random = false;
                    if (ai.isUserShipDestroyed(field)) {
                        ai.deleteExcessPoints(field);
                        random = true;
                    }
                }
                else {
                    cout << "ИИ промахнулся выстрелив в " << coortos(x_hit) << " " << y_hit+1 << ", нажмите любую клавишу для продолжения\n";
                    getchar();
                }
            }
            else {
                if (ai.smartShoot(field, x_hit, y_hit)) {
                    cout << "ИИ попал по кораблю в клетке: "<< coortos(x_hit)<<" "<<y_hit+1<< ", нажмите любую клавишу для продолжения\n";
                    getchar();
                    turn++;
                    if (ai.isUserShipDestroyed(field)) {
                        ai.deleteExcessPoints(field);
                        random = true;
                    }
                }
                else {
                    cout << "ИИ промахнулся выстрелив в " << coortos(x_hit)<< " " << y_hit+1 << ", нажмите любую клавишу для продолжения\n";
                    getchar();
                }
            }
        }
        system("cls");
        cout << field;
        turn++;// смена хода
        game_over = field.isGameOver();
    }
    cout << "Игра окончена\n";
    if (turn % 2)
        cout << "Победил ИИ";
    else
        cout << "Победил человек";
}
