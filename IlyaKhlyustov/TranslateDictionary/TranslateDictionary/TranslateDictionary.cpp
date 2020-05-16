#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

vector<string> split(string str, char sep = ' ') {
    vector<string> result;
    str += sep;
    string currentStr = "";
    for (auto s : str) {
        if (s == sep) {
            if (!currentStr.empty()) result.emplace_back(currentStr);
            currentStr.clear();
        }
        else {
            currentStr += s;
        }
    }
    return result;
}

class TranslateDictionary {

private:
    unordered_map<string, vector<string> > dict;

public:

    TranslateDictionary() = default;

    TranslateDictionary(unordered_map<string, vector<string> > startTranslations) {
        dict = startTranslations;
    }

    friend TranslateDictionary operator+(const TranslateDictionary& a, const TranslateDictionary& b);
    friend ostream& operator<<(ostream& out, const TranslateDictionary& matr);
    friend istream& operator>> (istream& out, TranslateDictionary& matr);

    TranslateDictionary& operator= (const TranslateDictionary& matr) = default;

    vector<string> translate(const string word) {
        if (!contains(word)) {
            return vector<string>();
        }
        else {
            return dict[word];
        }
    }

    void removeWord(string word) {
        if (contains(word)) {
            dict.erase(word);
        }
    }

    void addTranslation(const string word, const string translation) {
        dict[word].emplace_back(translation);
    }

    void addTranslations(const string word, const vector<string> translations) {
        for (auto translation : translations) {
            dict[word].emplace_back(translation);
        }
    }

    bool contains(string word) const {
        return dict.count(word) == 1;
    }

    int count() const {
        return dict.size();
    }

    ~TranslateDictionary() {
        dict.clear();
    }
};

TranslateDictionary operator+(const TranslateDictionary& a, const TranslateDictionary& b) {
    TranslateDictionary result(a);
    for (auto translations : b.dict) {
        result.addTranslations(translations.first, translations.second);
    }
    return result;
}

ostream& operator<<(ostream& out, const TranslateDictionary& MyDict) {
    for (auto words : MyDict.dict) {
        out << words.first << '\n';
        for (auto translation : words.second) {
            out << translation << ",";
        }
        out << '\n';
    }
    return out;
}

istream& operator>> (istream& in, TranslateDictionary& MyDict) {
    string word, translations;
    while (getline(in, word) && getline(in, translations)) {
        MyDict.dict[word] = split(translations, ',');
    }
    return in;
}

int main()
{

    TranslateDictionary gg;

    cin >> gg;
    cout << gg;

    gg.addTranslation("dog", "собака");
    gg.addTranslation("dog", "кошка");
    //Так и задумано

    gg.translate("dog");

    gg.translate("cat");
    
    return 0;
}