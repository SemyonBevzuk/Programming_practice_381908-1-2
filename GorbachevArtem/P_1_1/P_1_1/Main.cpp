#include <iostream>
#include "Rational.h"
using namespace std;

//----------НАГЛЯДНАЯ ДЕМОНСТРАЦИЯ ФУНКЦИОНАЛА КЛАССА-----------
void main() {
	Rational r1, r2(4, -10), r3(10), r4(r2);
	setlocale(LC_CTYPE, "Russian");
	cout << "---Пример объявления и вывода в поток---" << endl;
	cout << "Rational r1, r2(4, -10), r3(10), r4(r2);" << endl;
	cout << "r1=" << r1 << " r2=" << r2 << " r3=" << r3 << " r4=" << r4 << endl << endl;
	Rational r0, r5, r6, r7, r8, r9;
	cout << "---Пример ввода в поток и присваивания---" << endl;
	cout << "Введите шесть дробей вида n/m:" << endl;
	cin >> r0 >> r5 >> r6 >> r7 >> r8 >> r9;
	cout << "r0=" << r0 << endl;
	cout << "r5=" << r5 << " r6=" << r6 << " r7=" << r7 << " r8=" << r8 << " r9=" << r9 << endl;
	r5 = r0; cout << "r5 = r0;  r5=" << r5 << endl;
	r6 += r0; cout << "r6 += r0;  r6=" << r6 << endl;
	r7 -= r0; cout << "r7 -= r0;  r7=" << r7 << endl;
	r8 *= r0; cout << "r8 *= r0;  r8=" << r8 << endl;
	r9 /= r0; cout << "r9 /= r0;  r9=" << r9 << endl << endl;
	Rational r10, r11;
	cout << "---Пример сравнения---" << endl;
	cout << "Введите две дроби вида n/m:" << endl;
	cin >> r10 >> r11;
	cout << "r10=" << r10 << " r11=" << r11 << endl;
	if (r10 == r11)
		cout << "r10 == r11" << endl;
	if (r10 != r11)
		cout << "r10 != r11" << endl;
	if (r10 > r11)
		cout << "r10 > r11" << endl;
	if (r10 < r11)
		cout << "r10 < r11" << endl;
	if (r10 >= r11)
		cout << "r10 >= r11" << endl;
	if (r10 <= r11)
		cout << "r10 <= r11" << endl;
	cout << endl;
	Rational r12, r13;
	cout << "---Пример арифметических операций---" << endl;
	cout << "Введите две дроби вида n/m:" << endl;
	cin >> r12 >> r13;
	cout << "r12=" << r12 << " r13=" << r13 << endl;
	r0 = r12 + r13; cout << "r12 + r13 = " << r0 << endl;
	r0 = r12 - r13; cout << "r12 - r13 = " << r0 << endl;
	r0 = r12 * r13; cout << "r12 * r13 = " << r0 << endl;
	r0 = r12 / r13; cout << "r12 / r13 = " << r0 << endl << endl;
	system("pause");
}