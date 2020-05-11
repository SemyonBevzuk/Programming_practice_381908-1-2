#include "FilmClass.h"

void FilmClass::Add(string title, string producer, string screenwriter, string composer, string data, long long fees)
{
	title_vector.push_back(title);
	producer_vector.push_back(producer);
	screenwriter_vector.push_back(screenwriter);
	composer_vector.push_back(composer);
	data_vector.push_back(data);
	fees_vector.push_back(fees);
}

void FilmClass::Change(string title, string producer, string screenwriter, string composer, string data, long long fees)
{
	int index = -1;
	for (int i = 0; i < title_vector.size(); i++)
	{
		if (title_vector[i] == title)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		cout << endl << "There is no such film.";
	}
	else
	{
		producer_vector[index] = producer;
		screenwriter_vector[index] = screenwriter;
		composer_vector[index] = composer;
		data_vector[index] = data;
		fees_vector[index] = fees;

		cout << endl << "Changes applied.";
	}
}

vector<string> FilmClass::Find(string title, int year)
{
	vector<string> film_data;
	vector<string> interim;
	string movie_year;
	int index = -1;
	for (int i = 0; i < title_vector.size(); )
	{
		if (title_vector[i] == title) //Ищем название фильма
		{
			movie_year = ParseDate(data_vector[i]);

			if (movie_year == to_string(year))
			{
				index = i;
				break;
			}
			else
			{
				movie_year.clear();
				i++;
			}
		}
		else i++;
	}

	if (index == -1)
	{
		cout << endl << "There is no such film.";
	}
	else
	{
		film_data.push_back(title_vector[index]);
		film_data.push_back(producer_vector[index]);
		film_data.push_back(screenwriter_vector[index]);
		film_data.push_back(composer_vector[index]);
		film_data.push_back(data_vector[index]);
		film_data.push_back(to_string(fees_vector[index]));
	}

	return film_data;
}

vector<string> FilmClass::MovieSearch(string producer)
{
	vector<string> temp_producer;
	for (int i = 0; i < producer_vector.size(); i++)
	{
		if (producer_vector[i] == producer)
		{
			temp_producer.push_back(title_vector[i]);
		}
	}
	return temp_producer;
}

vector<string> FilmClass::MovieSearch(int year)
{
	vector<string> temp_year;
	string index;
	for (int i = 0; i < data_vector.size(); i++)
	{
		index = ParseDate(data_vector[i]);
		if (index == to_string(year))
		{
			temp_year.push_back(title_vector[i]);
		}
	}
	return temp_year;
}

vector<string> FilmClass::NumberFilms(int quantity)
{
	vector<string> temp_fees;
	vector<long long> temp = fees_vector;

	for (int i = 0; i < quantity; i++)
	{
		int maxElementIndex = max_element(temp.begin(), temp.end()) - temp.begin(); //ищем максимальный элемент в векторе
		temp_fees.push_back(title_vector[maxElementIndex]);
		temp[maxElementIndex] = 0;
	}

	return temp_fees;
}

vector<string> FilmClass::NumberFilms(int quantity, int year)
{
	vector<string> temp_fees_year;
	vector<long long> temp = fees_vector;
	string data_temp;
	int i = 0;

	for (int j = 0; j < temp.size(); j++)
	{
		int maxElementIndex = max_element(temp.begin(), temp.end()) - temp.begin(); //ищем максимальный элемент в векторе
		data_temp = ParseDate(data_vector[maxElementIndex]);
		if (data_temp == to_string(year))
		{
			temp_fees_year.push_back(title_vector[maxElementIndex]);
			temp[maxElementIndex] = 0;
			i++;
		}
		else
		{
			temp[maxElementIndex] = 0;
		}

		if (i == quantity)
		{
			break;
		}
	}
	return temp_fees_year;
}

int FilmClass::Total()
{
	return title_vector.size();
}

void FilmClass::DeleteMovie(string title)
{
	int index = -1;
	for (int i = 0; i < title_vector.size(); i++)
	{
		if (title_vector[i] == title)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		cout << endl << "There is no such film.";
	}
	else
	{
		title_vector.erase(title_vector.begin() + index);
		producer_vector.erase(producer_vector.begin() + index);
		screenwriter_vector.erase(screenwriter_vector.begin() + index);
		composer_vector.erase(composer_vector.begin() + index);
		data_vector.erase(data_vector.begin() + index);
		fees_vector.erase(fees_vector.begin() + index);
	}
}

void FilmClass::SaveLibraru() //Сохраняем библиотеку в файл
{
	ofstream fout; //поток
	fout.open("Save.txt"); // окрываем файл для записи
	for (int i = 0; i < title_vector.size(); i++)
	{
		fout << title_vector[i] << endl;
		fout << producer_vector[i] << endl;
		fout << screenwriter_vector[i] << endl;
		fout << composer_vector[i] << endl;
		fout << data_vector[i] << endl;
		fout << fees_vector[i] << endl;
		fout << endl;
	}
	fout.close();
}

void FilmClass::ReadLibraryr() //Читаем из файла
{
	string title, producer, screenwriter, composer, data, temp;
	long long fees;

	ifstream fin("Read.txt"); // окрываем файл для чтения(файл в кодировке ANSI)
	//Считаем количество фильмов в файле
	char* str = new char[1024];
	int number_lines = 0;
	while (!fin.eof())
	{
		fin.getline(str, 1024, '\n');
		number_lines++;
	}

	fin.clear(); //Убираем флаг конца файла

	fin.seekg(0); //Переводим курсор в начала файла
	delete[] str; //Ощичаем память
	int number_films = number_lines / 6; //Считаем количество фильмов в файле

	//Заносим данные в библиотеку
	for (int i = 0; i < 3; i++)
	{
		fin.get();
		getline(fin, title);
		getline(fin, producer);
		getline(fin, screenwriter);
		getline(fin, composer);
		getline(fin, data);
		fin >> fees;
		getline(fin, temp); //Читаем пустую строку как разделитель фильмов
		Add(title, producer, screenwriter, composer, data, fees);
	}
	fin.close(); //Закрываем файл
}

string FilmClass::ParseDate(string data)
{
	vector<string> interim;
	interim.clear();
	string line = data + '.'; //строка с датой, достаем из нее год
	string buffer = "";      //буфферная строка
	for (int i = 0; i < line.size(); i++) {
		if (line[i] != '.') {      // "." сплиттер
			buffer += line[i];
		}
		else {
			interim.push_back(buffer);
			buffer = "";
		}
	}
	return interim[2]; //возвращаем год
}
