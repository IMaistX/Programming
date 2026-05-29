#include "atm_engine.h"
#include "file_storage.h"
#include "journal.h"
#include "recovery.h"
#include <iostream>

ATMEngine::ATMEngine() {
    is_auth = false;
}

bool ATMEngine::login(std::string num, std::string pin) {
    if (!FileStorage::load_card(num, current_card)) {
        current_card = Card(num, pin);
        current_acc = Account(num, 5000.0);
        FileStorage::save_card(current_card);
        FileStorage::save_account(current_acc);
    } else {
        FileStorage::load_account(num, current_acc);
    }

    if (current_card.is_blocked) {
        std::cout << "Карта заблокирована!\n";
        return false;
    }

    if (current_card.pin == pin) {
        current_card.pin_attempts = 0;
        FileStorage::save_card(current_card);
        is_auth = true;

        Recovery::fix_after_crash(current_acc);
        FileStorage::save_account(current_acc);

        return true;
    } else {
        current_card.pin_attempts++;
        if (current_card.pin_attempts >= 3) {
            current_card.is_blocked = true;
            std::cout << "Превышено 3 попытки! Карта ЗАБЛОКИРОВАНА.\n";
        } else {
            std::cout << "Неверный PIN! Осталось попыток: " << 3 - current_card.pin_attempts << "\n";
        }
        FileStorage::save_card(current_card);
        return false;
    }
}

void ATMEngine::check_balance() {
    std::cout << "Ваш баланс: " << current_acc.balance << " руб.\n";
}

void ATMEngine::deposit(double amt) {
    if (amt <= 0) {
        std::cout << "Ошибка: Сумма пополнения должна быть больше нуля!\n";
        return;
    }
    amt = ((int)(amt * 100)) / 100.0;
    current_acc.balance += amt;
    FileStorage::save_account(current_acc);
    std::cout << "Успешно пополнено на " << amt << " руб.\n";

    Transaction tx = { DEPOSIT, amt, 0 };
    Journal::log_transaction(current_acc.card_number, tx);
}

void ATMEngine::withdraw(double amt) {
    if (amt <= 0) {
        std::cout << "Ошибка: Сумма снятия должна быть больше нуля!\n";
        return;
    }
    amt = ((int)(amt * 100)) / 100.0;
    if (amt > 10000) {
        std::cout << "Лимит на снятие за раз: 10 000 руб!\n";
        return;
    }
    if (current_acc.daily_withdrawn + amt > 50000) {
        std::cout << "Суточный лимит 50 000 руб превышен!\n";
        return;
    }

    double fee = amt * 0.01;
    if (fee < 30) fee = 30;

    if (current_acc.balance < amt + fee) {
        std::cout << "Недостаточно денег (Сумма + Комиссия " << fee << " руб)!\n";
        return;
    }

    current_acc.balance -= (amt + fee);
    current_acc.daily_withdrawn += amt;
    FileStorage::save_account(current_acc);

    std::cout << "Снято: " << amt << " руб. Комиссия: " << fee << " руб.\n";

    Transaction tx = { WITHDRAW, amt, 0 };
    Journal::log_transaction(current_acc.card_number, tx);
}

void ATMEngine::show_history() {
    std::vector<Transaction> h = Journal::get_history(current_acc.card_number);
    std::cout << "--- Последние операции ---\n";
    for (size_t i = 0; i < h.size(); i++) {
        std::string t = (h[i].type == DEPOSIT) ? "Пополнение" : "Снятие";
        std::cout << t << ": " << h[i].amount << " руб.\n";
    }
}
