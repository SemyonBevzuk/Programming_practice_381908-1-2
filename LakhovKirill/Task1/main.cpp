#include <iostream>
#include <string>
class Time{
public:
    Time(){
        this->setHour(0);
        this->setMin(0);
        this->setSec(0);
    };

    void setHour(int _h){
        this->hours=_h;
    }
    void setMin(int _m){this->min=_m;}
    void setSec(int _s){this->sec=_s;}
    int getHour(){return this->hours;}
    int getMin(){return this->min;}
    int getSec(){return this->sec;}
private:
    int hours;
    int min;
    int sec;
    std::string sHours;
    std::string sMin;
    std::string sSec;
};
int main() {
    std::string name = "Kirill";
    std::cout << name << std::endl;
    return 0;
}
