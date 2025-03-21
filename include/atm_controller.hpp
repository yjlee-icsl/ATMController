#pragma once

#include <string>
#include "bank_api.hpp"

class ATMController {
public:
    ATMController(BankAPI& bank, int max_pin_try_num=3);

    void run();

private:
    BankAPI bank_;

    int max_pin_try_num_;
    std::string current_card_id;

    bool check_validity();
    bool verifyPIN();
    bool provideService(int choice);
};

bool is_digit(const std::string& input);