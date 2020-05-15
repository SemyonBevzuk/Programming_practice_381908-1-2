#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

class Matrix {

private:
    vector<vector<int> > matrix;

public:
    Matrix() {
        matrix.resize(1, vector<int>(1, 1));
    }

    Matrix(vector<vector<int> > values) {
        matrix = values;
    }

    Matrix(int sz) {
        matrix.resize(sz, vector<int>(sz));
    }
    
    Matrix(int sz, int value) {
        matrix.resize(sz, vector<int>(sz, value));
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, const int b);

    friend ostream& operator<<(ostream& out, const Matrix& point);
    friend istream& operator>>(istream& in, Matrix& point);

    Matrix& operator= (const Matrix& matr) = default;

    vector<int>& operator[](const int index);
    
    int size() const {
        return matrix.size();
    }

    void transpose() {
        for (int i = 0; i < size(); i++) {
            for (int j = i + 1; j < size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    bool isDiagonalDominated() const {
        int greaterCount = 0;
        for (int i = 0; i < size(); i++) {
            int sum = 0;
            for (int j = 0; j < size(); j++) {
                sum += matrix[i][j] * (i != j);
            }
            if (matrix[i][i] < sum) {
                return false;
            }
            greaterCount += matrix[i][i] > sum;
        }
        return greaterCount > 0;
    }

    void resize(int newSize) {
        matrix.assign(newSize, vector<int>(newSize));
    }

    ~Matrix() {
        matrix.clear();
    }
};

vector<int>& Matrix::operator [](const int index) {
    assert(index >= 0 && index < size());
    return matrix[index];
}

Matrix operator+(const Matrix& a, const Matrix& b) {
    assert(a.size() == b.size());
    Matrix result(a.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            result[i][j] = a.matrix[i][j] + b.matrix[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix& a, const Matrix& b) {
    assert(a.size() == b.size());
    Matrix result(a.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            for (int k = 0; k < a.size(); k++) {
                result[i][j] += a.matrix[i][k] * b.matrix[k][j];
            }
        }
    }
    return result;
}

Matrix operator*(const Matrix& a, const int scalar) {
    Matrix result(a.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            result[i][j] = a.matrix[i][j] * scalar;
        }
    }
    return result;
}

ostream& operator<<(ostream& out, const Matrix& matr) {
    cout << matr.size() << '\n';
    for (auto x : matr.matrix) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << '\n';
    }
    
    return out;
}

istream& operator>> (istream& out, Matrix& matr) {
    int sz;
    cin >> sz;
    matr.resize(sz);
    for (auto& x : matr.matrix) {
        for (auto& y : x) {
            cin >> y;
        }
    }

    return out;
}


int main()
{
    //Предположим, что в матрице только целые числа, иначе пришлось бы писать на целых три символа больше: int -> double
    Matrix gg;
    cin >> gg;
    gg = gg * 2; 

    cout << gg;

    Matrix a(3, 3);
    Matrix b(3, 2);

    auto c = a + b;
    
    cout << c;

    return 0;
}