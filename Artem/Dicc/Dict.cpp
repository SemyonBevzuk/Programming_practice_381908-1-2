#include"Dict.h"

Dictionary::Dictionary() 
{
	size = 0;
	arr = new Word[size];
}

Dictionary::Dictionary(const Word word) 
{
	size = 1;
	arr = new Word[size];
	arr[0] = word;
}

Dictionary::Dictionary(const Dictionary& dict)
{
	size = dict.size;
	arr = new Word[size];
	for (int i = 0; i < size; i++)
		arr[i] = dict.arr[i];
}

Dictionary::~Dictionary()
{
	if(arr!=nullptr)
		delete[] arr;
	size = 0;
}

void Dictionary::AddWord(string word, string translation) 
{
	if (size == 0)
	{
		size = 1;
		arr = new Word[size];
		arr[0] = Word(word, translation);
		return;
	}
	size += 1;
	Word* tmp;
	tmp = new Word[size - 1];
	for (int i = 0; i < size - 1; ++i)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = new Word[size];
	for (int i = 0; i < size - 1; ++i)
		arr[i] = tmp[i];
	delete[] tmp;
	arr[size - 1] = Word(word, translation);

	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = (size - 1); j > i; --j)
		{
			if (arr[j - 1].get_eng_word() > arr[j].get_eng_word())
			{
				Word temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void Dictionary::ChangeTranslation(int index, string translation) 
{
	if (index != -1) 
		arr[index].set_rus_word(translation);
}

string Dictionary::GetTranslation(int index)
{
	return arr[index].get_rus_word();
}

int Dictionary::index_of_word(string word) 
{
	for (int i = 0; i < size; ++i) 
	{
		if (arr[i].get_eng_word() == word) 
		{
			cout << "The word was found" << endl;
			return i;
		}
	}
	cout << "The word wasnt found" << endl;
	return -1;
}

int Dictionary::number_of_words()
{
	return size;
}

void Dictionary::Read(string filename)
{
	ifstream file;
	string word, translation, str;
	int tmp = 0;
	file.open(filename, ios::in);
	if (!file.is_open()) cout << "Cant open file" << endl;
	while (getline(file, str)) 
	{
		tmp++;
		if (tmp == 1) 
			word = str;
		if (tmp == 2)
			translation = str;
		if (tmp == 2) 
		{
			this->AddWord(word, translation);
			tmp = 0;
		}
	}
	file.close();
}

void Dictionary::Load(string filename)
{
	ofstream file;
	file.open(filename, ios::app);
	if (!file.is_open()) cout << "Can't open file" << endl;
	for (int i = 0; i < size; ++i)
	{
		file << arr[i].get_eng_word()<<" ";
		file << arr[i].get_rus_word() << endl;
		file << endl;
		file.flush();
	}
	cout << "The data is recorded!" << endl;
	file.close();
}

Word& Dictionary::operator[](const int index)
{
	if (index < 0 || index >= this->size) throw std::out_of_range("Out of range!");
	return arr[index];
}

Dictionary& Dictionary::operator=(Dictionary& arr_)
{
if (this != &arr_)
	{
		size = arr_.size;
		delete[] arr;
		arr = new Word[size];
		for (int i = 0; i < size; ++i)
			arr[i] = arr_[i];
	}
	return *this;
}

Dictionary Dictionary::operator+(Dictionary& arr_)
{
	if (size == 0) 
	{
		size += arr_.size;
		arr = new Word[size];
		for (int i = 0; i < size; ++i)
			arr[i] = arr_[i];
		return *this;
	}
	Word* tmp;
	tmp = new Word[size];
	for (int i = 0; i < size; ++i)
		tmp[i] = arr[i];
	delete[] arr;
	size += arr_.size;
	arr = new Word[size];
	for (int i = 0; i < size - arr_.size; ++i)
		arr[i] = tmp[i];
	delete[] tmp;
	for (int i = size - arr_.size, j = 0; i < size; ++i, ++j) 
		arr[i] = arr_[j];
	return *this;
}
