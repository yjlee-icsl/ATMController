#include <iostream>
#include "atm_controller.hpp"

ATMController::ATMController(BankAPI& bank, int max_pin_try_num)
: bank_(bank), max_pin_try_num_(max_pin_try_num) {}

void ATMController::run() {
    
    while (true) {
        // check card id is in the bank database
        // if not in the bank database, reject current card
        if (!this->check_validity()) {
            std::cout << "Card " << current_card_id <<" is not in the bank database" << std::endl;
            continue;
        }

        // check pin number
        // if pin number is incorrect, skip this current card (current user)
        if (!verifyPIN()) continue;
        std::cout << "PIN number is verified\n" << std::endl;

        // if card id and pin number is verfied, provide ATM service
        while (true) {
            // get service to provide
            std::string choice;
            std::cout << "What service do you want?" << std::endl;
            std::cout << "1. See balance 2. Deposit 3. Withdraw 0. Exit" << std::endl;
            std::cin >> choice;

            // If input type is invalid (not digit), try again.
            if (!is_non_neg_digit(choice)) {
                std::cout << "Invalid type of input. Please try again\n" << std::endl;
                continue;
            }
            // If 'Exit' is choosed, finish this card
            if (!provideService(std::stoi(choice))) break;
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

        if (try_count < max_pin_try_num_) {
            // if pin number is incorrect, try again
            std::cout << "PIN number is incorrect, try again (" << try_count << "/" << max_pin_try_num_ << ")" << std::endl;
        } else {
            // after final failure
            std::cout << "Too many failed. Please remove your card" << std::endl;
        }
    }
    return pin_verified;
}

bool ATMController::provideService(int choice) {
    std::string amount;

    switch (choice) {
        case 1:
            std::cout << "Your balance is: " << bank_.seeBalance(current_card_id) << "$" << std::endl;
            break;
        case 2:
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            if (!is_non_neg_digit(amount)) {
                std::cout << "Invalid amount. Please try again\n";
                break;
            }
            bank_.deposit(current_card_id, std::stoi(amount));
            std::cout << "Deposit is successfully done (now, " << bank_.seeBalance(current_card_id) << "$)" << std::endl;
            break;
        case 3:
            std::cout << "Enter withdraw amount: ";
            std::cin >> amount;
            if (!is_non_neg_digit(amount)) {
                std::cout << "Invalid amount. Please try again\n";
                break;
            }
            if (bank_.withdraw(current_card_id, std::stoi(amount))) {
                std::cout << "Withdraw is successfully done (now, " << bank_.seeBalance(current_card_id) << "$)" << std::endl;
            } else {
                std::cout << "Your balance is not enough (now, " << bank_.seeBalance(current_card_id) << "$)" << std::endl;
            }
            break;
        case 0:
            std::cout << "Your work is finished\n" << std::endl;
            return false;
        default:
            std::cout << "Invalid type of input. Please try again\n" << std::endl;
            break;
    }
    return true;
}

bool is_non_neg_digit(const std::string& input) {
    // check if the input is integer
    for (auto c : input) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    // check if the input is non negative value
    if (std::stoi(input) >= 0) {
        return true;
    }
    return false;
}