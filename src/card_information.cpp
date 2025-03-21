#include "card_information.hpp"

CardInfo::CardInfo(const std::string pin_number, int balance)
: pin_number_(pin_number), balance_(balance) {}

std::string CardInfo::getPIN() {
    return pin_number_;
}

int CardInfo::seeBalance() {
    return balance_;
}

void CardInfo::deposit(int amount) {
    balance_ = balance_ + amount;
}

bool CardInfo::withdraw(int amount) {
    if (amount <= balance_) {
        balance_ = balance_ - amount;
        return true;
    } else {
        return false;
    }
}