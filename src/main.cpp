#include <iostream>
#include "bank_api.hpp"
#include "atm_controller.hpp"

int main() {
    BankAPI bank;
    bank.addCard("A", "0000", 1000);
    bank.addCard("B", "1234", 5000);
    std::cout << std::endl;

    ATMController atm(bank);
    atm.run();

    return 0;
}