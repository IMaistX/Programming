#include "account.h"

Account::Account() {
    card_number = "";
    balance = 0.0;
    daily_withdrawn = 0.0;
}

Account::Account(std::string num, double bal) {
    card_number = num;
    balance = bal;
    daily_withdrawn = 0.0;
}
