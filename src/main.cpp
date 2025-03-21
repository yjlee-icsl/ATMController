#include <iostream>
#include <unistd.h>
#include <filesystem>
#include <string>
#include "bank_api.hpp"
#include "atm_controller.hpp"

int main() {          
    std::string project_root = PROJECT_ROOT_PATH;
    std::string database_path = "/database/card_infos.txt";

    BankAPI bank;
    if (!bank.load_database(project_root + database_path)) return 1;

    std::cout << "\nAll card information (just for testing)" << std::endl;
    bank.printAllCardInfo();
    std::cout << std::endl;

    ATMController atm(bank);
    atm.run();

    return 0;
}