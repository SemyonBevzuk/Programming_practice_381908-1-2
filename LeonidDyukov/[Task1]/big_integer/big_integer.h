//
// Created by Leo on 22.02.2020.
//

#ifndef TASK1_BIG_INTEGER_H
#define TASK1_BIG_INTEGER_H


#include <vector>
#include <string>

class big_integer {
public:
    typedef unsigned int item_t;
    typedef unsigned long size_t;
    typedef std::vector<item_t> BI;

    const int BASE_POW = 9;
    const int BASE = 1000 * 1000 * 1000;

    big_integer();

    explicit big_integer(int new_value);
    explicit big_integer(long new_value);
    explicit big_integer(long long new_value);
    explicit big_integer(std::string new_value);
    big_integer(const big_integer& other);
    big_integer(bool new_sign, BI new_value);

    big_integer& operator=(const big_integer& other);
    big_integer& operator()(long long new_value);

    bool operator==(const big_integer& other) const;
    bool operator!=(const big_integer& other) const;
    bool operator> (const big_integer& other) const;
    bool operator>=(const big_integer& other) const;
    bool operator< (const big_integer& other) const;
    bool operator<=(const big_integer& other) const;

    bool operator==(long long other) const;
    bool operator!=(long long other) const;
    bool operator> (long long other) const;
    bool operator>=(long long other) const;
    bool operator< (long long other) const;
    bool operator<=(long long other) const;

    big_integer operator+(const big_integer& other) const;
    big_integer operator-(const big_integer& other) const;
    big_integer operator*(const big_integer& other) const;
    big_integer operator/(const big_integer& other) const;

    big_integer operator+(long long other) const;
    big_integer operator-(long long other) const;
    big_integer operator*(long long other) const;
    big_integer operator/(long long other) const;

    big_integer operator+=(const big_integer& other);
    big_integer operator-=(const big_integer& other);
    big_integer operator*=(const big_integer& other);
    big_integer operator/=(const big_integer& other);

    big_integer operator+=(long long other);
    big_integer operator-=(long long other);
    big_integer operator*=(long long other);
    big_integer operator/=(long long other);

    big_integer operator++();
    big_integer operator--();

    friend std::ostream& operator<<(std::ostream& os, const big_integer& other);
    friend std::istream& operator>>(std::istream& in, big_integer& other);

    std::string to_string() const;
    const char * to_chars() const;

    bool getSign() const;
private:
    bool sign;
    BI value;

    void setValue(bool new_sign, long long new_value);
    int compare(const BI *a, const BI *b) const;

    void add(BI *a, const BI *b) const;
    void rem(BI *a, const BI *b) const;

    static void normalize(BI * vector);
    static size_t length(const big_integer::BI *vector);
};

std::ostream& operator<<(std::ostream& os, const big_integer& other);
std::istream& operator>>(std::istream& in, big_integer& other);

#endif //TASK1_BIG_INTEGER_H
