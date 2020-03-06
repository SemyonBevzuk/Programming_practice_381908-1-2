//
// Created by Leo on 05.03.2020.
//

#ifndef TASK1_WORD_H
#define TASK1_WORD_H

#include <vector>
#include <string>

class word {
public:
    explicit word(std::string key);
    word(std::string key, const std::string& value);
    word(std::string key, const std::vector<std::string>& value);

    word& operator=(const word& other);

    bool add(const std::string& value);
    bool add(const std::vector<std::string>& value);

    bool del(const std::string& value);
    bool del(const std::vector<std::string>& value);

    bool change(const std::string& old_value, const std::string& new_value);

    static bool check(const std::string& word);
    static bool check(const std::vector<std::string>& word);

    void clear();
    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream& os, const word& other);
    friend std::istream& operator>>(std::istream& os, word& other);
private:
    std::string key;
    std::vector<std::string> value;
};


#endif //TASK1_WORD_H
