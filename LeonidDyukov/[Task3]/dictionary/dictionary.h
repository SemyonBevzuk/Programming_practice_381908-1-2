//
// Created by Leo on 05.03.2020.
//

#ifndef TASK1_DICTIONARY_H
#define TASK1_DICTIONARY_H

#include "word.h"

class dictionary {
public:
    explicit dictionary(const std::vector<word *> * = nullptr);
    explicit dictionary(const std::string& filename);
    dictionary(dictionary const &);

    bool add(word *);
    bool rem(word *);

    bool forceAdd(word *);
    bool forceRem(word *);

    dictionary operator+(const dictionary&) const;
    dictionary operator-(const dictionary&) const;
    dictionary operator+=(const dictionary&);
    dictionary operator-=(const dictionary&);
    dictionary& operator=(const dictionary&);

    bool operator==(const dictionary&) const;
    bool operator!=(const dictionary&) const;

    word * find(const std::string& word) const;
    word * find(const word& word) const;

    size_t size() const;
    std::vector<word *> get() const;

    void in(const std::string&);
    void out(const std::string&) const;

    std::string to_string() const;

    friend std::istream& operator>>(std::istream&, dictionary&);
    friend std::ostream& operator<<(std::ostream&, const dictionary&);
private:
    std::vector<word *> values;
};

static std::vector<std::string> explode(const std::string&, char);

#endif //TASK1_DICTIONARY_H
