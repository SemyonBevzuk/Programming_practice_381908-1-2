//
// Created by Kirill on 10.05.2020.
//

#ifndef TASK6_VIEW_H
#define TASK6_VIEW_H

#include "string"
#include "Field.h"
using namespace std;
class View {
public:
    View(const string& name = "");
    void printField(const Field& field, bool isEnemy=false);
    void printFields(const Field& field, const Field& enemy_field);
    void hit(int row, int col);
    void miss(int row, int col);
    void turn();
    static int inputNumber(const string& what_number, int a, int b);
private:
    string name;
};


#endif //TASK6_VIEW_H
