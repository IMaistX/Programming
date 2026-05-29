#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    std::string number;
    std::string pin;
    bool is_blocked;
    int pin_attempts;

    Card();
    Card(std::string num, std::string p);
};

#endif
