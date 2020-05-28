#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class CreditInfo
{
    private:
        long long funds;
        int length;
        float rate;
        long long monthPay;
        long long creditBalance;

    public:
        CreditInfo(long long _funds, int _length, float _rate);

    friend class Credit;
};

class Account
{
    private:
        long long funds;
        std::vector<CreditInfo> credits;
        std::string password;
    public:
        int id;
        std::string name;

        Account(int _id = 0, std::string _name = "", long long _funds = 0, std::vector<CreditInfo> _credits = {}, std::string _password = "000");

    friend class Credit;
    friend class ProcCenter;
};

class Credit
{
    private:
        Account& acc = * new Account;
    public:
        Credit(Account& _acc);

        bool checkAvailability(long long _funds, int length, int rate);
        void takeCredit(long long funds, int length, int rate);
        std::vector<CreditInfo> getCredits();
        bool prepay(size_t index);
        bool pay(size_t index, long long amount);
};

class ProcCenter
{
    private:
        std::vector<Account> accounts;
    public:
        ProcCenter(std::vector<Account> _accounts);
        Credit auth(int _id, std::string pass);
        Account& operator[](size_t index);
};  