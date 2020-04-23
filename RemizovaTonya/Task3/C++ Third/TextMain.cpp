#include "Text.h"

int main()
{
	wstring w;//word
	wstring t;//translation
	int dstv;//for the main menu
	int var;//for additional menu (6.1, 6.2)
	wchar_t ch;//for character-by-character reading from the file
	int newsize;//for resize dictionary
	wstring name;//for choose dictionary

	wofstream fsout;
	wifstream fsin;
	fsin.imbue(locale("rus_rus.1251"));
	fsout.exceptions(ios_base::badbit | ios_base::failbit);
	fsout.imbue(locale("rus_rus.1251"));
	wcout.imbue(locale("rus_rus.866"));
	wcin.imbue(locale("rus_rus.866"));

	Dictionary A, B(0), C(A);
	wcout << "Dictionary A:" << endl;
	wcout << A;
	wcout << "Dictionary B:" << endl;
	wcout << B;
	wcout << "Dictionary C:" << endl;
	wcout << C << endl;

	wcout << "There are three dictionaries: A, B, C" << endl;
	wcout << "------------------------------------------------------------" << endl;
met:
	wcout << "                  Menu" << endl;
	wcout << "1.   Add a word and its translation to the dictionary" << endl;
	wcout << "2.   Change the translation of the specified word" << endl;
	wcout << "3.   Find out the translation of the selected word" << endl;
	wcout << "4.   Check for a word in the dictionary" << endl;
	wcout << "5.   Find out the number of words in the dictionary" << endl;
	wcout << "6.1. Save the dictionary to a file" << endl;
	wcout << "6.2. Read the dictionary from the file" << endl;
	wcout << "7.   Combining dictionaries" << endl;
	wcout << "8.   Overwriting the dictionary" << endl;
	wcout << "9.   Clear the dictionary" << endl;
	wcout << "10.  Exit" << endl << endl;

	
	wcin >> dstv;
	switch (dstv)
	{
	case 1:
	{
		wcout << "1.  Add a word and its translation to the dictionary" << endl;

		wcout << "Select dictionary A or B" << endl;
		wcin >> name;
		wcout << "Enter the word for translation: ";
		wcin >> w;
		cout << "Enter translation of the word: ";
		wcin >> t;
		if (name == L"A")
		{
			if (A.AddWord(w, t))
			{
				wcout << "Dictionary A after adding words:" << endl;
				wcout << A << endl << endl;
			}
			else wcout << "Translation of this word is already in the dictionary A" << endl;
		}
		if (name == L"B")
		{
			if (B.AddWord(w, t))
			{
				wcout << "Dictionary B after adding words:" << endl;
				wcout << B << endl << endl;
			}
			else wcout << "Translation of this word is already in the dictionary B" << endl;
		}
		
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 2:
	{
		wcout << "2.  Change the translation of the specified word" << endl;

		wcout << "Select dictionary A or B" << endl;
		wcin >> name;
		wcout << "Enter the word which translation you want to change: ";
		wcin >> w;
		cout << "Enter new translation of the word: ";
		wcin >> t;
		if (name == L"A")
		{
			if (A.ChangeTranslation(w, t))
				cout << "Replacement was successful" << endl;
			else cout << "Entered word is not found" << endl;
			wcout << "Dictionary A after changing translation:" << endl;
			wcout << A << endl;
		}
		if (name == L"B")
		{
			if (B.ChangeTranslation(w, t))
				cout << "Replacement was successful" << endl;
			else cout << "Entered word is not found" << endl;
			wcout << "Dictionary B after changing translation:" << endl;
			wcout << B << endl;
		}
		
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 3:
	{
		wcout << "3.  Find out the translation of the selected word" << endl;

		wcout << "Select dictionary A or B" << endl;
		wcin >> name;
		wcout << "Enter the word which you want to find in the dictionary: ";
		wcin >> w;
		if (name == L"A")
			A.PrintStroka(A.FindTranslation(w));
		if (name == L"B")
			B.PrintStroka(B.FindTranslation(w));
		cout << endl;
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 4:
	{
		wcout << "4.  Check for a word in the dictionary" << endl;

		wcout << "Select dictionary A or B" << endl;
		wcin >> name;
		wcout << "Enter the word which presense you want to check in the dictionary: ";
		wcin >> w;
		if (name == L"A")
		{
			if (A.FindWord(w))
				wcout << "The entered word and its trsnslation are in the dictionary A" << endl << endl;
			else wcout << "The entered word is not found in the dictionary A" << endl << endl;
		}
		if (name == L"B")
		{
			if (B.FindWord(w))
				wcout << "The entered word and its trsnslation are in the dictionary B" << endl << endl;
			else wcout << "The entered word is not found in the dictionary B" << endl << endl;
		}
		
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 5:
	{
		cout << "5.  Find out the number of words in the dictionary" << endl;

		wcout << "Select dictionary A or B" << endl;
		wcin >> name;
		if (name == L"A")
		{
			int s = A.Size();
			cout << "The number of words with translation in the dictionary A is " << s << endl << endl;
		}
		if (name == L"B")
		{
			int s = B.Size();
			cout << "The number of words with translation in the dictionary B is " << s << endl << endl;
		}
		
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 6:
	{
	met1:
		wcout << "Enter 1 to save the dictionary to a file" << endl;
		wcout << "Enter 2 to read the dictionary from the file" << endl;
		wcin >> var;
		switch (var)
		{
		case 1:
		{
			wcout << "6.1.  Save the dictionary to a file" << endl;
			try
			{
				fsout.open(L"Dictionary.txt");
				wcout << L"Dictionary.txt is OPEN" << endl;

				wcout << "Select dictionary A or B" << endl;
				wcin >> name;
				if (name == L"A")
				{
					fsout << A;
					wcout << "The dictionary A is written to the file" << endl;
				}
				if (name == L"B")
				{
					fsout << B;
					wcout << "The dictionary B is written to the file" << endl;
				}
				fsout.close();
			}
			catch (const exception & ex)
			{
				wcout << L"ERROR: " << ex.what() << endl;
			}
		}
		wcout << "Back to the point 6?" << endl;
		wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
		wcin >> dstv;
		if (dstv == 1)
			goto met1;
		else
			break;
		case 2:
		{
			wcout << "6.2.  Read the dictionary from the file" << endl;
			fsin.open(L"Dictionary.txt");
			if (fsin.is_open())
			{
				wcout << L"Dictionary.txt is OPEN" << endl;
				bool ChangeReadableWord = false;
				bool ClearAndWriteLines = true;
				while (fsin.get(ch))
				{
					if (ClearAndWriteLines)
					{
						w = L"";
						t = L"";
						ClearAndWriteLines = false;
					}

					if (ch != '1' && ch != L'2' && ch != L'3' && ch != L'4' && ch != L'5' && ch != L'6'
						&& ch != L'7' && ch != L'8' && ch != L'9' && ch != L'0' && ch != L'.')
					{
						if (!ChangeReadableWord)
						{
							if (ch != L' ')
							{
								w += ch;
							}
							else
							{
								ChangeReadableWord = true;
								fsin.get(ch);
							}
						}

						if (ChangeReadableWord)
						{
							if (ch != L'\n')
								t += ch;
							else
							{
								ChangeReadableWord = false;
								ClearAndWriteLines = true;
							}
						}
					}
					if (ClearAndWriteLines)
						C.AddWord(w, t);
				}
			}
			else wcout << "File open error" << endl;

			wcout << "The dictionary is reading from the file" << endl;
			wcout << C << endl;
			fsin.close();	
		}
		wcout << "Back to the point 6?" << endl;
		wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
		wcin >> dstv;
		if (dstv == 1)
			goto met1;
		else
			break;
		default: wcout << "Digit entered incorrectly" << endl; break;
		}
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 7:
	{
		wcout << "7.  Combining dictionaries" << endl;
		 A += B;
		wcout << "the result of combining dictionaries" << endl;
		wcout << A << endl;
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 8:
	{
		wcout << "8.  Overwriting the dictionary" << endl;
		C = A;
		wcout << "the result of overwriting dictionaries" << endl;
		wcout << C << endl;
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 9:
	{
		wcout << "9. Clear the dictionary" << endl;

		wcout << "Select dictionary A or B" << endl;
		wcin >> name;
		if (name == L"A")
		{
			A.Clear();
			wcout << "The dictionary A is empty" << endl;
		}
		if (name == L"B")
		{
			B.Clear();
			wcout << "The dictionary B is empty" << endl;
		}
	
	}
	wcout << "Back to the menu?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 10:
	{
		wcout << "11. Exit" << endl;
	} break;
	default: break;
	}
}