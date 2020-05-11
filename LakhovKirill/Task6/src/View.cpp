//
// Created by Kirill on 10.05.2020.
//

#include <iostream>
#include "../include/View.h"



View::View(const string &name) {
    this->name = name;
}

void View::printField(const Field &field) {
    std::cout<<this->name<<"'s field"<<std::endl;
    std::cout<<field<<std::endl;
}

