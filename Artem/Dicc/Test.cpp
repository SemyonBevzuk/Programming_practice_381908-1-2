#include"Dict.h"

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	string a = "Cat", b = "�����";
	Word word(a, b);
	cout << word;
	Dictionary mass1(word);
	mass1.AddWord("Winter","����");
	mass1.GetTranslation(0);
	mass1.Read("Dic2.txt");
	mass1.Load("Dic1.txt");
	mass1.AddWord("Cinnamon", "������");
	mass1.GetTranslation(3);
	mass1.number_of_words();
	return 0;
}