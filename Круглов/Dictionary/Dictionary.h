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
	Dictionary(const Dictionary& d);
	void insert(string eng, string rus);
	void insert(pair<string,string> p);
	map <string, string> :: iterator begin();
	map <string, string> ::iterator end();
	int getSize();
	string translateToRussian(string eng);
	string translateToEnglish(string rus);
	void changeTranslation(string eng,string rus);
	bool presence(string eng);// есть ли слово в словаре
	void save();
	void read();
	Dictionary& operator=(const Dictionary& d);
	const Dictionary operator+(const Dictionary& d);
};
