#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include "Matrix.h"
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	fout.open("output.txt", ios::out);
	ifstream fin("input.txt");
	Matrix m1, m2(2), m3(m2);
	vector<vector<int>>a(2);
	a[0].push_back(1);
	a[0].push_back(2);
	a[1].push_back(3);
	a[1].push_back(4);
	Matrix m4(a);
	fout << "m4:" << endl;
	fout << m4;
	fout << "m2:" << endl;
	fout << m2;
	fin >> m1;
	fout << "m1:" << endl;
	fout << m1;
	if (m1.check_diagonal_dominant())
		fout << "m1 обладает диагональным преобладанием" << endl;
	else
		fout << "m1 не обладает диагональным преобладанием" << endl;
	fout << "m4.transpon:" << endl;
	m4 = m4.transpon();
	fout << m4;
	m2 = m1 + m4;
	fout << "m2 = m1 + m4:" << endl;
	fout << m2;
	m2 *= m4;
	fout << "m2 *= m4:" << endl;
	fout << m2;
	m3 += m2 * 2;
	fout << "m3 += m2 * 2:" << endl;
	fout << m3;
	fout << "m3[0][1]:" << endl;
	fout << m3(0, 1);
	fout.close();
	fin.close();
	return 0;
}