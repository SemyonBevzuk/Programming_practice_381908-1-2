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
    void printField(const Field& field);
private:
    string name;

};


#endif //TASK6_VIEW_H
