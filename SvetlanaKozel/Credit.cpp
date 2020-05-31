#include "Credit.h"

CreditInfo::CreditInfo(long long _funds, int _length, float _rate)
{
    funds = _funds;
    length = _length;
    rate = _rate;
    monthPay = _funds * (rate / 1200 + (rate / 1200) / (pow(1 + (rate / 1200), length / 12) - 1));

    creditBalance = monthPay * length * 12;
}

Account::Account(int _id = 0, std::string _name = "", long long _funds = 0, std::vector<CreditInfo> _credits = {}, std::string _password = "000")
{
    id = _id;
    funds = _funds;
    credits = _credits;
    password = _password;
}

Credit::Credit(Account& _acc)
{
    acc = _acc;
}
bool Credit::checkAvailability(long long _funds, int length, int rate)
{
    if ((length != 1 && length != 2 && length != 3 && length != 5 && length != 15) || _funds > 3000000) return false;
    long monthPay = _funds * (rate / 1200 + (rate / 1200) / (pow(1 + (rate / 1200), length / 12) - 1));
    return (6 * monthPay > acc.funds);
}
void Credit::takeCredit(long long funds, int length, int rate)
{
    if (!checkAvailability(funds, length, rate)) return;

    acc.funds += funds;

    acc.credits.push_back(CreditInfo(funds, length, rate));
}
std::vector<CreditInfo> Credit::getCredits()
{
    return acc.credits;
}
bool Credit::prepay(size_t index)
{
    CreditInfo creditInfo = acc.credits[index];
    if (creditInfo.creditBalance > acc.funds) return false;
    acc.funds -= creditInfo.creditBalance;

    acc.credits.erase(acc.credits.begin() + index);

    return true;
}
bool Credit::pay(size_t index, long long amount)
{
    CreditInfo creditInfo = acc.credits[index];
    if (amount > acc.funds) return false;
    if (amount >= creditInfo.creditBalance) return prepay(index);

    acc.funds -= amount;
    creditInfo.creditBalance -= amount;

    return true;
}

ProcCenter::ProcCenter(std::vector<Account> _accounts)
{
    accounts = _accounts;
}
Credit ProcCenter::auth(int _id, std::string pass)
{
    for (auto acc : accounts)
    {
        if (acc.id == _id)
        {
            if (acc.password == pass) return Credit(acc);
        }
    }
}
Account& ProcCenter::operator[](size_t index)
{
    return accounts[index];
}