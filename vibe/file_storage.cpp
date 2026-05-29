#include "file_storage.h"
#include <fstream>

bool FileStorage::load_card(const std::string& num, Card& card) {
    std::ifstream f(num + "_card.txt");
    if (!f.is_open()) return false;
    f >> card.number >> card.pin >> card.is_blocked >> card.pin_attempts;
    f.close();
    return true;
}

void FileStorage::save_card(const Card& card) {
    std::ofstream f(card.number + "_card.txt");
    if (f.is_open()) {
        f << card.number << " " << card.pin << " " << card.is_blocked << " " << card.pin_attempts;
        f.close();
    }
}

bool FileStorage::load_account(const std::string& num, Account& acc) {
    std::ifstream f(num + "_acc.txt");
    if (!f.is_open()) return false;
    f >> acc.card_number >> acc.balance >> acc.daily_withdrawn;
    f.close();
    return true;
}

void FileStorage::save_account(const Account& acc) {
    std::ofstream f(acc.card_number + "_acc.txt");
    if (f.is_open()) {
        f << acc.card_number << " " << acc.balance << " " << acc.daily_withdrawn;
        f.close();
    }
}
