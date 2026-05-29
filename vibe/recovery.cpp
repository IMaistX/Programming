#include "recovery.h"
#include "transaction.h"
#include <fstream>

void Recovery::fix_after_crash(Account& acc) {
    std::ifstream f(acc.card_number + "_journal.bin", std::ios::binary);
    if (!f.is_open()) return;

    double restored_balance = 5000.0; 
    Transaction tx;

    while (f.read((char*)&tx, sizeof(Transaction))) {
        if (tx.type == DEPOSIT) {
            restored_balance += tx.amount;
        }
        if (tx.type == WITHDRAW) {
            double fee = tx.amount * 0.01;
            if (fee < 30.0) fee = 30.0;
            
            restored_balance -= (tx.amount + fee);
        }
    }
    f.close();

    acc.balance = restored_balance;
}
