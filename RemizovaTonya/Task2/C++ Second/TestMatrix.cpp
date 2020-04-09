#include "Matrix.h"

int main()
{
	int chislo; //скаляр
	int row, col; //Строки, столбцы
	int a; //Элемент поиска по индксам
	int size;//Размер матрицы
	cout << "Matrix1 default" << endl;
	cout << "Size of matrix is 4*4" << endl;
	Matrix m1;
	cout << "Fill the Matrix1 randomly" << endl;
	m1.RandomM(4);
	cout << m1 << endl;
	cout << "Enter the size of matrix from the keyboard: ";
	cin >> size;
	Matrix m2(size);
	cout << "Matrix2 " << endl;
	cout << "Fill the Matrix2 randomly" << endl;
	m2.RandomM(size);
	cout << m2 << endl;
	Matrix m12(m1);
	cout << "Creating a Matrix12 using copy" << endl;
	cout << m12 << endl;

	cout << "Assigment operation of the 2nd matrix to the 1st matrix" << endl;
	m1 = m2;
	cout << "Matrix1 after assignment operation " << endl;
	cout << m1 << endl;

	Matrix m3; //Для прибавления
	m3.RandomM(3);
	cout << "Random Matrix3" << endl;
	cout << m3;
	cout << "Random Matrix2" << endl;
	cout << m2;
	cout << "Matrix addition" << endl;
	try
	{
		Matrix m4 = m2 + m3;
		cout << "Matrix4 = M2 + M3:" << endl;
		cout << m4;
		cout << endl;
	}
	catch(int)
	{
		cout << "Error" << endl;
		cout << "Matrices are not equal" << endl;
	}

	cout << "Transpose operation: M5 = TransM4 " << endl;
	Matrix m4;
	m4.RandomM(5);
	Matrix m5 = m4.Trans();
	cout << "Matrix M4: " << endl;
	cout << m4 << endl;
	cout << "Matrix M5: " << endl;
	cout << m5 << endl;

	Matrix m6;
	cout << "Check for diagonal transform in Matrix6" << endl;
	cout << "Size of matrix is: 4*4 " << endl;
	cout << "Enter a matrix of this size" << endl;
	cin >> m6;
	if (m6.IsDiagonallyDominant())
	cout << "Diagonal domiant matrix" << endl;
	else 
	cout << "Matrix without diagonal prevalence" << endl;

	cout << "Scalar matrix multiplication M7 = M5*scalar" << endl;
	cout << "Enter scalar: ";
	cin >> chislo;
	Matrix m7 = m5 * chislo;
	cout << "Scalar multiplication result " << endl;
	cout << m7 << endl;

	cout << "Three new matrices M8,M9,M10:" << endl;
	Matrix m8, m9;
	cout << "Enter the size of Matrix8: ";
	cin >> size;
	m8.RandomM(size);
	cout << "Matrix8 " << endl;
	cout << m8;
	cout << "Enter the size of Matrix9: ";
	cin >> size;
	m9.RandomM(size);
	cout << "Matrix9 " << endl;
	cout << m9;
	cout << "Matrix multiplication M10 = M8*M9" << endl;
	try
	{
		Matrix m10 = m8 * m9;
		cout << "Matrix6 is a multiplication result " << endl;
		cout << m10;
	}
	catch (int)
	{
		cout << "Error" << endl;
		cout << "Matrices are not equal" << endl;
	}
	
	Matrix m10;
	m10.RandomM(5);
	cout << "Matrix10 " << endl;
	cout << m10 << endl;
	cout << "Indexing operation" << endl;
	cout << "Enter the row number ";
	cin >> row;
	cout << "Enter the column number ";
	cin >> col;
	try
	{
		cout << "Saerch element: " << m10(row, col) << endl;
	}
	catch (int)
	{
		cout << "Error" << endl;
		cout << "Indexes outside the array" << endl << endl;
	}

	//*Чтение и сохранение данных из файла/в файл для перегрузки операторов << >>
	fstream fs;
met:
	fs.exceptions(fstream::badbit | fstream::failbit);
	fs.open("FileMat.txt", fstream::in | fstream::out); //Ввод, вывод, без дозаписи!!
	try
	{
		fs.is_open();
		int a; //Для вызова чтения или записи в файл
		string str;
		cout << "File is open" << endl;
		cout << "Enter 1 to write the class to the file" << endl;
		cout << "Enter 2 to read the class from the file" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			fs << m10;
			cout << "The matrix is written to the file" << endl;
			fs.close();
			goto met;
		}
		case 2:
		{
			int sizem;
			char ch;//Для посимвольного считывания
			string s;
			int b = 0;//bytes
			do 
			{
				fs.get(ch);
				s += ch;
				b++;
			} while (ch != '\n');
			sizem = atoi(s.c_str());
			fs.seekg(b, ios::beg);//Идем в начало файла в потоке
			fs.clear();
			Matrix m11(sizem);
			cout << "Matrix11 from file, size is: ";
			fs >> m11;
			cout << m11;
		}break;
		default:
		{
			cout << "Incorrect file action selection" << endl;
		}
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
		cout << "File open error" << endl;
	}
	fs.close();
}