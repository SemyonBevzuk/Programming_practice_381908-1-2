//
// Created by Leo on 29.02.2020.
//

#include <array>
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix() {
    this->size_rows = 0;
    this->size_strs = 0;
    this->init();
}

template<typename T>
Matrix<T>::Matrix(const size_t size) {
    this->size_rows = size;
    this->size_strs = size;
    this->init();
}

template<typename T>
Matrix<T>::Matrix(size_t size_rows, size_t size_strs) {
    this->size_rows = size_rows;
    this->size_strs = size_strs;
    this->init();
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other) {
    this->size_rows = other.size_rows;
    this->size_strs = other.size_strs;
    this->init(other.value);
}

template<typename T>
Matrix<T>::Matrix(size_t size_rows, size_t size_strs, T **arr) {
    this->size_rows = size_rows;
    this->size_strs = size_strs;
    this->init(arr);
}

template<typename T>
void Matrix<T>::init(T **arr) {
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
                this->value[i][j] = 0;
            }
        }
    }
}

template<typename T> inline std::ostream& operator<<(std::ostream& os, const Matrix<T> &other) {
    os << other.to_string();
    return os;
}

template<typename T> std::istream& operator>>(std::istream& is, const Matrix<T> &other) {
    for (int i = 0; i < other.size_rows; ++i) {
        for (int j = 0; j < other.size_strs; ++j) {
            is >> other.value[i][j];
        }
    }
    return is;
}

template<typename T>
std::string Matrix<T>::to_string() {
    std::stringstream res;
    for (int i = 0; i < size_rows; ++i) {
        for (int j = 0; j < size_strs; ++j) {
            res << std::setw(pow(2, sizeof(this->value[0][0])) + 1) << std::setfill(' ') << this->value[i][j];
        }
        res << std::endl;
    }
    return res.str();
}

template<typename T>
Matrix<T> Matrix<T>::operator=(T **arr) {
    this->init(arr);
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator=(const Matrix &other) {
    this->size_rows = other.size_rows;
    this->size_strs = other.size_strs;
    this->value = other.value;
    return *this;
}







