#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

class Cinema
{
private:
    struct Date
    {
        int day;
        int month;
        int year; 
    };
    struct Time
    {
        int hour;
        int min;  
    };
    string VIP;
    string STANDART;
    vector<int**> CinemaHalls;
    vector <pair  <string,  pair  <vector  <Time>, vector<int**>>>> CinemaSeassions;
    vector <pair  <Date,    vector <pair  <string, pair  <vector  <Time>, vector<int**>>>>>> ThirtyDays;
    int start_hour;
    int start_min;
    int number_of_films;
    int number_rows;
    int number_seats;
    int number_of_seans;
    vector <pair<string, pair <int, int>>> name_of_films_and_time;
    double* film_price;
public:
    Cinema();
    ~Cinema();

    void CCinema(const string fileName);
    void CreateCinema(int y, int m, int d);
    Date CreateDate(int y, int m, int d, int plus);
    vector<Time> CreateTime(int starthour, int startmin, int durationhour, int durationmin, int kol);
    int GetDay(Date a);
    int GetMonth(Date a);
    int GetYear(Date a);
    bool ChSeans(string film, int h, int m);
    vector<pair<int, int>> RSeats(int y, int m, int d, string film, int h, int min, string zone, int kol);
    bool ChSeats(int y, int m, int d, string film, int h, int min, string zone, int kol);
    bool DelSeats(int y, int m, int d, string film, int h, int min, int index1, int index2);
    double* GetFilmsPrice();
    int GetStandartPrice(string film, double* price);
    int GetVipPrice(string film, double* price);
    string GetVIP();
    string GetSTANDART();
    int GetHall(string film);

    friend istream& operator>> (istream& stream, Cinema& c);
    friend ostream& operator<< (ostream& stream, const Cinema& c);//Overload operator input into the stream

   
};