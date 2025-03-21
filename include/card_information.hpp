#pragma once

#include <string>

class CardInfo {
public:
    CardInfo(const std::string pin_number, unsigned long long balance);

    std::string getPIN();

    unsigned long long seeBalance();
    void deposit(unsigned long long amount);
    bool withdraw(unsigned long long amount);

private:
    const std::string pin_number_;
    unsigned long long balance_;
};