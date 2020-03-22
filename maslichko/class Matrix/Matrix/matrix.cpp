#include"matrix.h"
#include <chrono>
#include <ctime>

//Конструктор
void Matrix::Create()
{
    mat = new int* [row];
    for (int i = 0; i < row; i++)
    {
        mat[i] = new int[row];
    }
}

Matrix::Matrix(const Matrix& m)
{
    row = m.row;
    Create();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            mat[i][j] = m.mat[i][j];
        }
    }
}

Matrix::Matrix(int _row, int elem)
{
    row = _row;
    Create();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            mat[i][j] = elem;
        }
    }
}

//Деструктор
Matrix :: ~Matrix()
{
    for (int i = 0; i < row; i++)
        delete[] mat[i];
    if (mat != NULL)
        delete[] mat;
    row = 0;
}

//Методы
bool Matrix::Diagonal()
{
    for (int i = 0; i < row; i++)
    {
        long long sum = 0;
        for (int j = 0; j < row; j++)
        {
            if (j == i) continue;
            sum += abs(mat[i][j]);
        }
        if (sum > abs(mat[i][i]))
            return 0;
    }
    return 1;
}

Matrix Matrix::Transpos()
{
    Matrix res(row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            res(j, i) = mat[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(const int x)
{
    Matrix res(row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            res(i, j) = mat[i][j] * x;
        }
    }
    return res;
}

Matrix Matrix::operator*(const Matrix& m)
{
    if (row == m.row)
    {
        Matrix res(row);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++)
            {
                int x = 0;
                for (int k = 0; k < row; k++)
                    x += mat[i][k] * m.mat[k][j];
                res(i, j) = x;
            }
        }
        return res;
    }
    else
    {
        cout << "Матрицы имеют разрый ранг" << endl;
        system("pause");
        exit(0);
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{
    if (this == &m) return *this;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            mat[i][j] = m.mat[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& m)
{
    if (row == m.row)
    {
        Matrix res(row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row; j++)
            {
                res(i, j) = mat[i][j] + m.mat[i][j];
            }
        }
        return res;
    }
    else
    {
        cout << "Матрицы имеют разрый ранг" << endl;
        system("pause");
        exit(0);
    }
}

int& Matrix::operator()(int i, int j)
{
    if (i < row && j < row && i >= 0 && j >= 0)
    {
        //cout << mat[i][j];
        return mat[i][j];
    }
    else
    {
        cout << "Такого элемента нет" << endl;
        system("pause");
        exit(0);
    }
}

//Ввод и вывод
ostream& operator<<(ostream& ofstream, const Matrix& m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.row; j++)
        {
            ofstream << m.mat[i][j] << " ";
        }
        ofstream << "\n";
    }
    return ofstream;
}

istream& operator>>(istream& ofstream, Matrix& m)
{
    cout << "Введите количество элементов в строке";
    int r;
    cin >> r;
    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            ofstream >> m.mat[i][j];
        }
    }
    return ofstream;
}
