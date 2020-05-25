#include "Film.h"

int main()
{
	int dstv;
	wstring _searchname;
	wstring _name;
	wstring _producer;
	wstring _screenwriter;
	wstring _composer;
	int _day;
	int _month;
	int _year;
	int _cashfees;
	int _sum;

	wofstream fsout;
	wifstream fsin;
	fsin.imbue(locale("rus_rus.1251"));
	fsout.exceptions(ios_base::badbit | ios_base::failbit);
	fsout.imbue(locale("rus_rus.1251"));
	wcout.imbue(locale("rus_rus.866"));
	wcin.imbue(locale("rus_rus.866"));

	MovieClass Library, ReadLibrary;
	wcout << "MovieClass Library:" << endl;
	wcout << Library;
	/*wcout << "Check" << endl;
	wcin >> day;
	cout << "Enter: " << day;*/


	wcout << "----------------------------------------------------------------------" << endl;
met:
	wcout << " Menu" << endl;
	wcout << "1.1. Save the movie library to a file" << endl;
	wcout << "1.2. Read a movie library from a file" << endl;
	wcout << "2. Add a movie" << endl;
	wcout << "3. Change the data for the movie selected by name" << endl;
	wcout << "4. Find a movie by name and year" << endl;
	wcout << "5. Give out all films of the specified Director" << endl;
	wcout << "6. Give out all films released in the selected year" << endl;
	wcout << "7. Give out the specified number of movies with the highest fees" << endl;
	wcout << "8. Give out the specified number of movies with the highest fees in the selected year" << endl;
	wcout << "9. Find out the current number of movies" << endl;
	wcout << "10. Delete a movie by name" << endl;
	wcout << "11. Exit" << endl << endl;

	wcin >> dstv;
	switch (dstv)
	{
	case 1:
	{
	met1:
		wcout << "Enter 1 to save the film to a file or 2 to read the film from the file" << endl;
		wcin >> dstv;
		if (dstv == 1)
		{
			wcout << "1.1. Save the film to a file" << endl;
			try
			{
				fsout.open(L"FilmLibrary.txt");
				wcout << L"FilmLibrary.txt is OPEN" << endl;
				fsout << Library;
				wcout << "The Film library is written to the file" << endl;
				fsout.close();
			}
			catch (const exception & ex)
			{
				wcout << L"ERROR: " << ex.what() << endl;
			}
			wcout << "Back to the point 1?" << endl;
			wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
			wcin >> dstv;
			if (dstv == 1)
				goto met1;
			else
				break;
		}

		if (dstv == 2)
		{
			wcout << "1.2. Read the film from the file" << endl;
			fsin.open(L"FilmLibrary.txt");
			if (fsin.is_open())
			{
				wcout << L"FilmLibrary.txt is OPEN" << endl;
				int d = 0; //Number of films from the Film libray
				fsin >> d;
				wcout << d << endl;
				fsin.seekg(0, ios::beg);//Идем в начало файла в потоке
				fsin.clear();
				ReadLibrary.Resize(d);
				fsin >> ReadLibrary;
			}
			else wcout << "File open error" << endl;

			wcout << "The dictionary is reading from the file" << endl;
			wcout << ReadLibrary << endl;
			fsin.close();

			wcout << "Back to the point 1?" << endl;
			wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
			wcin >> dstv;
			if (dstv == 1)
				goto met1;
			else
				break;
		}
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 2:
	{
		wcout << "2. Add a movie" << endl;
		

		wcout << "Enter the name and information about the movie:" << endl;
		wcout << "Name: ";
		wcin >> _name;
		wcout << "Producer: ";
		wcin >> _producer;
		wcout << "Screenwriter: ";
		wcin >> _screenwriter;
		wcout << "Composer: ";
		wcin >> _composer;
		wcout << "Day: ";
		wcin >> _day;
		wcout << "Month: ";
		wcin >> _month;
		wcout << "Year: ";
		wcin >> _year;
		while (!CheckingTheDate(_day, _month, _year))
		{
			wcout << "Nhe date was entered invorrectly, please enter the date again" << endl;
			wcout << "Day: ";
			wcin >> _day;
			wcout << "Month: ";
			wcin >> _month;
			wcout << "Year: ";
			wcin >> _year;
		}
		wcout << "Cashfees: ";
		wcin >> _cashfees;
		if (Library.AddFilm(_name, _producer, _screenwriter, _composer, _day, _month, _year, _cashfees))
		{
			wcout << "The movie was added to the movie library" << endl;
			wcout << Library;
		}
		else wcout << "Information about the movie with the specified name is already present in the movie library" << endl;
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 3:
	{
		wcout << "3. Change the data for the movie selected by name" << endl;
		
		wcout << "Enter the search name and new information about the movie:" << endl;
		wcout << "Cearch Name: ";
		wcin >> _searchname;
		wcout << "New Name: ";
		wcin >> _name;
		wcout << "Producer: ";
		wcin >> _producer;
		wcout << "Screenwriter: ";
		wcin >> _screenwriter;
		wcout << "Composer: ";
		wcin >> _composer;
		wcout << "Day: ";
		wcin >> _day;
		wcout << "Month: ";
		wcin >> _month;
		wcout << "Year: ";
		wcin >> _year;
		while (!CheckingTheDate(_day, _month, _year))
		{
			wcout << "Nhe date was entered invorrectly, please enter the date again" << endl;
			wcout << "Day: ";
			wcin >> _day;
			wcout << "Month: ";
			wcin >> _month;
			wcout << "Year: ";
			wcin >> _year;
		}
		wcout << "Cashfees: ";
		wcin >> _cashfees;

		if (Library.ChangeInformation(_searchname, _name, _producer, _screenwriter, _composer, _day, _month, _year, _cashfees))
		{
			wcout << "The movie information was successfully changed" << endl;
			wcout << Library;
		}
		else wcout << "The film was not found in the film library" << endl;
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 4:
	{
		wcout << "4. Find a movie by name and year" << endl;
		
		wcout << "Enter the name of the movie: ";
		wcin >> _name;
		wcout << "Enter the release year of the movie: ";
		wcin >> _year;
		wcout << "Movie found by name and year" << endl;
		if (Library.SearchFilm(_name, _year).size() == 0)
			wcout << "Film is not founf in the film library" << endl;
		else
			Library.PrintListOfFilms(Library.SearchFilm(_name, _year));
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 5:
	{
		wcout << "5. Give out all films of the specified Director" << endl;
		
		wcout << "Enter the name of the producer whose movie list you want to display: ";
		wcin >> _producer;
		wcout << "List of films released in a given year: " << endl;
		Library.PrintListOfFilms(Library.SearchByProducer(_producer));
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 6:
	{
		wcout << "6. Give out all films released in the selected year" << endl;
		
		wcout << "Enter the year in which the search is performed: ";
		wcin >> _year;
		wcout << "List of films released in a given year: " << endl;
		Library.PrintListOfFilms(Library.SearchByYear(_year));
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 7:
	{
		wcout << "7. Give out the specified number of movies with the highest fees" << endl;
		
		wcout << "Enter the number of movies to display on the screen: ";
		wcin >> _sum;
		wcout << "List of films, sorted in descending order of monetary fees" << endl;
		Library.PrintListOfFilms(Library.HighestFees(_sum));
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 8:
	{
		wcout << "8. Give out the specified number of movies with the highest fees in the selected year" << endl;
		
		wcout << "Enter the number of movies to display on the screen: ";
		wcin >> _sum;
		wcout << "Enter the year in which the search is performed: ";
		wcin >> _year;
		wcout << "List of films, sorted in descending order of monetary fees" << endl;
		Library.PrintListOfFilms(Library.HighestFeesPerYear(_sum, _year));
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 9:
	{
		wcout << "9. Find out the current number of movies" << endl;
		
		wcout << "Number of films in the film library is: " << Library.NumberOfFilmsInTheLibrary();
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 10:
	{
		wcout << "10. Delete a movie by name" << endl;
		
		wcout << "enter the name of the movie to delete from the movie library" << endl;
		wcout << "Name: ";
		wcin >> _name;
		if (Library.DeleteFilmFromTheLibrary(_name))
		{
			wcout << "The movie was successfully removed from the movie library" << endl;
			wcout << Library;
		}
		else wcout << "The film was not found in the film library" << endl;
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter 1 to answer positively or any number to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 11:
	{
		wcout << "11. Exit" << endl;
	}break;
	default: break;
	}
}