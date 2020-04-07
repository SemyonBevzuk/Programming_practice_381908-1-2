#include "Matrix.h"

int main()
{
	int chislo; //скаляр
	int row, col; //Строки, столбцы
	int a; //Элемент поиска по индксам
	int size;//Размер матрицы
	cout << "Matrix1" << endl;
	cout << "Size of matrix is 4*4" << endl;
	Matrix m1;
	cout << m1 << endl;
	cout << "Enter the size of matrix from the keyboard: ";
	cin >> size;
	Matrix m2(size);
	cout << "Matrix2 " << endl;
	cout << m2 << endl;
	Matrix m9(m1);
	cout << "Creating a Matrix9 using copy" << endl;
	cout << m9 << endl;

	cout << "Assigment operation of the 2nd matrix to the 1st matrix" << endl;
	m1 = m2;
	cout << "Matrix1 after assignment operation " << endl;
	cout << m1 << endl;

	Matrix m3(3); //Для прибавления
	Matrix m4(4); //Для результата сложения
	cout << "Matrix3 " << endl;
	cout << m3;
	cout << "Matrix addition" << endl;
	try
	{
		m4 = m2 + m3;
		cout << "Matrix4 = M2 + M3:" << endl;
		cout << m4;
		cout << endl;
	}
	catch(int)
	{
		cout << "Error" << endl;
		cout << "Matrices are not equal" << endl;
		cout << "Matrix4" << endl;
		cout << m4 << endl;
	}

	cout << "Transpose operation: M1 = TransM4 " << endl;
	m4.Trans(m1);
	cout << "Matrix M1: " << endl;
	cout << m1 << endl;
	cout << "Matrix M4: " << endl;
	cout << m4 << endl;

	cout << "Check for diagonal transform in Matrix1" << endl;
	cout << "Size of matrix is: 4*4 ";
	cout << "Enter a matrix of this size" << endl;
	Matrix m5;
	if (m5.IsDiagonallyDominant())
	cout << "Diagonal domiant matrix" << endl;
	else 
	cout << "Matrix without diagonal prevalence" << endl;

	cout << "Scalar matrix multiplication M1 = M3*scalar" << endl;
	cout << "Enter scalar: ";
	cin >> chislo;
	m1 = m3 * chislo;
	cout << "Scalar multiplication result " << endl;
	cout << m1 << endl;

	cout << "Three new matrices M6,M7,M8:" << endl;
	cout << "Enter the size of Matrix6: ";
	cin >> size;
	Matrix m6(size);
	cout << "Enter the size of Matrix7: ";
	cin >> size;
	Matrix m7(size);
	cout << "Matrix7 " << endl;
	cout << m7;
	cout << "Enter the size of Matrix8: ";
	cin >> size;
	Matrix m8(size);
	cout << "Matrix8 " << endl;
	cout << m8;
	cout << "Matrix multiplication M6 = M7*M8" << endl;
	try
	{
		m6 = m7 * m8;
		cout << "Matrix6 is a multiplication result " << endl;
		cout << m6;
	}
	catch (int)
	{
		cout << "Error" << endl;
		cout << "Matrices are not equal" << endl;
		cout << "Matrix6" << endl;
		cout << m6 << endl;
	}
	

	cout << "Indexing operation" << endl;
	cout << "Enter the row number ";
	cin >> row;
	cout << "Enter the column number ";
	cin >> col;
	try
	{
		cout << "Saerch element: " << m6(row, col) << endl;
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
			fs << m6;
			cout << "The matrix is written to the file" << endl;
			fs.close();
			goto met;
		}
		case 2:
		{
			int count_space = 0; //Число пробелов в начале строки
			char ch;//Для посимвольного считывания
			while (!fs.eof())
			{
				fs.get(ch);//Считываем текущий символ
				if (ch == ' ')//Если пробел
					count_space++;//Увеличиваем число пробелов
				if (ch == '\n')//Если переход на новую строчку
					break;//Выходим из цикла
			}
			fs.seekg(0, ios::beg);//Идем в начало файла в потоке
			fs.clear();
			//Теперь мы знаем сколько пробелов в строке
			int n = count_space;//Число строк равно числу столбцов, поэтому достаточно только одной переменной
			Matrix m9(n);
			fs >> m9;
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