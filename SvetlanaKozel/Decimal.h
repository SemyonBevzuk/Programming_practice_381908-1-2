#include <iostream>
#include <vector>

class Decimal
{
    private:
        std::vector<unsigned char> digits;
    public:

        Decimal(unsigned long long n = 0);
        size_t size() const;
        Decimal& operator=(const Decimal&);
        Decimal& operator=(unsigned long long);
        friend bool operator>(const Decimal&, const Decimal&);
        friend bool operator==(const Decimal&, const Decimal&);
        friend bool operator!=(const Decimal&, const Decimal&);
        friend bool operator<(const Decimal&, const Decimal&);
        friend bool operator>=(const Decimal&, const Decimal&);
        friend bool operator<=(const Decimal&, const Decimal&);
        friend Decimal operator+(const Decimal&, const Decimal&);
        friend Decimal operator-(const Decimal&, const Decimal&);
        friend std::ostream& operator<< (std::ostream &, const Decimal&);
        friend std::istream& operator>> (std::istream &, Decimal&);
};