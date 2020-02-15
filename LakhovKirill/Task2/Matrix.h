//
// Created by Kirill Lakhov on 14.02.2020.
//

#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H


#include <string>

class Matrix {
public:
    explicit Matrix(int size);
    bool init(int size, int **arr);
    bool add(Matrix _m);
    bool out(const std::string& filename);
    static Matrix* in(const std::string& filename);
    void print();
    int get(int _i, int _j);
    void randomInit();
    void initZero();
    static int matrixCount;
private:
    int size;
    int **contents;
};





#endif //TASK2_MATRIX_H
