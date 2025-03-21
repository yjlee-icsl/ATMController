#include <iostream>
#include <fstream>
#include <string>
#include "bank_api.hpp"
#include "atm_controller.hpp"

int main(int argc, char* argv[]) {
    if (argc == 1 || (std::string(argv[1]) != "use_cli" && std::string(argv[1]) != "from_file")) {
        std::cout << "Invalid arguments. Use 'use_cli' or 'from_file'" << std::endl;
        return 1;
    } else if (std::string(argv[1]) == "from_file" && argc != 3) {
        std::cout << "Invalid arguments. If you want 'from_file', input testcase idx" << std::endl;
        return 1;
    }

    std::string project_root = PROJECT_ROOT_PATH;
    std::string database_path = "/database/card_infos.txt";
    
    BankAPI bank;
    if (!bank.load_database(project_root + database_path)) return 1;

    std::cout << "\nAll card information (just for testing)" << std::endl;
    bank.printAllCardInfo();
    std::cout << std::endl;

    if (argc > 1 && std::string(argv[1]) == "use_cli") {
        std::cout << "Run with CLI" << std::endl;
        ATMController atm(bank);
        atm.run();
    } else {
        std::string testcase_path = "/testcase/testcase_" + std::string(argv[2]) + ".txt";
        std::ifstream testcase_file(project_root + testcase_path);
        if (!testcase_file.is_open()) {
            std::cerr << "Failed to open " << project_root + testcase_path << std::endl;
            return 1;
        }
        std::cout << "Run with TXT file" << std::endl;
        ATMController atm(bank, testcase_file);
        atm.run();
    }

    return 0;
}