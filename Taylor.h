#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

class myExp
{
    private:
        std::vector<double> elements;
        double a;
    public:
        myExp(size_t n = 0);
        void setSize(size_t n);
        size_t getSize();
        void findElements(double _a);
        void showEquation();
        double operator[](size_t index);
        double calculate(double x);
        double accuracy(double x);
        friend std::ofstream& operator<<(std::ofstream& ofs, myExp& obj);
        friend std::ifstream& operator>>(std::ifstream& ifs, myExp& obj);
};
