#include <iostream>
#include "bank_api.hpp"

BankAPI::BankAPI() {}

bool BankAPI::addCard(const std::string& card_id, const std::string& pin_number, int balance) {
    if (card_database.find(card_id) == card_database.end()) {
        card_database.emplace(card_id, CardInfo(pin_number, balance));
        std::cout << "Card " << card_id << " is added to bank database" << std::endl;
        return true;
    } else {
        std::cout << "Card " << card_id << " is already exists in bank database" << std::endl;
        return false;
    }
}

bool BankAPI::check_validity(const std::string& card_id) {
    return (card_database.find(card_id) != card_database.end());
}

bool BankAPI::verifyPIN(const std::string& card_id, const std::string& pin_number) {
    return (card_database.find(card_id)->second.getPIN() == pin_number);
}

int BankAPI::seeBalance(const std::string& card_id) {
    return card_database.find(card_id)->second.seeBalance();
}

void BankAPI::deposit(const std::string& card_id, int amount) {
    card_database.find(card_id)->second.deposit(amount);
}

bool BankAPI::withdraw(const std::string& card_id, int amount) {
    return card_database.find(card_id)->second.withdraw(amount);
}