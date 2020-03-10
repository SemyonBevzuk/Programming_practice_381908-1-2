#include "Matrix.h"

void main() {
	setlocale(LC_CTYPE, "Russian");
	Matrix A, B(4, 5), C(B), D, E;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 5; j++)
			B(i, j) = 42;
	ifstream is;
	is.open("matrixIn.txt");
	is >> A >> D >> E;
	is.close();
	if (E.IsDiagonallyDominant()) E = E.transpose();
	C = 2 * A + B * 3;
	A = D * C;
	ofstream os;
	os.open("matrixOut.txt");
	os << A << E;
	os.close();
	system("pause");
}