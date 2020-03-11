//
// Created by Leo on 05.03.2020.
//

#include <fstream>
#include <sstream>
#include <regex>
#include <codecvt>
#include "dictionary.h"

dictionary::dictionary(const std::vector<word *> * other) {
    if (other == nullptr) {
        this->values = std::vector<word *>();
    } else {
        this->values = std::vector<word *>(other->size());
        std::move(other->begin(), other->end(), this->values.begin());
    }
}

dictionary::dictionary(const dictionary &) = default;

dictionary::dictionary(const std::string& filename) {
    this->in(filename);
}

void dictionary::in(const std::string& filename) {
    std::fstream file;
    file.open(filename, std::ostream::in);
    if (file.is_open()) {
        file >> *this;
    } else {
        throw std::invalid_argument("Can not open file: " + filename);
    }
}

void dictionary::out(const std::string& filename) const {
    std::fstream file;
    file.open(filename, std::fstream::out);
    if (file.is_open()) {
        file << *this;
    } else {
        throw std::invalid_argument("Can not open file: " + filename);
    }
}

std::string dictionary::to_string() const {
    std::stringstream out;
    out << this->size() << std::endl;
    for (const auto word: this->values) {
        out << word->to_string();
    }
    return out.str();
}

std::istream& operator>>(std::istream& is, dictionary& words) {
    words = dictionary();

    size_t size = 0;
    is >> size;
    std::string line;
    getline(is, line);

    while (getline(is, line)) {
        auto arr = explode(line, ':');
        auto w1 = new word(
                arr[0],
                std::vector<std::string>(
                        arr.begin() + 1,
                        arr.end()
                        ));
        words.add(w1);
    }
    return is;
}


std::ostream &operator<<(std::ostream &os, const dictionary& words) {
    os << words.to_string();
    return os;
}


size_t dictionary::size() const {
    return this->values.size();
}

std::vector<word *> dictionary::get() const {
    std::vector<word *> val;
    std::copy(this->values.begin(), this->values.end(), val.begin());
    return val;
}

bool dictionary::add(word * word) {
    if (find(word->getKey()) == nullptr) {
        this->values.push_back(word);
        return true;
    } else {
        return false;
    }
}

bool dictionary::rem(word * word) {
    if (this->find(word->getKey())) {
        this->values.erase(
                std::remove(
                        this->values.begin(),
                        this->values.end(),
                        word),
                this->values.end());
        return true;
    } else {
        return false;
    }
}

word *dictionary::find(const std::string& word) const {
    for (const auto v: this->values) {
        if (v->getKey() == word)
            return v;
    }
    return nullptr;
}

word *dictionary::find(const word& word) const {
    for (const auto v: this->values)
        if (v == &word)
            return v;
    return nullptr;
}

bool dictionary::operator==(const dictionary &other) const {
    if (this->size() == other.size()) {
        for (const auto word: other.values)
            if (!this->find(word->getKey()))
                return false;
        return true;
    } else {
        return false;
    }
}

bool dictionary::operator!=(const dictionary &other) const {
    return !this->operator==(other);
}

dictionary& dictionary::operator=(const dictionary& dict) {
    if (this->operator==(dict))
        return *this;
    std::copy(dict.values.begin(), dict.values.end(), this->values.begin());
    return *this;
}

dictionary dictionary::operator+=(const dictionary& other) {
    for (const auto word: other.values)
        this->add(word);
    return *this;
}

dictionary dictionary::operator+(const dictionary& other) const {
    auto a = *this;
    return a.operator+=(other);
}

dictionary dictionary::operator-=(const dictionary &other) {
    for (const auto word: other.values)
        this->rem(word);
    return *this;
}

dictionary dictionary::operator-(const dictionary &other) const {
    auto a = *this;
    return a.operator-=(other);
}

std::vector<std::string> explode(const std::string& string, char det) {
    size_t start = 0;
    size_t end = 0;
    std::vector<std::string> result;

    while ((end = string.find(det, start)) != std::string::npos) {
        if (start < end)
            result.push_back(string.substr(start, end - start));
        start = end + 1;
    }
    end = string.find(';');
    if (start < end)
        result.push_back(string.substr(start, end - start));
    return result;
}


