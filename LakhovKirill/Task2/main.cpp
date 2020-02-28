#include <iostream>
#include "Matrix.h"
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

int** generator(int size){
    int**toGen = new int*[size];
    for (int i = 0; i < size; ++i) {
        toGen[i] = new int[size];
    }
    mt19937 generator(chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    uniform_int_distribution<> uid(0,100);
    for (int j = 0; j <size; ++j) {
        for (int i = 0; i < size; ++i) {
            toGen[j][i] = uid(generator);
        }
    }
    return toGen;
}

void print(int**arr, int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n"<<"";
    }
}


int main(){
    //Создание матриц
    Matrix a = Matrix(5);
    Matrix b = Matrix(4);

    //инициализация некоторым массивом (подходящего размера)
    a.init(5,generator(5));
    //инициализация нулями
    b.init();
    //копией другой матрицы
    Matrix c = Matrix(a);

    //сумма двух матриц
    Matrix d = a + c;
    d+=a;

    //Индексация
    int number = d(2,2);
    //d(6,6) - вызовет ошибку out_of_range

    //вывод матрицы в поток
    cout<<d;
    //вывод матрицы в файл
    d.out("Dmatrix.txt");

    //считывание матрицы откуда либо
    Matrix e = Matrix::in("Dmatrix.txt");
    e(0,0) = 100; e(1,1) = 100;
    e.out("Ematrix.txt");

    //или из открытого файла
    fstream someFile;
    someFile.open("Ematrix.txt", fstream::in);
    if (someFile.is_open()) {
        Matrix k = Matrix();
        someFile >> k;
    }

    //Умножение матриц (range_error в случае несопостовимих размеров матриц)
    Matrix f = d*e;
    f*=a;

    //Умножение на скаляр
    Matrix g = f*3;
    f*=2;

    //Диагональное преобладание
    if(f.diagonalPrevalence()) std::cout<<"f matrix has diagonal prevalence"<<std::endl;

    //Транспонирование
    a.transpose();

    return 0;
}

