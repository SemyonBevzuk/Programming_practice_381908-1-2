#include"Dict.h"

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	string a = "Cat", b = "Кошка";
	Word word(a, b);
	word.show_word();
	Dictionary mass1(word);
	mass1.AddWord("Winter","Зима");
	mass1.ShowTranslation(0);
	mass1.Read("Dic2.txt");
	mass1.Load("Dic1.txt");
	mass1.AddWord("Cinnamon", "Корица");
	mass1.ShowTranslation(3);
	mass1.number_of_words();
	delete[] mass1.arr;
	return 0;
}