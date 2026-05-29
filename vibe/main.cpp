#include <iostream>
#include <cctype>
#include "atm_engine.h"

bool isOnlyDigits(const std::string& str) {
    if (str.empty()) return false;
    for (char const &c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

int main() {
    ATMEngine atm;
    std::string num, pin;

    std::cout << "=== Добро пожаловать в Вайб-Банк ===\n";
    
    while (true) {
        std::cout << "Введите номер карты (только цифры): ";
        std::cin >> num;
        if (isOnlyDigits(num)) {
            break;
        }
        std::cout << "Ошибка! Номер карты должен состоять только из цифр.\n";
    }

    while (true) {
        std::cout << "Введите PIN (только цифры): ";
        std::cin >> pin;
        if (isOnlyDigits(pin)) {
            break;
        }
        std::cout << "Ошибка! PIN должен состоять только из цифр.\n";
    }

    if (!atm.login(num, pin)) {
        return 0;
    }

    int choice;
    while (true) {
        std::cout << "\n1. Проверить баланс\n2. Пополнить\n3. Снять\n4. История (5 операций)\n5. Выйти\nВыбор: ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода! Вводите только цифры.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) atm.check_balance();
        else if (choice == 2) {
            double amt;
            std::cout << "Сумма пополнения: ";
            if (!(std::cin >> amt)) {
                std::cout << "Неверный формат суммы!\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            atm.deposit(amt);
        }
        else if (choice == 3) {
            double amt;
            std::cout << "Сумма снятия: ";
            if (!(std::cin >> amt)) {
                std::cout << "Неверный формат суммы!\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            atm.withdraw(amt);
        }
        else if (choice == 4) atm.show_history();
        else break;
    }

    std::cout << "Удачи!\n";
    return 0;
}
