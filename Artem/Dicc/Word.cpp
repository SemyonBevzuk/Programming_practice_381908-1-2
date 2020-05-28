#include"Dict.h"

Word::Word()
{
	eng_word = "";
	rus_word = "";
}

Word::Word(string word, string translation)
{
	eng_word = word;
	rus_word = translation;
}

void Word::set_eng_word(string word)
{
	eng_word = word;
}

void Word::set_rus_word(string word)
{
	rus_word = word;
}

bool operator==(const Word& left, const Word& right)
{
	if ((left.eng_word == right.eng_word) && (left.rus_word == right.rus_word))
		return true;
	else return false;
}

ostream& operator<<(ostream& stream, const Word& dict)
{
	stream << dict.eng_word << " - " << dict.rus_word << endl;
	return stream;
}