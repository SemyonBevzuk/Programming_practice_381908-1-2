#include "Matrix.h"

int main()
{
	int chislo; //скаляр
	int row, col; //Строки, столбцы
	int a; //Элемент поиска по индксам
	int size;//Размер матрицы
	Matrix m1;
	cout << "Matrix1 " << endl;
	m1.Print();
	cout << "Enter the size of matrix from the keyboard: ";
	cin >> size;
	Matrix m2(size);
	cout << "Matrix2 " << endl;
	m2.Print(); 
	cout << endl;

	cout << "Assigment operation of the 2nd matrix to the 1st matrix" << endl;
	m1 = m2;
	cout << "Matrix1 after assignment operation " << endl;
	m1.Print();
	cout << endl;

	cout << "Matrix addition" << endl;
	Matrix m3(3); //Для прибавления
	cout << "Matrix3 " << endl;
	m3.Print();
	Matrix m4; //Для результата сложения
	m4 = m2 + m3;
	cout << "Matrix4 = M2 + M3:" << endl;
	m4.Print(); cout << endl;

	cout << "Transpose operation: M4 = TransM1 " << endl;
	m4.Trans(m1);
	cout << endl;

	cout << "Check for diagonal transform in Matrix1" << endl;
	Matrix m5;
	cout << "Introduce Matrix5 from the keyboard" << endl;
	m5.CheckM();
	m5.Diagonal();
	cout << endl;

	cout << "Scalar matrix multiplication M1 = M3*scalar" << endl;
	cout << "Enter scalar: ";
	cin >> chislo;
	m1 = m3* chislo;
	cout << "Scalar multiplication result " << endl;
	m1.Print();
	cout << endl;

	cout << "Three new matrices M6,M7,M8:" << endl;
	Matrix m6, m7, m8;
	cout << "Matrix7 " << endl;
	m7.Print();
	cout << "Matrix8 " << endl;
	m8.Print();
	cout << "Matrix multiplication M6 = M7*M8" << endl;
	m6.MultiplyM(m7, m8);
	cout << "Matrix6 is a multiplication result " << endl;
	m6.Print();
	cout << endl;

	cout << "Indexing operation" << endl;
	cout << "Enter the row number ";
	cin >> row;
	cout << "Enter the column number ";
	cin >> col;
	m6(row, col);
	cout << endl;

	//*Чтение и сохранение данных из файла/в файл для перегрузки операторов << >>
	fstream fs;
    met:
	fs.open("FileMat.txt", fstream::in | fstream::out); //Ввод, вывод, без дозаписи!!
	if (!fs.is_open())
		cout << "File open error" << endl;
	else
	{
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
	fs.close();
}