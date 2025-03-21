#pragma once

#include <string>
#include "bank_api.hpp"

class ATMController {
public:
    ATMController(BankAPI& bank, std::istream& istream_type=std::cin, int max_pin_try_num=3);

    void run();

private:
    BankAPI bank_;
    std::istream& istream_type_;

    int max_pin_try_num_;
    std::string current_card_id;

    bool check_validity();
    bool verifyPIN();
    bool provideService(int choice);
};

bool is_non_neg_digit(const std::string& input);