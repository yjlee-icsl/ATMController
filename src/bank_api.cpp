#include <iostream>
#include "bank_api.hpp"

BankAPI::BankAPI() {}

void BankAPI::printAllCardInfo() {
    // print all card information in bank database
    for (auto card : card_database) {
        std::cout << "Card " << card.first << " (PIN: "
        << card.second.getPIN() << ", Balance: " << card.second.seeBalance() << ")" << std::endl;
    }
}

bool BankAPI::addCard(const std::string& card_id, const std::string& pin_number, unsigned long long balance) {
    // add card to database
    if (card_database.find(card_id) == card_database.end()) {
        // if card is not in bank database, add the card to bank database
        card_database.emplace(card_id, CardInfo(pin_number, balance));
        std::cout << "Card " << card_id << " is added to bank database" << std::endl;
        return true;
    } else {
        // if card is already exists in bank database, print message and return
        std::cout << "Card " << card_id << " is already exists in bank database" << std::endl;
        return false;
    }
}

bool BankAPI::check_validity(const std::string& card_id) {
    // if card is in bank database return true, else return false
    return (card_database.find(card_id) != card_database.end());
}

bool BankAPI::verifyPIN(const std::string& card_id, const std::string& pin_number) {
    // if pin_number is correct return true, else retur false 
    return (card_database.find(card_id)->second.getPIN() == pin_number);
}

unsigned long long BankAPI::seeBalance(const std::string& card_id) {
    return card_database.find(card_id)->second.seeBalance();
}

void BankAPI::deposit(const std::string& card_id, unsigned long long amount) {
    card_database.find(card_id)->second.deposit(amount);
}

bool BankAPI::withdraw(const std::string& card_id, unsigned long long amount) {
    return card_database.find(card_id)->second.withdraw(amount);
}