//
// Created by Leo on 05.03.2020.
//

#include <utility>
#include <algorithm>
#include <sstream>
#include <regex>
#include "word.h"

word::word(std::string key) {
    if (!check(key)) throw std::invalid_argument("Invalid symbol in: " + key);
    this->key = std::move(key);
    this->value = std::vector<std::string>(0);
}

word::word(std::string key, const std::string& new_value) {
    if (!check(key)) throw std::invalid_argument("Invalid symbol in: " + key);
    this->key = std::move(key);
    if (!check(new_value)) {
        this->value = std::vector<std::string>(1, new_value);
    } else {
        this->value = std::vector<std::string>(0);
    }
}

word::word(std::string key, const std::vector<std::string>& new_value) {
    if (!check(key)) throw std::invalid_argument("Invalid symbol in: " + key);
    this->key = std::move(key);
    if (!check(new_value)) {
        this->value = new_value;
    } else {
        this->value = std::vector<std::string>(0);
    }}

word &word::operator=(const word &other) = default;

bool word::add(const std::string& new_value) {
    if(std::find(this->value.begin(), this->value.end(), new_value) != this->value.end() || !check(new_value)) {
        return false;
    } else {
        this->value.push_back(new_value);
        return true;
    }
}

bool word::add(const std::vector<std::string>& new_value) {
    bool result = true;
    for (const std::string& str: new_value) {
        result &= this->add(str);
    }
    return result; //TODO: Return value, if not all added
}

bool word::del(const std::string& new_value) {
    if(std::find(this->value.begin(), this->value.end(), new_value) != this->value.end()) {
        this->value.erase(
                std::remove(this->value.begin(), this->value.end(), new_value),
                this->value.end());
        return true;
    } else {
        return false;
    }
}

bool word::del(const std::vector<std::string>& new_value) {
    bool result = true;
    for (const std::string& str: new_value) {
        result &= this->del(str);
    }
    return result; //TODO: Return value, if not all deleted
}

bool word::change(const std::string& old_value, const std::string& new_value) {
    if(std::find(this->value.begin(), this->value.end(), new_value) != this->value.end() || !check(new_value)) {
        std::replace(this->value.begin(), this->value.end(), old_value, new_value);
        return true;
    } else {
        return false;
    }}

void word::clear() {
    this->value.clear();
}

std::string word::to_string() const {
    std::stringstream out;
    out << this->key << ":";
    if (!this->value.empty()) {
        auto start = this->value.begin();
        out << *start++;
        while (start < this->value.end()) {
            out << "," << *start++;
        }
    }
    out << std::endl;
    return out.str();
}

std::ostream &operator<<(std::ostream &os, const word &other) {
    os << other.to_string();
    return os;
}

bool word::check(const std::string& word) {
    std::regex filter(R"(^[a-zA-Zа-яА-Я]+$)");
    return std::regex_search(word, filter);
}

bool word::check(const std::vector<std::string>& words) {
    bool result = true;
    for (const std::string& word: words) {
        result &= check(word);
    }
    return result;
}

std::istream &operator<<(std::istream &is, word &other) {
    std::string key;
    std::string val;
    is >> key;
    while (!other.check(key)) {
        is >> key;
    }

    is >> val;
    while (!other.check(val)) {
        is >> val;
    }
    other = word(key, val);
    return is;
}
