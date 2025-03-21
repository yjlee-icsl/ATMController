#include "card_information.hpp"

CardInfo::CardInfo(const std::string pin_number, unsigned long long balance)
: pin_number_(pin_number), balance_(balance) {}

std::string CardInfo::getPIN() {
    return pin_number_;
}

unsigned long long CardInfo::seeBalance() {
    return balance_;
}

void CardInfo::deposit(unsigned long long amount) {
    // add deposit amount to balance
    balance_ = balance_ + amount;
}

bool CardInfo::withdraw(unsigned long long amount) {
    if (amount <= balance_) {
        // if balance is same with or large than withdraw amount
        // reduece balance by the withdraw amount
        balance_ = balance_ - amount;
        return true;
    } else {
        // if balance is smaller than withdraw amount, return false
        return false;
    }
}