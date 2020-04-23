#include"Matrix.h"

using namespace std;

int main()
{
	Matrix matr1, matr2(2, 1), matr3(matr2), matr4(3), matr5(3, 1), matr6(3, 3);
	ifstream fin;
	ofstream fout;
	fin.open("MatrIn.txt");
	fout.open("MatrixResult.txt");
	matr3 = matr1 + matr2;
	fout << "The result of adding two matrixes together:" << endl;
	fout << matr3;
	fout << "The fourth matrix:" << endl;
	fin >> matr4;
	fin.close();

	fout << matr4;
	matr4 = matr4.Transpose();
	fout << "The transposed matrix" << endl;
	fout << matr4;
	matr4 = matr4 * matr5;
	fout << "The result of multiplication of two matrixes:" << endl;
	fout << matr4;
	matr5 = matr6;
	fout << "The fifth matrix:" << endl;
	fout << matr5;
	if (matr3.IsDagonalDominance())
		fout << "The matrix has diagonal dominance" << endl;
	else
		fout << "The matrix does not have diagonal domination" << endl;
	fout << "The result of multiplication by a number:" << endl;
	matr4 = matr4 * 2;
	fout << matr4;

	fout.close();

	return 0;
}