#ifndef JOURNAL_H
#define JOURNAL_H

#include "transaction.h"
#include <string>
#include <vector>

class Journal {
public:
    static void log_transaction(const std::string& card_num, Transaction tx);
    static std::vector<Transaction> get_history(const std::string& card_num);
};

#endif
