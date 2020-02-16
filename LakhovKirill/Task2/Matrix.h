//
// Created by Kirill Lakhov on 14.02.2020.
//

#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H


#include <string>

class Matrix {
public:
    explicit Matrix(int size);
    void init();
    bool init(int size, int **arr);
    bool add(Matrix _m);
    bool out(const std::string& filename);
    static Matrix* in(const std::string& filename);
    void print();
    int get(int _i, int _j);
    bool set(int _i, int _j , int val);
    void randomInit();
    void transpose();
    bool diagonalPrevalence();
    bool multiplyBy(Matrix _m);
    void multiplyBy(int _n);
    static Matrix* multiply(Matrix _a, Matrix _b);
private:
    int size;
    int **contents;
};





#endif //TASK2_MATRIX_H
