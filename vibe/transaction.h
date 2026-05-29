#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

enum TransactionType { CHECK_BALANCE, WITHDRAW, DEPOSIT };

struct Transaction {
    TransactionType type;
    double amount;
    long long timestamp; // время операции в секундах
};

#endif
