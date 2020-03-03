#include "Matrix.h"

Matrix::Matrix(int size) {
	n = size;
	for (int i = 0; i < n; i++)
	{
		mat.push_back(vector<int>(n));
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& m) {
	n = m.n;
	for (int i = 0; i < n; i++)
	{
		mat.push_back(vector<int>(n));
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = m.mat[i][j];
		}
	}
}
Matrix::Matrix(vector<vector<int>> a) {
	for (int i = 0; i < a.size(); i++)
		if (a[i].size() != a.size())
		{
			throw exception("Аргумент не является квадратной матрицей!");
		}
	n = a.size();
	for (int i = 0; i < n; i++)
	{
		mat.push_back(vector<int>(n));
		for (int j = 0; j < n; j++)
			mat[i][j] = a[i][j];
	}
}
Matrix& Matrix::operator=(const Matrix& m) {
	n = m.n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = m.mat[i][j];
		}
	}
	return *this;
}
Matrix& Matrix::operator+=(const Matrix& m) {
	if (n == m.n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mat[i][j] += m.mat[i][j];
			}
		}
		return *this;
	}
	else
		throw  exception("Размеры матриц не равны!");
}
Matrix& Matrix::operator*=(const Matrix& m) {
	if (n == m.n)
	{
		Matrix tm = *this;
		for (int nstr = 0; nstr < n; nstr++)
			for (int nstb = 0; nstb < n; nstb++)
			{
				mat[nstr][nstb] = 0;
				for (int j = 0; j < n; j++)
					mat[nstr][nstb]+= tm.mat[nstr][j] * m.mat[j][nstb];
			}
		return *this;
	}
	else
		throw  exception("Размеры матриц не равны!");
}
Matrix& Matrix::operator*=(int d) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			mat[i][j] *= d;
		}
	return *this;
}
const Matrix Matrix::operator+(const Matrix& m)const {
	Matrix tm = *this;
	tm += m;
	return tm;
}
const Matrix Matrix::operator*(const Matrix& m)const {
	Matrix tm = *this;
	tm *= m;
	return tm;
}
const Matrix Matrix::operator*(int d)const {
	Matrix tm = *this;
	tm *= d;
	return tm;
}
int& Matrix::operator()(int i, int j){
	if (i >= n || j >= n || i < 0 || j < 0)
		throw exception("Выход за границы матрицы!");
	return mat[i][j];
}
ifstream& operator>>(ifstream& in, Matrix& m) {
	in >> m.n;
	for (int i = 0; i < m.n; i++)
	{
		m.mat.push_back(vector<int>(m.n));
		for (int j = 0; j < m.n; j++)
			in >> m.mat[i][j];
	}
	return in;
}
ofstream& operator<<(ofstream& out, Matrix& m) {
	out << m.n << endl;
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			out << m.mat[i][j] << ' ';
		}
		out << endl;
	}
	return out;
}
bool Matrix::check()const {
	int strog = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (j != i)
				sum += abs(mat[i][j]);
		}
		if (sum < abs(mat[i][i]))
			strog = 1;
		if (sum > abs(mat[i][i]))
		{
			return false;
		}
	}
	if (strog)
		return true;
	return false;
}
Matrix& Matrix::transpon() {
	Matrix tm = *this;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			mat[j][i] = tm.mat[i][j];
		}
	return *this;
}

