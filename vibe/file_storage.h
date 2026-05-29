#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H

#include "card.h"
#include "account.h"

class FileStorage {
public:
    static bool load_card(const std::string& num, Card& card);
    static void save_card(const Card& card);
    static bool load_account(const std::string& num, Account& acc);
    static void save_account(const Account& acc);
};

#endif
