#include "card.h"

Card::Card() {
    number = "";
    pin = "";
    is_blocked = false;
    pin_attempts = 0;
}

Card::Card(std::string num, std::string p) {
    number = num;
    pin = p;
    is_blocked = false;
    pin_attempts = 0;
}
