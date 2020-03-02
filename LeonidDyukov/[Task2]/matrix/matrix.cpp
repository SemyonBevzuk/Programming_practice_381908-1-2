//
// Created by Leo on 29.02.2020.
//

#include <array>
#include "matrix.h"

matrix::matrix() {
    this->size_rows = 0;
    this->size_strs = 0;
}

matrix::matrix(const size_t size) {
    this->size_rows = size;
    this->size_strs = size;
    this->value = std::array<std::array<, size>, size>();
    for (int i = 0; i < this->size_rows; ++i) {
        for (int k = 0; k < this->size_strs; ++k) {
            this->value[i][k] = 0;
        }
    }
}

matrix::matrix(size_t size_rows, size_t size_strs) {
    this->size_rows = size_rows;
    this->size_strs = size_strs;
    this->value = &std::array< &std::array<T, this->size_strs>(), this->size_rows>();
    for (int i = 0; i < this->size_rows; ++i) {
        for (int k = 0; k < this->size_rows; ++k) {
            this->value[i][k] = 0;
        }
    }
}

