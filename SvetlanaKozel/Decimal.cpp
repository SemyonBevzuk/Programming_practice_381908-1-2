#include "Decimal.h"

Decimal::Decimal(unsigned long long n = 0)
{
    while (n > 0)
    {
        digits.push_back(n%10);
        n/=10;
    }
}
size_t Decimal::size() const
{
    return digits.size();
}
Decimal& Decimal::operator=(const Decimal& other)
{
    digits = other.digits;
    return (*this);
}
Decimal& Decimal::operator=(unsigned long long other)
{
    (*this) = Decimal(other); 
    return (*this);
}
bool operator>(const Decimal& a, const Decimal& b)
{
    if (a.size() > b.size()) return true;
    if (a.size() < b.size()) return false;

    size_t i = a.size();
    while ((a.digits[i] == b.digits[i]) && (i > 0))
    {
        i--;
    }
    return (a.digits[i] > b.digits[i]);
}
bool operator==(const Decimal& a, const Decimal& b)
{
    return (a.digits == b.digits);
}
bool operator!=(const Decimal& a, const Decimal& b)
{
    return (a.digits != b.digits);
}
bool operator<(const Decimal& a, const Decimal& b)
{
    return ((a != b) && !(a > b));
}
bool operator>=(const Decimal& a, const Decimal& b)
{
    return ((a > b) || (a == b));
}
bool operator<=(const Decimal& a, const Decimal& b)
{
    return ((a < b) || (a == b));
}
Decimal operator+(const Decimal& a, const Decimal& b)
{
    Decimal res;
    Decimal other;

    if (a > b)
    {
        res = a;
        other = b;
    }
    else
    {
        res = b;
        other = a;
    }

    for (int i=0; i<other.size(); i++)
    {
        res.digits[i] += other.digits[i];
        if (res.digits[i] > 9)
        {
            if (res.size() == i+1) res.digits.resize(i+2);
            res.digits[i+1] = res.digits[i] / 10;
            res.digits[i] %= 10;
        }
    }

    return res;
}
Decimal operator-(const Decimal& a, const Decimal& b)
{
    Decimal res;
    Decimal other;
    if (a > b)
    {
        res = a;
        other = b;
    }
    else
    {
        res = b;
        other = a;
    }
    
    for (int i=0; i < other.size(); i++)
    {
        res.digits[i] -= other.digits[i];
        if (res.digits[i] < 0)
        {
            res.digits[i]+=10;
            res.digits[i+1]-=1;
        }
    }
    return res;
}

std::ostream& operator<< (std::ostream &out, const Decimal& a)
{
    bool start = false;
    for (int i = a.digits.size()-1; i >= 0; i--)
    {
        if (a.digits[i] != 0)
            start = true;
        if(start)
            out<<(int)a.digits[i];
    }
}
std::istream& operator>> (std::istream &in, Decimal &a)
{
    std::string s;
    in>>s;
    a.digits.clear();
    a.digits.resize(s.size());
    for (int i=0; i<s.size(); i++)
    {
        if ((s[i] > 57) || (s[i] < 48))
        {
            a = Decimal(0);
            break;
        }
        a.digits[s.size()-i-1] = s[i]-48;
    }
    return in;
}