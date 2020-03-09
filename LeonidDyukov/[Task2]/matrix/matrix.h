//
// Created by Leo on 29.02.2020.
//

#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H

#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>

template<typename T> class matrix {
public:
    matrix<T>(size_t = 0, size_t = 0, T = 0);

    matrix(const matrix&);
    matrix<T>(size_t, size_t, T**);
    explicit matrix<T>(std::vector<std::vector<T>>);
    ~matrix() { delete [] value; }

    matrix<T>& operator=(const std::vector<std::vector<T>>&);
    matrix<T>& operator=(const matrix<T>&);

    matrix<T> operator()(std::vector<std::vector<T>>);

    T* operator[](size_t);
    T& at(size_t, size_t);

    matrix<T> operator-(const matrix&) const;
    matrix<T> operator-=(const matrix&) const;

    matrix<T> operator+(const matrix&) const;
    matrix<T> operator+=(const matrix&) const;

    matrix<T> operator*(const matrix&) const;
    matrix<T> operator*(std::vector<std::vector<T>>) const;
    matrix<T> operator*=(const matrix&);
    matrix<T> operator*=(std::vector<std::vector<T>>);

    matrix<T> operator*=(T);
    matrix<T> operator*(T) const;


    bool operator==(const matrix&) const;
    bool operator!=(const matrix&) const;

    matrix<T> trans() const;

    bool is_upper_triangle();
    bool is_lower_triangle();
    bool is_diagonal();
    bool is_diagonal_prevalence();
    bool is_zero();
    bool is_square();

    template<typename U> friend std::ostream& operator<<(std::ostream&, const matrix<U>&);
    template<typename U> friend std::istream& operator>>(std::istream&, matrix<U>&);

    void init(T** = nullptr, T val = T(0));
    void init(std::vector<std::vector<T>>);
    std::string to_string() const;
    std::string to_string(size_t) const;
private:
    T **value;
    size_t size_rows{};
    size_t size_strs{};
};

template<typename T> std::ostream& operator<<(std::ostream&, const matrix<T>&);
template<typename T> std::ostream& operator>>(std::istream&, matrix<T>&);


//###########################################################################
//###########################################################################
//###########################################################################


template<typename T>
matrix<T>::matrix(const matrix<T>& other) {
    this->size_rows = other.size_rows;
    this->size_strs = other.size_strs;
    this->init(other.value);
}

template<typename T>
matrix<T>::matrix(size_t size_rows, size_t size_strs, T **arr) {
    this->size_rows = size_rows;
    this->size_strs = size_strs;
    this->init(arr);
}

template<typename T>
matrix<T>::matrix(size_t size_rows, size_t size_strs, T val) {
    if (size_strs == 0) size_strs = size_rows;
    this->size_rows = size_rows;
    this->size_strs = size_strs;
    this->init(nullptr, val);
}

template<typename T>
matrix<T>::matrix(std::vector<std::vector<T>> val) {
    this->init(val);
}

template<typename T>
void matrix<T>::init(T **arr, T val) {
    this->value = new T*[size_rows];
    if (arr) {
        for (size_t i = 0; i < size_rows; ++i) {
            this->value[i] = new T[size_strs];
            for (size_t j = 0; j < size_strs; ++j) {
                this->value[i][j] = arr[i][j];
            }
        }
    } else {
        for (size_t i = 0; i < size_rows; ++i) {
            this->value[i] = new T[size_strs];
            for (size_t j = 0; j < size_strs; ++j) {
                this->value[i][j] = val;
            }
        }
    }
}

template<typename T>
void matrix<T>::init(std::vector<std::vector<T>> val) {
    this->size_rows = val.size();
    this->size_strs = 0;
    for (const auto & i : val)
        this->size_strs = i.size() > this->size_strs? i.size(): this->size_strs;

    this->value = new T*[this->size_rows];
    for (size_t i = 0; i < this->size_rows; ++i) {
        this->value[i] = new T[this->size_strs];
        for (size_t j = 0; j < val.at(i).size(); ++j) {
            this->value[i][j] = val.at(i).at(j);
        }

        for (size_t j = val.at(i).size(); j < this->size_strs; ++j) {
            this->value[i][j] = 0;
        }
    }
}

template<typename T> std::ostream& operator<<(std::ostream& os, const matrix<T> &other) {
    os << other.to_string();
    return os;
}

template<typename T> std::istream& operator>>(std::istream& is, const matrix<T> &other) {
    for (size_t i = 0; i < other.size_rows; ++i) {
        for (size_t j = 0; j < other.size_strs; ++j) {
            is >> other.value[i][j];
        }
    }
    return is;
}

template<typename T>
std::string matrix<T>::to_string() const {
    size_t chars = pow(2, sizeof(T)) + 1;
    return this->to_string(chars);
}

template<typename T>
std::string matrix<T>::to_string(size_t size) const {
    std::stringstream res;
    for (size_t i = 0; i < size_rows; ++i) {
        for (size_t j = 0; j < size_strs; ++j) {
            res << std::setw(size) << std::setfill(' ') << this->value[i][j];
        }
        res << std::endl;
    }
    return res.str();
}

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix &other) {
    if(this->operator==(other))
        return *this;
    this->size_rows = other.size_rows;
    this->size_strs = other.size_strs;
    this->init(other.value);
    return *this;
}

template<typename T>
matrix<T>& matrix<T>::operator=(const std::vector<std::vector<T>>& val) {
    this->init(val);
    return *this;
}

template<typename T>
matrix<T> matrix<T>::trans() const {
    auto res = matrix<T>(this->size_strs, this->size_rows);
    for (size_t i = 0; i < this->size_rows; ++i) {
        for (size_t j = 0; j < this->size_strs; ++j) {
            res.value[j][i] = this->value[i][j];
        }
    }
    return res;
}

template<typename T>
std::istream& operator>>(std::istream &in, matrix<T> &other) {
    return in;
}

template<typename T>
T* matrix<T>::operator[](size_t a) {
    return this->value[a];
}



template<typename T>
matrix<T> matrix<T>::operator+=(const matrix& other) const {
    if (this->size_strs != other.size_strs || this->size_rows != other.size_rows)
        throw std::invalid_argument("Size is not equals");

    for (size_t i = 0; i < this->size_rows; ++i) {
        for (size_t j = 0; j < this->size_strs; ++j) {
            this->value[i][j] += other.value[i][j];
        }
    }
    return *this;
}

template<typename T>
matrix<T> matrix<T>::operator-=(const matrix& other) const {
    if (this->size_strs != other.size_strs || this->size_rows != other.size_rows)
        throw std::invalid_argument("Size is not equals");

    for (size_t i = 0; i < this->size_rows; ++i) {
        for (size_t j = 0; j < this->size_strs; ++j) {
            this->value[i][j] -= other.value[i][j];
        }
    }
    return *this;
}

template<typename T>
bool matrix<T>::is_upper_triangle() {
    bool result = true;
    for (size_t i = 0; i < this->size_rows && result; ++i) {
        for (size_t j = 0; j < this->size_strs && result; ++j) {
            result &= ((i <= j) || this->value[i][j] == T(0));
        }
    }
    return result;
}

template<typename T>
bool matrix<T>::is_lower_triangle() {
    bool result = true;
    for (size_t i = 0; i < this->size_rows && result; ++i) {
        for (size_t j = 0; j < this->size_strs && result; ++j) {
            result &= ((i >= j) || this->value[i][j] == T(0));
        }
    }
    return result;
}

template<typename T>
bool matrix<T>::is_zero() {
    bool result = true;
    for (size_t i = 0; i < this->size_rows && result; ++i) {
        for (size_t j = 0; j < this->size_strs && result; ++j) {
            result &= this->value[i][j] == T(0);
        }
    }
    return result;
}

template<typename T>
bool matrix<T>::is_diagonal() {
    bool result = true;
    for (size_t i = 0; i < this->size_rows && result; ++i) {
        for (size_t j = 0; j < this->size_strs && result; ++j) {
            result &= ((i == j) || this->value[i][j] == T(0));
        }
    }
    return result;
}

template<typename T>
bool matrix<T>::is_square() {
    return this->size_rows == this->size_strs;
}

template<typename T>
bool matrix<T>::is_diagonal_prevalence() {
    if (!this->is_square())
        return false;
    bool hard = false;
    for (size_t i = 0; i < this->size_rows; ++i) {
        T sum = T(0);
        for (size_t j = 0; j < this->size_strs; ++j) {
            sum += abs(this->value[i][j]);
        }

        if (sum > 2 * abs(this->value[i][i])) {
            return false;
        } else if (sum < 2 * abs(this->value[i][i])) {
            hard = true;
        }
    }
    return hard;
}

template<typename T>
T& matrix<T>::at(size_t a, size_t b) {
    if (a >= this->size_rows || b >= this->size_strs)
        throw std::invalid_argument("Invalid index");
    return this->value[a][b];
}

template<typename T>
bool matrix<T>::operator!=(const matrix& other) const {
    if (this->size_strs != other.size_strs || this->size_rows != other.size_rows)
        return true;

    bool result = false;
    for (size_t i = 0; i < this->size_rows && !result; ++i) {
        for (size_t j = 0; j < this->size_strs && !result; ++j) {
            result |= this->value[i][j] == other.value[i][j];
        }
    }
    return !result;
}

template<typename T>
bool matrix<T>::operator==(const matrix& other) const {
    if (this->size_strs != other.size_strs || this->size_rows != other.size_rows)
        return false;

    bool result = true;
    for (size_t i = 0; i < this->size_rows && result; ++i) {
        for (size_t j = 0; j < this->size_strs && result; ++j) {
            result &= this->value[i][j] == other.value[i][j];
        }
    }
    return result;
}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix& other) const {
    auto result = matrix<T>(*this);
    result.operator+=(other);
    return result;
}

template<typename T>
matrix<T> matrix<T>::operator-(const matrix& other) const {
    auto result = matrix<T>(*this);
    result.operator-=(other);
    return result;
}

template<typename T>
matrix<T> matrix<T>::operator*(const matrix &other) const {
    auto result = matrix<T>(*this);
    result.operator*=(other);
    return result;
}

template<typename T>
matrix<T> matrix<T>::operator*=(const matrix &other) {
    if (this->size_strs != other.size_rows)
        throw std::invalid_argument("Size not equals");

    auto result = matrix<T>(this->size_rows, other.size_strs);
    for (size_t i = 0; i < this->size_rows; ++i) {
        for (size_t j = 0; j < other.size_strs; ++j) {
            result.value[i][j] = 0;
            for (size_t k = 0; k < this->size_strs; ++k) {
                result.value[i][j] += this->value[i][k] * other.value[k][j];
            }
        }
    }
    this->size_rows = result.size_rows;
    this->size_strs = result.size_strs;
    this->init(result.value);
    return *this;
}

template<typename T>
matrix<T> matrix<T>::operator*=(std::vector<std::vector<T>> val) {
    return this->operator*=(matrix<T>(val));
}

template<typename T>
matrix<T> matrix<T>::operator*(std::vector<std::vector<T>> val) const {
    return this->operator*(matrix<T>(val));
}

template<typename T>
matrix<T> matrix<T>::operator*=(T val) {
    for (size_t i = 0; i < this->size_rows; ++i) {
        for (size_t j = 0; j < this->size_strs; ++j) {
            this->value[i][j] *= val;
        }
    }
    return *this;
}

template<typename T>
matrix<T> matrix<T>::operator*(T val) const {
    auto result = matrix<T>(*this);
    result.operator*=(val);
    return result;
}

template<typename T>
matrix<T> matrix<T>::operator()(std::vector<std::vector<T>> val) {
    this->operator=(val);
    return *this;
}

#endif //TASK2_MATRIX_H

