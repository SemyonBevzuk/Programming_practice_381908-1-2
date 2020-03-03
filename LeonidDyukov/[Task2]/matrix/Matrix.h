//
// Created by Leo on 29.02.2020.
//

#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

template<typename T>
class Matrix {
public:
    Matrix<T>();
    explicit Matrix<T>(size_t size);
    Matrix<T>(size_t size_rows, size_t size_strs);
    Matrix(const Matrix& other);
    Matrix<T>(size_t size_rows, size_t size_strs,
              T **arr = nullptr);
    ~Matrix() { delete [] value; }

    Matrix<T> operator=(T **arr);
    Matrix<T> operator=(const Matrix &other);

    Matrix<T> operator-(const Matrix &other);
    Matrix<T> operator-(const T new_value);

    Matrix<T> operator+(const Matrix &other);
    Matrix<T> operator+(const T new_value);

    Matrix<T> operator*(const Matrix &other);
    Matrix<T> operator*(const T new_value);

    bool operator==(const Matrix &other);
    bool operator!=(const Matrix &other);

    Matrix<T> trans(const Matrix &other);

    bool is_upper_triangle();
    bool is_lower_triangle();
    bool is_diagonal();
    bool is_zero();

    template<typename U> friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& other);
    template<typename U> friend std::istream& operator>>(std::istream& in, Matrix<U>& other);

    void init(T **arr = nullptr);
    std::string to_string();
private:
    T **value;
    size_t size_rows;
    size_t size_strs;
};

template<typename T> std::ostream& operator<<(std::ostream& os, const Matrix<T>& other);
template<typename T> std::istream& operator>>(std::istream& in, Matrix<T>& other);

#endif //TASK2_MATRIX_H
