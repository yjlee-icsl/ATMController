#include <iostream>
#include "atm_controller.hpp"

ATMController::ATMController(BankAPI& bank, int max_pin_try_num)
: bank_(bank), max_pin_try_num_(max_pin_try_num) {}

void ATMController::run() {
    
    while (true) {
        // check card id is in bank database
        if (!this->check_validity()) {
            std::cout << "Error: your card is not in bank database" << std::endl;
            continue;
        }

        // check pin number is correct. If incorrect pin number, skip to next user
        if (!verifyPIN()) continue;
        std::cout << "PIN number is verified\n" << std::endl;

        while (true) {
            int choice;
            std::cout << "What service do you want?" << std::endl;
            std::cout << "1. See balance 2. Deposit 3. Withdraw 0. Exit" << std::endl;
            std::cout << "Type: ";
            std::cin >> choice;
            if (!provideService(choice)) break;
            std::cout << std::endl;
        }
    }
}

bool ATMController::check_validity() {
    std::cout << "Insert your card (now, just type your card ID): ";
    std::cin >> current_card_id;
    return bank_.check_validity(current_card_id);
}

bool ATMController::verifyPIN() {
    bool pin_verified = false;
    std::string pin_number;

    for (int try_count = 1; try_count < max_pin_try_num_+1; try_count++) {
        std::cout << "Please enter the PIN number: ";
        std::cin >> pin_number;
        if (bank_.verifyPIN(current_card_id,  pin_number)) {
            pin_verified = true;
            break;
        }

        // if pin number is incorrect, print message
        if (try_count < max_pin_try_num_) {
            std::cout << "PIN number is incorrect, try again (" << try_count << "/" << max_pin_try_num_ << ")" << std::endl;
        } else {
            std::cout << "Remove your card" << std::endl;
        }
    }
    return pin_verified;
}

bool ATMController::provideService(int choice) {
    int amount;

    switch (choice) {
        case 1:
            std::cout << "Your balance is: " << bank_.seeBalance(current_card_id) << "$" << std::endl;
            break;
        case 2:
            std::cout << "Amout of deposit: ";
            std::cin >> amount;
            bank_.deposit(current_card_id, amount);
            std::cout << "Deposit is successfully done (" << bank_.seeBalance(current_card_id) << ")" << std::endl;
            break;
        case 3:
            std::cout << "Amout of withdraw: ";
            std::cin >> amount;
            if (bank_.withdraw(current_card_id, amount)) {
                std::cout << "Withdraw is successfully done (" << bank_.seeBalance(current_card_id) << ")" << std::endl;
            } else {
                std::cout << "Your balance is not enough (" << bank_.seeBalance(current_card_id) << ")" << std::endl;
            }
            break;
        case 0:
            std::cout << "Your work is finished\n" << std::endl;
            return false;
        default:
            std::cout << "You choose wrong, please try again\n";
            break;
    }
    return true;
}