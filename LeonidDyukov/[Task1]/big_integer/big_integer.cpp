//
// Created by Leo on 22.02.2020.
//

#include <string>       // Библиотека строк
#include <iomanip>      // Библиотека для формирования строки
#include <iostream>     // Библиотека потока ввода и вывода
#include "big_integer.h"


//=========================================================================
//=======================Constructors======================================
//=========================================================================
big_integer::big_integer() {
    setValue(false, 0);
}

big_integer::big_integer(int new_value) {
    setValue(new_value < 0, new_value);
}

big_integer::big_integer(long new_value) {
    setValue(new_value < 0, new_value);
}

big_integer::big_integer(long long new_value) {
    setValue(new_value < 0, new_value);
}

big_integer::big_integer(std::string new_value) {
    if (new_value.empty()) {
        this->setValue(false, 0);
    } else {
        this->sign = new_value[0] == '-';
        size_t start = this->sign? 1: 0;
        size_t end = new_value.size();

        this->value.reserve((end - start) / 9 + ((end - start) % 9 != 0? 1: 0));
        for (size_t i = end; i > start; i -= 9) {
            int buf = 0;
            for (size_t k = (i > 9 + start) ? i - 9: start; k < i; ++k) {
                buf = 10 * buf + (new_value[k] - '0');
            }

            this->value.push_back(buf);
            if (i < 9) break;
        }
    }
}

big_integer::big_integer(big_integer const &other) = default;

big_integer::big_integer(bool new_sign, BI new_value) {
    this->sign = new_sign;
    this->value = std::move(new_value);
}

big_integer& big_integer::operator=(const big_integer &other) {
    this->sign = other.getSign();
    this->value = other.value;
    return *this;
}

big_integer& big_integer::operator()(long long new_value) {
    this->setValue(new_value < 0, new_value);
    return *this;
}

//=========================================================================
//=======================Logic operation===================================
//=========================================================================
bool big_integer::operator==(const big_integer& other) const {
    auto a_str = this->to_string();
    auto b_str = other.to_string();

    bool a_sign = this->getSign();
    bool b_sign = other.getSign();

    return (a_sign == b_sign) && (a_str == b_str);
}

bool big_integer::operator!=(const big_integer& other) const {
    return !this->operator==(other);
}

bool big_integer::operator>=(const big_integer &other) const {
    if (this->getSign() == other.getSign()) {
        return this->getSign()?
            compare(&this->value, &other.value) <= 0:
            compare(&this->value, &other.value) >= 0;
    } else {
        return !this->getSign();
    }
}

bool big_integer::operator> (const big_integer &other) const {
    if (this->getSign() == other.getSign()) {
        return this->getSign()?
               compare(&this->value, &other.value) < 0:
               compare(&this->value, &other.value) > 0;
    } else {
        return !this->getSign();
    }
}

bool big_integer::operator<=(const big_integer &other) const {
    return !this->operator>(other);
}

bool big_integer::operator< (const big_integer &other) const {
    return !this->operator>=(other);
}


//=========================================================================
bool big_integer::operator==(long long other) const {
    return this->operator==(big_integer(other));
}

bool big_integer::operator!=(long long other) const {
    return this->operator!=(big_integer(other));
}

bool big_integer::operator>(long long other) const {
    return this->operator>(big_integer(other));
}

bool big_integer::operator>=(long long other) const {
    return this->operator>=(big_integer(other));
}

bool big_integer::operator<(long long other) const {
    return this->operator<(big_integer(other));
}

bool big_integer::operator<=(long long int other) const {
    return this->operator<=(big_integer(other));
}

//=========================================================================
//=======================Math operation====================================
//=======================Two arguments=====================================
//=========================================================================
big_integer big_integer::operator+(const big_integer &other) const {
    auto a = *this;
    return a.operator+=(other);
}


big_integer big_integer::operator-(const big_integer &other) const {
    auto a = *this;
    return a.operator-=(other);
}


big_integer big_integer::operator*(const big_integer &other) const {
    auto a = *this;
    return a.operator*=(other);
}

big_integer big_integer::operator/(const big_integer &other) const {
    auto a = *this;
    return a.operator/=(other);
}

//=========================================================================
big_integer big_integer::operator+(long long other) const {
    return this->operator+(big_integer(other));
}

big_integer big_integer::operator-(long long other) const {
    return this->operator-(big_integer(other));
}

big_integer big_integer::operator*(long long other) const {
    return this->operator*(big_integer(other));
}

big_integer big_integer::operator/(long long other) const {
    return this->operator/(big_integer(other));
}



//=========================================================================
//=======================Math operation====================================
//=======================One arguments=====================================
//=========================================================================
big_integer big_integer::operator+=(const big_integer &other) {
    if (this->getSign() == other.getSign()) {
        add(&this->value, &other.value);
        return *this;
    } else {
        if (compare(&this->value, &other.value) == 0)
            return big_integer(0);
        if (compare(&this->value, &other.value) > 0) {
            rem(&this->value, &other.value);
            return *this;
        } else {
            auto a = other;
            rem(&a.value, &this->value);
            this->value = a.value;
            this->sign = a.sign;
            return *this;
        }
    }
}

big_integer big_integer::operator-=(const big_integer &other) {
    if (this->getSign() != other.getSign()) {
        add(&this->value, &other.value);
        return *this;
    } else {
        if (compare(&this->value, &other.value) == 0)
            return big_integer(0);
        if (compare(&this->value, &other.value) > 0) {
            rem(&this->value, &other.value);
            return *this;
        } else {
            auto a = other;
            rem(&a.value, &this->value);
            this->value = a.value;
            this->sign = !a.sign;
            return *this;
        }
    }
}

big_integer big_integer::operator*=(const big_integer &other) {
    auto zero = big_integer();
    if (this->operator==(zero) || other.operator==(zero)) {
        this->operator=(zero);
        return *this;
    }

    auto * a = &this->value;
    auto * b = &other.value;
    BI result(1, 0);

    for (size_t i = 0; i < b->size(); ++i) {
        BI tmp_result;
        for (size_t j = 0; j < i; ++j) {
            tmp_result.push_back(0);
        }
        unsigned long long next = 0;
        for (unsigned int a_i : *a) {
            next = (unsigned long long)a_i *
                    (unsigned long long)b->at(i) +
                    next;
            tmp_result.push_back(next % BASE);
            next /= BASE;
        }
        if (next != 0) tmp_result.push_back(next);
        add(&result, &tmp_result);
    }

    this->value = result;
    this->sign = this->getSign() ^ other.getSign();
    return *this;
}

big_integer big_integer::operator/=(const big_integer &other) {
    if (other.operator==(0)) throw std::invalid_argument("Divizion by zero");

    int comp = compare(&this->value, &other.value);
    if (comp < 0) {
        this->value = BI(1, 0);
        this->sign = false;
        return *this;
    }
    this->sign = this->getSign() ^ other.getSign();
    if (comp == 0) {
        this->value = BI(1, 1);
        return *this;
    }

    size_t size_a = length(&this->value);
    size_t size_b = length(&other.value);

    BI result(1, 0);
    auto * a = &this->value;
    for (size_t i = size_a - size_b + 1; i > 0; --i) {
        long long int range = 1;
        for (size_t j = 0; j + 1 < i; ++j, range *= 10);
        BI step(1, range);

        BI b = (other * big_integer(range)).value;
        while (compare(a, &b) >= 0) {
            rem(a, &b);
            add(&result, &step);
        }
    }

    this->value = result;
    return *this;
}

//=========================================================================
big_integer big_integer::operator+=(const long long other) {
    auto result = this->operator+(other);
    this->value = result.value;
    this->sign = result.sign;
    return *this;
}

big_integer big_integer::operator-=(const long long other) {
    auto result = this->operator-(other);
    this->value = result.value;
    this->sign = result.sign;
    return *this;
}

big_integer big_integer::operator*=(const long long other) {
    auto result = this->operator*(other);
    this->value = result.value;
    this->sign = result.sign;
    return *this;
}

big_integer big_integer::operator/=(const long long other) {
    auto result = this->operator/(other);
    this->value = result.value;
    this->sign = result.sign;
    return *this;
}

//=========================================================================
big_integer big_integer::operator++() {
    auto result = this->operator+(1);
    this->value = result.value;
    this->sign = result.sign;
    return *this;
}

big_integer big_integer::operator--() {
    auto result = this->operator-(1);
    this->value = result.value;
    this->sign = result.sign;
    return *this;
}



//=========================================================================
//=======================Stream operation==================================
//=========================================================================
std::ostream& operator<<(std::ostream& os, const big_integer &other) {
    os << other.to_string();
    return os;
}

std::istream& operator>>(std::istream& in, big_integer &other) {
    std::cout << "Enter value: ";
    std::string new_value;
    in >> new_value;
    other = big_integer(new_value);
    return in;
}



//=========================================================================
//=======================Functions=========================================
//=========================================================================
const char * big_integer::to_chars() const {
    return this->to_string().c_str();
}

std::string big_integer::to_string() const {
    std::stringstream result;
    result << (this->sign? "-": "") << this->value.at(this->value.size() - 1);
    for (size_t i = this->value.size() - 1; i > 0; --i) {
        result << std::setw(BASE_POW) << std::setfill('0') << this->value.at(i - 1);
    }
    return result.str();
}

bool big_integer::getSign() const {
    return this->sign;
}


//=========================================================================
//=======================Private function==================================
//=========================================================================
void big_integer::setValue(bool new_sign, long long new_value) {
    this->sign = new_sign;
    if (new_value == 0) {
        this->value.push_back(0);
    } else {
        new_value = std::abs(new_value);
        while (new_value != 0) {
            this->value.push_back(new_value % BASE);
            new_value /= BASE;
        }
    }
}

int big_integer::compare(const BI *a, const BI *b) const {
    if (a->size() == b->size()) {
        for (size_t i = a->size(); i > 0; --i) {
            if (a->at(i - 1) != b->at(i - 1))
                return a->at(i - 1) > b->at(i - 1)? 1: -1;
        }
        return 0;
    } else {
        return a->size() > b->size()? 1: -1;
    }
}

void big_integer::add(big_integer::BI *a, const big_integer::BI *b) const {
    size_t size = std::max(a->size(), b->size());
    item_t next = 0;
    a->resize(size + 1);

    for (size_t i = 0; i < size; ++i) {
        item_t a_i = a->size() > i? a->at(i): 0;
        item_t b_i = b->size() > i? b->at(i): 0;

        if (a_i < BASE - b_i - next) {
            item_t push_value = a_i + b_i + next;
            (*a)[i] = push_value;
            next = 0;
        } else {
            item_t push_value = a_i - (BASE - b_i - next);
            (*a)[i] = push_value;
            next = 1;
        }
    }
    if (next != 0) (*a)[size] = next;
    normalize(a);
}

void big_integer::rem(big_integer::BI *a, const big_integer::BI *b) const {
    size_t size = std::max(a->size(), b->size());
    item_t next = 0;

    for (size_t i = 0; i < size; ++i) {
        item_t a_i = a->size() > i? a->at(i): 0;
        item_t b_i = b->size() > i? b->at(i): 0;

        if (a_i + next >= b_i) {
            item_t push_value = a_i - b_i + next;
            (*a)[i] = push_value;
            next = 0;
        } else {
            item_t push_value = a_i + next + (BASE - b_i);
            (*a)[i] = push_value;
            next = -1;
        }
    }
    normalize(a);
}


void big_integer::normalize(big_integer::BI * vector) {
    size_t size = vector->size();
    for (size_t i = vector->size(); i > 0; --i) {
        if (vector->at(i - 1) != 0) break;
        size--;
    }
    vector->resize(size == 0? 1: size);
}


big_integer::size_t big_integer::length(const big_integer::BI *vector) {
    int last_element_size = 0;
    item_t tmp = 1;
    for (; tmp <= vector->at(vector->size() - 1); tmp *= 10, last_element_size++);
    return 9 * (vector->size() - 1) + last_element_size;
}




