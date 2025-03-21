#pragma once

#include <unordered_map>
#include "card_information.hpp"

class BankAPI {
public:
    BankAPI();

    bool load_database(const std::string& database_filename);
    bool addCard(const std::string& card_id, const std::string& pin_number, unsigned long long balance);
    void printAllCardInfo();

    bool check_validity(const std::string& card_id); 
    bool verifyPIN(const std::string& card_id, const std::string& pin_number);

    unsigned long long seeBalance(const std::string& card_id);
    void deposit(const std::string& card_id, unsigned long long amount);
    bool withdraw(const std::string& card_id, unsigned long long amount);

private:
    std::unordered_map<std::string, CardInfo> card_database;

};