#include<iostream>
#include<string>

using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time();//по умолчанию
	Time(const Time& _d);//копироdание
	Time(int _hour, int _min, int _sec);//установление
	Time(string s);//преобразование
	~Time();//дестркутор
	void setHour(int _hour);
	void setMin(int _min);
	void setSec(int _sec);
	void setTime(int _hour, int _min, int _sec);
	int getHour() { return hour; }
	int getMin() { return min; }
	int getSec() { return sec; }
	Time getTime();
	Time addHour(int _hour);
	Time addMin(int _min);
	Time addSec(int _sec);
	//ime operator-(const Time& _d);//разность c одноклассником
	//Time operator-(string s); // разность со строкой
	Time& operator=(const Time& _d); //присваивание
	Time operator+(const Time& _d);//сумма с одноклассником
	Time operator+(string s);// сумма со строкой
	Time operator*(const Time& _d); // произведение
	Time operator* (string s);
	bool operator==(const Time& _d);
	friend ostream& operator<<(ostream& stream, const Time& _d);
	friend istream& operator>>(istream& stream, Time& _d);
	void inPut();
	void outPut();
};