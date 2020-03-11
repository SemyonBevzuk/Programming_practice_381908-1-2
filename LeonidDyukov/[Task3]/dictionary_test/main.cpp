//
// Created by Leo on 05.03.2020.
//

#include <iostream>
#include <fstream>

#include "word.h"
#include "dictionary.h"

int main() {
    try {
        word a = word("Cat", "Кошка");
        word b = word("Dog", std::vector<std::string>{"Собака", "Собачка"});
        word c = word("Cow", {"Корова", "Теленок", "Бык"});
        word d = word("Parrot", "Попугай");

        word a1 = word("Brow", "Кошка");
        word b1 = word("Star", std::vector<std::string>{"Собака", "Собачка"});
        word c1 = word("Meow", {"Корова", "Теленок", "Бык"});
        word d1 = word("Box", "Попугай");

        auto dict = dictionary();
        dict.add( &a );
        dict.add( &b );
        dict.add( &c );
        dict.add( &d );

        auto dict1 = dictionary();
        dict1.add( &a1 );
        dict1.add( &b1 );
        dict1.add( &c1 );
        dict1.add( &d1 );

        std::cout << dict << std::endl;

        auto * w = dict.find("Cat");
        w->change("Кошка", "Котейка");

        std::cout << dict << std::endl;

        std::cout << dict1 << std::endl;
        std::cout << (dict + dict1) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what();
    }
}
