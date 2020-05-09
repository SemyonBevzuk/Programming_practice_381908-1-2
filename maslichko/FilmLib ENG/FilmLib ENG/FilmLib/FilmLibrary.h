#ifndef FILM_DATA
#define FILM_DATA

#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class FilmLibrary
{
protected:
    vector<string> title_vector;
    vector<string> producer_vector;
    vector<string> screenwriter_vector;
    vector<string> composer_vector;
    vector<string> data_vector;
    vector<long long> fees_vector;
public:
    FilmLibrary()
    {
    }
};

#endif