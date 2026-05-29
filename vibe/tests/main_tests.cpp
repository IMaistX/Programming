#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdio>
#include "../atm_engine.h"
#include "../file_storage.h"

void clean_test_files(const std::string& num) {
    std::remove((num + "_card.txt").c_str());
    std::remove((num + "_acc.txt").c_str());
    std::remove((num + "_journal.bin").c_str());
}

void test_initial_login_and_limits() {
    std::string test_card = "9999";
    clean_test_files(test_card);

    ATMEngine atm;
    
    assert(atm.login(test_card, "1111") == true);
    assert(atm.current_acc.balance == 5000.0);

    atm.withdraw(20000);
    assert(atm.current_acc.balance == 5000.0);

    atm.withdraw(1000);
    assert(atm.current_acc.balance == 3970.0);

    atm.deposit(500);
    assert(atm.current_acc.balance == 4470.0);

    clean_test_files(test_card);
    std::cout << "Test 1 (Login and limits) passed!\n";
}

void test_pin_blocking() {
    std::string test_card = "8888";
    clean_test_files(test_card);

    ATMEngine atm;
    assert(atm.login(test_card, "1111") == true);

    ATMEngine atm2;
    assert(atm2.login(test_card, "2222") == false);
    assert(atm2.login(test_card, "3333") == false);
    assert(atm2.login(test_card, "4444") == false);
    assert(atm2.login(test_card, "1111") == false);

    clean_test_files(test_card);
    std::cout << "Test 2 (PIN blocking) passed!\n";
}

int main() {
    std::cout << "=== Running ATM Tests ===\n";
    test_initial_login_and_limits();
    test_pin_blocking();
    std::cout << "All tests completed successfully!\n";
    return 0;
}
