#include <string>
#include <set>
#include <map>

using namespace std;

class Dictionary
{
private:
	map <string, string> Dict;
	map <string, string> ::iterator it;
public:
	Dictionary();
	Dictionary(Dictionary& d);
	void insert(string eng, string rus);
	void insert(pair<string,string> p);
	map <string, string> ::iterator begin();
	map <string, string> ::iterator end();
	int size();
	string Translate(string eng);
	void ChangeTranslation(string eng,string rus);
	bool Presence(string eng);// есть ли слово в словаре
	void Save();
	void Read();
	Dictionary& operator=(Dictionary& d);
	Dictionary operator+(Dictionary& d);
};
