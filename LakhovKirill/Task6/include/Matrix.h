//
// Created by Kirill Lakhov on 14.02.2020.
//

#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H


#include <string>
#include <ostream>

using namespace std;

class Matrix {
public:
    explicit Matrix(int size = 0);

    Matrix(const Matrix &_m);

    ~Matrix();

    bool init(int size = 0, int **arr = nullptr);

    void randomInit();

    bool out(const std::string &filename);

    static Matrix in(const std::string &filename);

    void transpose();

    bool diagonalPrevalence();

    Matrix &operator+=(const Matrix &toAdd);

    friend Matrix operator+(const Matrix &_a, const Matrix &_b);

    Matrix &operator*=(const Matrix &toMultiply);

    Matrix &operator*=(int number);

    friend Matrix operator*(const Matrix &_a, const Matrix &_b);

    friend Matrix operator*(const Matrix &matrix, int number);

    bool operator==(const Matrix &matrix) const;

    int &operator()(int row, int col) const;

    int &operator()(int row, int col);

    Matrix &operator=(const Matrix &toCopy);

    int getSize() const;

    int **getContents() const;

    bool gettable(int row, int col) const;

    int get(int row, int col) const;

    void set(int row, int col, int val) const;

    bool contains(int number) const;

    friend ostream &operator<<(ostream &os, const Matrix &matrix);

    friend istream &operator>>(istream &is, Matrix &matrix);

protected:
    int size;
    int **contents;
private:

    void clearContent();

    void setMemoryContent();
};


#endif //TASK2_MATRIX_H
