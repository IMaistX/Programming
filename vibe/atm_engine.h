#ifndef ATM_ENGINE_H
#define ATM_ENGINE_H

#include "card.h"
#include "account.h"

class ATMEngine {
public:
    Card current_card;
    Account current_acc;
    bool is_auth;

    ATMEngine();
    bool login(std::string num, std::string pin);
    void check_balance();
    void deposit(double amt);
    void withdraw(double amt);
    void show_history();
};

#endif
