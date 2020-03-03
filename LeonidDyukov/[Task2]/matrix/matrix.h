//
// Created by Leo on 29.02.2020.
//

#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H

#include <string>
#include <vector>

template<typename T>
class matrix {
public:
    matrix<T>();

    explicit matrix<T>(size_t size);
    matrix<T>(size_t size_n, size_t size_m);

    matrix(const matrix& other);
    matrix<T>(size_t size_strs, size_t size_rows,
            const T **arr = nullptr);
    matrix operator=(const T **arr);
    void init(T **arr = nullptr);

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



template<typename T>
matrix<T>::matrix() {
    this->size_rows = 0;
    this->size_strs = 0;
    this->init();
}

template<typename T>
matrix<T>::matrix(const size_t size) {
    this->size_rows = size;
    this->size_strs = size;
    this->init();
}

template<typename T>
matrix<T>::matrix(size_t size_rows, size_t size_strs) {
    this->size_rows = size_rows;
    this->size_strs = size_strs;
    this->init();
}

template<typename T>
matrix<T>::matrix(const matrix<T>& other) {
    this->size_rows = other.size_rows;
    this->size_strs = other.size_strs;
    this->init(other.value);
}

template<typename T>
matrix<T>::matrix(size_t size_rows, size_t size_strs, const T **arr) {
    this->size_rows = size_rows;
    this->size_strs = size_strs;
    this->init(arr);
}

template<typename T>
void matrix<T>::init(T **arr) {
    this->value = new T*[size_rows];
    auto setter = ((arr)?
                  ([arr](size_t i, size_t j) -> T { return arr[i][j]; }):
                  ([arr](size_t i, size_t j) -> T { return T(0); }));

    for (size_t i = 0; i < size_rows; ++i) {
        this->value[i] = new T[size_strs];
        for (size_t j = 0; j < size_strs; ++j) {
            this->value[i][j] = arr[i][j];
        }
    }
}




#endif //TASK2_MATRIX_H
