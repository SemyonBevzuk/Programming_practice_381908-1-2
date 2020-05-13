//
// Created by Kirill on 10.05.2020.
//

#include <iostream>
#include "../include/View.h"



View::View(const string &name) {
    this->name = name;
}



void View::printField(const Field &field, bool isEnemy) {
    string desc = this->name;
    if(isEnemy){
        desc+= "'s enemy field";
    }else{
        desc+= "'s field";
    }
    std::cout<<desc<<std::endl;
    std::cout<<field<<std::endl;
}

void View::printFields(const Field &field, const Field &enemy_field) {
    std::cout<<this->name<<"'s fields"<<std::endl;
    int size = field.getSize();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size * 2; ++j) {
            if(j<size){
                std::cout<<field(i,j)<<" ";
            }else{
                if(j == size){
                    std::cout<<"   ";
                }
                std::cout<<enemy_field(i,j-size)<<" ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}


int View::inputNumber(const string &what_number, int a, int b) {
    string str;
    int number;
    while (true) {
        std::cout << what_number << std::endl;
        cin >> str;
        try {
            number = stoi(str);
        } catch (invalid_argument &e) {
            std::cout << "You need to enter a number" << std::endl;
            continue;
        }
        if(number >= a && number <= b){
            return number;
        }else{
            std::cout << "You need to enter a number in " <<"[" <<a<<";"<<b<<"]"<<std::endl;
        }
    }
}

void View::hit(int row, int col) {
    std::cout<<this->name<<" hit to "<<row<<" "<<col<<"\n"<<std::endl;
}

void View::miss(int row, int col) {
    std::cout<<this->name<<" missed at "<<row<<" "<<col<<"\n"<<std::endl;
}

void View::turn() const {
    std::cout<<this->name<<"'s turn"<<std::endl;
}

void View::destroy() {
    std::cout<<this->name<<" destroyed ship!"<<std::endl;
}

