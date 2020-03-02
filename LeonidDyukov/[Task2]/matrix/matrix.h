//
// Created by Leo on 29.02.2020.
//

#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H

#include <string>
#include <vector>

class matrix {
public:
    typedef int T;

    matrix();

    explicit matrix(size_t size);
    matrix(size_t size_n, size_t size_m);

    matrix(const matrix& other);
    matrix(size_t size, T **arr = nullptr);

    matrix operator=(const matrix &other);
    matrix operator+(const matrix &other);
    matrix operator-(const matrix &other);

    matrix operator*(const matrix &other);

    std::string to_string();
private:
    T **value;
    size_t size_rows;
    size_t size_strs;
};



#endif //TASK2_MATRIX_H
