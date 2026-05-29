#include "journal.h"
#include <fstream>
#include <time.h>

void Journal::log_transaction(const std::string& card_num, Transaction tx) {
    tx.timestamp = time(NULL);
    std::ofstream f(card_num + "_journal.bin", std::ios::binary | std::ios::app);
    if (f.is_open()) {
        f.write((char*)&tx, sizeof(Transaction));
        f.close();
    }
}

std::vector<Transaction> Journal::get_history(const std::string& card_num) {
    std::vector<Transaction> history;
    std::ifstream f(card_num + "_journal.bin", std::ios::binary);
    if (!f.is_open()) return history;

    Transaction tx;
    while (f.read((char*)&tx, sizeof(Transaction))) {
        history.push_back(tx);
    }
    f.close();

    if (history.size() > 5) {
        history.erase(history.begin(), history.end() - 5);
    }
    return history;
}
