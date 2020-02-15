#include <iostream>
#include "Matrix.h"
#include <random>
#include <chrono>
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


int main() {
    //Конструктор
    auto *a = new Matrix(5); // создает квадратную матрицу и инициализирует ее нулями

    //операция присваивания
    int**test = generator(3); // двумерный массив с int'ами
    auto *b = new Matrix(3); // матрица нужного размера
    b->init(3,test); // сработает только если (размеры массива == размеры матрицы) Вернет true в случае успеха

    //операция суммирования двух матриц
    auto *c = new Matrix(2);
    auto *d = new Matrix(2);
    c->randomInit(); //заполнение случайными числами
    d->randomInit();
    c->add(*d); // Прибавляем одну матрицу к другой, true если операция удалась

    //индексация с контролем
    auto *e = new Matrix(3);
    e->randomInit();
    std::cout<<e->get(0,0)<<std::endl; // получить значение по индексам
//    e->get(5,5); // вызовет ошибку range_error

    //запись в файл/чтение из файла
    auto *f = new Matrix(4);
    f->randomInit();
    f->out("matrixOut.txt");

    //Чтение матрицы из файла (желательно сначала записать ее с помощью matrix->out() )
    Matrix *j = Matrix::in("matrixIn.txt");
    j->print();
    return 0;
}
