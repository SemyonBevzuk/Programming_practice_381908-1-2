#include "Dictionary.h"

void main() {
	setlocale(LC_CTYPE, "Russian");
	string en[] = {"chair", "window"}, ru[] = {"стул", "окно"};
	Dictionary A, B(2, en, ru), C({"sky", "nature"}, {"небо","природа"}), D(C);
	A = B + D;
	ifstream is;
	is.open("DictionaryIn.txt");
	is >> D;
	is.close();
	D += A;
	D.AddWord("expectation", "ощущение");
	D.ChangeTranslation("expectation", "ожидание");
	ofstream os;
	os.open("DictionaryOut.txt");
	os << D;
	os.close();
	cout << D.Size() << endl;
	if (D.IsContain("природа"))
		cout << "true" << endl;
	cout << D.Translate("природа") << endl;
	system("pause");
}