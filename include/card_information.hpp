#pragma once

#include <string>

class CardInfo {
public:
    CardInfo(const std::string pin_number, int balance);

    std::string getPIN();

    int seeBalance();
    void deposit(int amount);
    bool withdraw(int amount);

private:
    const std::string pin_number_;
    int balance_;
};