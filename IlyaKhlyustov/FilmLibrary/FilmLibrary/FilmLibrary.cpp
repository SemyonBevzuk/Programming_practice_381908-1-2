#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<queue>

using namespace std;

class Date {
private:
    uint32_t month, year, day;
    
public:
    uint32_t getDay() const {
        return day;
    }

    void setDay(int newDay) {
        day = newDay;
    }

    uint32_t getMonth() const {
        return month;
    }

    void setMonth(int newMonth) {
        month = newMonth;
    }

    uint32_t getYear() const {
        return year;
    }

    void setYear(int newYear) {
        year = newYear;
    }
};

class Film {
private:
    string name, screenWriter, producer, compositor;
    Date date;
    uint64_t fees;

public:
    Date getDate() const {
        return date;
    }

    void setDate(Date newDate) {
        date = newDate;
    }

    uint64_t getFees() const {
        return fees;
    }

    void setFees(uint64_t newFees) {
        fees = newFees;
    }

    string getName() const {
        return name;
    }

    void setName(string newName) {
        name = newName;
    }

    string getCompositor() const {
        return compositor;
    }

    void setCompositor(string newCompositor) {
        compositor = newCompositor;
    }

    string getProducer() const {
        return producer;
    }

    void setProducer(string newProducer) {
        producer = newProducer;
    }

    string getScreenWriter() const {
        return screenWriter;
    }

    void setScreenWriter(string newScreenWriter) {
        screenWriter = newScreenWriter;
    }

    bool operator < (const Film& f) const {
        return getFees() < f.getFees();
    }

    
};
    
class FilmLibrary {
private:
    //Для быстрого поиска    
    unordered_map<string, vector<Film*> > byName;
    unordered_map<string, vector<Film*> > byProducer;
    unordered_map<uint32_t, unordered_map<string, vector<Film*> > > byYearAndName;
    //Храним фильмы по году, когда надо составить топ по всем годам -- будем собирать из всех годов в top-K
    unordered_map<uint32_t, multiset<Film, greater<Film>> > films;
    uint32_t countOfFilms;

public:

    FilmLibrary() {
        countOfFilms = 0;
    }

    FilmLibrary(vector<Film>& startFilms) {
        countOfFilms = 0;
        for (auto film : startFilms) {
            addFilm(film);
        }
    }

    uint32_t getCountOfFilms() const {
        return countOfFilms;
    }

    bool contains(Film& film) {
        return (films[film.getDate().getYear()].count(film) > 0);
    }

    
    void addFilm(Film& film) {
        if (contains(film)) return;
        countOfFilms++;
        
        films[film.getDate().getYear()].insert(film);
        
        byYearAndName[film.getDate().getYear()][film.getName()].emplace_back(film);
        byProducer[film.getProducer()].emplace_back(film);
        byName[film.getName()].emplace_back(film);
    }

    vector<Film> searchByYear(uint32_t year) {
        vector<Film> result;

        if (films.count(year) > 0) {
            for (auto film : films[year]) {
                result.emplace_back(film);
            }
        }

        return result;
    }

    vector<Film> searchByName(string name) {
        vector<Film> result;

        if (byName.count(name) > 0) {
            for (auto film : byName[name]) {
                result.emplace_back(*film);
            }
        }

        return result;
    }

    vector<Film> searchByProducer(string producer) {
        vector<Film> result;

        if (byProducer.count(producer) > 0) {
            for (auto film : byProducer[producer]) {
                result.emplace_back(*film);
            }
        }

        return result;
    }

    vector<Film> searchByYearAndName(int year, string name) {
        vector<Film> result;

        if (byYearAndName.count(year) > 0) {
            if (byYearAndName[year].count(name) > 0) {
                for (auto film : byYearAndName[year][name]) {
                    result.emplace_back(*film);
                }
            }
        }

        return result;
    }
    
    vector<Film> getTopFilmsByYear(int year, uint32_t count) {
        vector<Film> result;
        if (films.count(year) > 0) {
            for (auto film : films[year]) {
                if (count == 0) {
                    break;
                }
                count--;
                result.emplace_back(film);
            }
        }
        return result;
    }

    /*
        Немного об алгоритме:
            Сливаем в один список из разных сетов фильмы по кассовости, как это сделать наиболее быстро, если мы не хотим дублировать данные и имеем уже отсортированные фильмы, но разбитые по грппам?
            Делаем следующее, будем хранить приоритетную очередь(примерно все операции за O(logN), в С++ реализована на бинарной куче, если я правильно помню), из которой мы будем доставать фильмы "по очереди", когда мы достали фильм, добавим в очередь следующий фильм этого года(если такой есть).
            Взятие следующего фильма будет происходить тоже за O(LogN) (в сете инкремент итератора работает за O(logN)(реализация на красно-чёрном дереве)).
        Асимптотика:
            count -- сколько фильмов вытащить
            countYears -- количество годов в фильмотеке на данный момент
            K -- среднее количество фильмов в вышедших каждом году
            O(max(count, countYears) * (log(countYears) + log(K)) + countYears * log(K))
    */
    
    vector<Film> getTopFilms(uint32_t count) {
        priority_queue<Film> filmsQueue;
        unordered_map<int, set<Film>::const_iterator> forYears;
        
        for (auto film : films) {
            forYears[film.first] = film.second.begin();
            filmsQueue.push(*(forYears[film.first]++));
        }

        vector<Film> result;
        for (size_t i = 0; i < count; i++) {
            if (filmsQueue.empty()) break;
            result.emplace_back(filmsQueue.top());
            filmsQueue.pop();
            int year = result.back().getDate().getYear();
            if (forYears[year] != films[year].end()) {
                filmsQueue.push(*(forYears[year]++));
            }
        }

        //returns top-K films if count of films >= K and top-count_of_films otherwise
        return result;
    }
};

int main()
{
    return 0;
}