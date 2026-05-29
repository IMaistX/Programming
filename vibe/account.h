#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    std::string card_number;
    double balance;
    double daily_withdrawn;

    Account();
    Account(std::string num, double bal);
};

#endif
