//
// Created by Kirill Lakhov on 14.02.2020.
//

#include "../include/Matrix.h"
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>

Matrix::Matrix(int size) {
    this->size = size;
    this->setMemoryContent();
    this->init();
}

Matrix::Matrix(const Matrix &matrix) {
    this->size = matrix.getSize();
    this->contents = new int *[size];
    for (int i = 0; i < size; ++i) {
        this->contents[i] = new int[size];
    }
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->contents[i][j] = matrix.contents[i][j];
        }
    }
}

void Matrix::randomInit() {
    std::mt19937 generator(std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
    std::uniform_int_distribution<> uid(0, 100);
    for (int j = 0; j < this->size; ++j) {
        for (int i = 0; i < this->size; ++i) {
            this->contents[j][i] = uid(generator);
        }
    }
}

bool Matrix::init(int size, int **arr) {
    if ((size > 0) && (arr != nullptr)) {
        if (this->size == size) {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    this->contents[i][j] = arr[i][j];
                }
            }
            return true;
        } else {
            throw std::out_of_range("Init failed, check matrix size");
        }
    } else {
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                this->contents[i][j] = 0;
            }
        }
        return false;
    }
}


bool Matrix::out(const std::string &filename) {
    std::fstream f;
    f.open(filename, std::fstream::out);
    if (f.is_open()) {
        f << *this;
        f.close();
        return true;
    }
    return false;
}

Matrix Matrix::in(const std::string &filename) {
    std::fstream f;
    f.open(filename, std::fstream::in);
    if (f.is_open()) {
        auto matrix = Matrix();
        f >> matrix;
        return matrix;
    } else {
        throw std::exception();
    }
}

void Matrix::transpose() {
    int **temp = new int *[this->size];
    for (int i = 0; i < this->size; ++i) {
        temp[i] = new int[size];
    }
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            temp[i][j] = this->contents[i][j];
        }
    }
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->contents[i][j] = temp[j][i];
        }
    }
}

bool Matrix::diagonalPrevalence() {
    for (int i = 0; i < this->size; ++i) {
        int diagonalElement = abs(this->contents[i][i]);
        int sum = 0;
        for (int j = 0; j < this->size; ++j) {
            if (i != j) sum += abs(this->contents[i][j]);
        }
        if (diagonalElement < sum) return false;
    }
    return true;
}


Matrix::~Matrix() {
    this->clearContent();
}


int Matrix::getSize() const {
    return this->size;
}

int **Matrix::getContents() const {
    return this->contents;
}

void Matrix::clearContent() {
    for (int i = 0; i < this->size; ++i) {
        delete this->contents[i];
    }
    delete this->contents;
}


void Matrix::setMemoryContent() {
    this->contents = new int *[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->contents[i] = new int[this->size];
    }
}

int &Matrix::operator()(int row, int col) const {
    if (this->gettable(row, col))
        return this->contents[row][col];
    string str = "Can not reach index " + to_string(row)+ " "+ to_string(col);
    throw std::out_of_range(str);
}
int &Matrix::operator()(int row, int col) {
    if (this->gettable(row, col))
        return this->contents[row][col];
    string str = "Can not reach index " + to_string(row)+ " "+ to_string(col);
    throw std::out_of_range(str);
}

Matrix &Matrix::operator=(const Matrix &toCopy) {
    this->clearContent();
    this->size = toCopy.getSize();
    this->setMemoryContent();
    this->init(toCopy.getSize(), toCopy.getContents());
    return *this;
}

Matrix operator+(const Matrix &_a, const Matrix &_b) {
    Matrix temp = Matrix(_a);
    temp += _b;
    return temp;
}

Matrix &Matrix::operator+=(const Matrix &toAdd) {
    if (this->size == toAdd.getSize()) {
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                this->contents[i][j] += toAdd(i, j);
            }
        }
        return *this;
    } else {
        throw std::range_error("Can not get sum of matrices with different sizes");
    }
}

Matrix operator*(const Matrix &_a, const Matrix &_b) {
    Matrix temp = Matrix(_a);
    temp *= _b;
    return temp;
}

Matrix &Matrix::operator*=(const Matrix &toMultiply) {
    if (this->size == toMultiply.getSize()) {
        int **arr = new int *[this->size];
        for (int i = 0; i < this->size; ++i) {
            arr[i] = new int[this->size];
        }
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                arr[i][j] = 0;
                for (int k = 0; k < this->size; ++k) {
                    arr[i][j] += this->contents[i][k] * toMultiply.contents[k][j];
                }
            }
        }
        this->init(this->size, arr);
        return *this;
    } else {
        throw std::range_error("Can not multiply matrices with different sizes");
    }
}

Matrix operator*(const Matrix &matrix, int number) {
    Matrix temp = Matrix(matrix);
    temp *= number;
    return temp;
}

Matrix &Matrix::operator*=(int number) {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->contents[i][j] *= number;
        }
    }
    return *this;
}

ostream &operator<<(ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.getSize(); ++i) {
        for (int j = 0; j < matrix.getSize(); ++j) {
            os << matrix(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}

istream &operator>>(istream &is, Matrix &matrix) {
    int size;
    is >> size;
    Matrix temp = Matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            is >> temp(i, j);
        }
    }
    matrix = temp;
    return is;
}

bool Matrix::gettable(int row, int col) const {
    return row >= 0 && row < this->size && col >=0 && col < this->size;
}

int Matrix::get(int row, int col) const {
    return this->contents[row][col];
}

void Matrix::set(int row, int col, int val) const {
   this->contents[row][col] = val;
}
