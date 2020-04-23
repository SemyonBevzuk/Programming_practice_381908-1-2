#include "Text.h"

Dictionary::Dictionary()
{
	this->~Dictionary();
	dictionary.resize(0);
}

Dictionary::Dictionary(int size)
{
	this->~Dictionary();
	dictionary.resize(size);
}

Dictionary::Dictionary(const Dictionary& other)
{
	this->~Dictionary();
	dictionary.resize(other.dictionary.size());
	for (int i = 0; i < other.dictionary.size(); i++)
	{
		dictionary[i] = other.dictionary[i];
	}
}

Dictionary::~Dictionary()
{
	if (!dictionary.empty())
	{
		dictionary.clear();
		dictionary.shrink_to_fit();
	}
}

bool Dictionary::AddWord(wstring eng, wstring rus)
{
	bool flag = true;
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (eng == dictionary[i].first || eng == dictionary[i].second ||
			rus == dictionary[i].first || rus == dictionary[i].second)
			flag = false;
	}
	if (flag)
	{
		dictionary.push_back(make_pair(eng, rus));
		ChangeRegistr();
		SortAlphabet();
	}  
	return flag;
}

bool Dictionary::ChangeTranslation(wstring word, wstring translation)
{
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (word == dictionary[i].first)
		{
			dictionary[i].second = translation;
			return true;
			break;
		}
		if (word == dictionary[i].second)
		{
			dictionary[i].first = translation;
			return true;
			break;
		}
	}
	ChangeRegistr();
	SortAlphabet();
	return false;
}

int Dictionary::FindTranslation(wstring word)
{
	int stroka = -1;
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (word == dictionary[i].first || word == dictionary[i].second)
			stroka = i;
	}
	return stroka;
}

bool Dictionary::FindWord(wstring word)
{
	bool flag = false;
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (word == dictionary[i].first || word == dictionary[i].second)
			flag = true;
	}
	return flag;
}

int Dictionary::Size()
{
	int a = dictionary.size();
	return a;
}

void Dictionary::Clear()
{
	this->~Dictionary();
}

void Dictionary::Resize(int size)
{
	dictionary.resize(size);
}

void Dictionary::PrintStroka(int stroka)
{
	if (stroka >= 0)
	{
		wcout << stroka + 1 << ". ";
		wcout << dictionary[stroka].first;
		wcout << "-";
		wcout << dictionary[stroka].second;
		wcout << "\n";
	}
	else
		wcout << "No matches found" << endl;
}

Dictionary& Dictionary::operator=(const Dictionary& other)
{
	if (this != &other)
	{
		this->~Dictionary();
		for (int i = 0; i < other.dictionary.size(); i++)
		{
			dictionary.push_back(make_pair(other.dictionary[i].first,
				other.dictionary[i].second));
		}
	}
	return* this;
}

Dictionary Dictionary::operator+=(const Dictionary& other)
{
	int a = dictionary.size();
	for (int i = 0; i < other.dictionary.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < a; j++)
		{
			if (dictionary[j].first == other.dictionary[i].first)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		    dictionary.push_back(make_pair(other.dictionary[i].first,
			                               other.dictionary[i].second));
	}
	SortAlphabet();
	return *this;
}

wistream& operator>> (wistream& wistream, Dictionary& c)
{
	for (int i = 0; i < c.dictionary.size(); i++)
	{
		wistream >> c.dictionary[i].first;
		wistream >> c.dictionary[i].second;
	}
	return wistream;
}

wostream& operator<< (wostream& wostream, const Dictionary& c)
{
	for (int i = 0; i < c.dictionary.size(); i++)
	{
		wostream << i+1 << ".";
		wostream << c.dictionary[i].first;
		wostream << " ";
		wostream << c.dictionary[i].second;
		wostream << "\n";
	}
	return wostream;
}

void Dictionary::ChangeRegistr()
{
	int k = 0;
	int l = 0;
	for (int i = 0; i < dictionary.size(); i++)
	{
		while (dictionary[i].first[k])
		{
			dictionary[i].first[k] = tolower(dictionary[i].first[k], locale("rus_rus.866"));
			k++;
		}
		while (dictionary[i].first[l])
	    {
			dictionary[i].second[l] = tolower(dictionary[i].second[l], locale("rus_rus.866"));
			l++;
		}
	}
}

void Dictionary::SortAlphabet()
{
	sort(dictionary.begin(), dictionary.end());
}