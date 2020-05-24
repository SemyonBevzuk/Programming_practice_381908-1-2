#include "Taylor.h"

myExp::myExp(size_t n = 0)
{
    elements.resize(n);
}
void myExp::setSize(size_t n)
{
    elements.resize(n);
}
size_t myExp::getSize()
{
    return elements.size();
}
void myExp::findElements(double _a)
{
    a = _a;
    double buff = 1;
    double exp_a = exp(a);
    for (int i = 0; i < elements.size(); i++)
    {
        elements[i] = exp_a / buff;
        buff *= (i + 1);
    }
}
void myExp::showEquation()
{
    std::cout << elements[0];
    for (int i = 1; i < elements.size(); i++)
    {
        std::cout << "+" << elements[i] << "(x-" << a << ")^" << i;
    }
    std::cout << std::endl;
}
double myExp::operator[](size_t index)
{
    return elements[index];
}
double myExp::calculate(double x)
{
    double res = elements[0];
    for (int i = 1; i < elements.size(); i++)
    {
        res += elements[i] * pow(x - a, i);
    }
    return res;
}
double myExp::accuracy(double x)
{
    return abs(calculate(x) - exp(x));
}
std::ofstream& operator<<(std::ofstream& ofs, myExp& obj)
{
    for (int i = 0; i < obj.elements.size(); i++)
    {
        ofs << std::fixed << obj.elements[i] << " ";
    }
    ofs << std::endl;
    return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, myExp& obj)
{
    for (int i = 0; i < obj.elements.size(); i++)
    {
        ifs >> obj.elements[i];
    }
    return ifs;
}