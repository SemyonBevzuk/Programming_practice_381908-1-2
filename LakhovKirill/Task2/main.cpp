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
    int val = e->get(0,0); // получить значение по индексам
//    e->get(5,5); // вызовет ошибку range_error

    e->set(1,1,val); // установить значение по индексу true/false в зависимости от успеха

    //Запись в файл
    auto *f = new Matrix(4);
    f->randomInit();
    f->out("matrixOut.txt");

    //Чтение матрицы из файла (желательно сначала записать ее с помощью matrix->out() )
    Matrix *g = Matrix::in("matrixIn.txt");
//    g->print();

    //Транспонирование матрицы
    auto *h = new Matrix(3);
    h->randomInit();
    h->transpose();

    //Диагональное преобладание true/false
    Matrix *k = Matrix::in("matrixIn.txt");
    if(k->diagonalPrevalence()) std::cout<<"matrix has diagonal prevalence property"<<std::endl;

    //Произведение матриц
    auto *l = new Matrix(3);
    auto *m = new Matrix(3);
    l->randomInit();
    m->randomInit();
    Matrix *n = Matrix::multiply(*l,*m);

    //или
    auto *o = new Matrix(4);
    auto *p = new Matrix(4);
    o->randomInit();
    p->randomInit();
    o->multiplyBy(*p); // true/false  зависимости от успеха операции

    //умножение на скаляр
    auto *q = new Matrix(4);
    q->randomInit();
    q->multiplyBy(5);
    return 0;
}
