#include "phoneBook.hpp"

int main() {
    std::cout << "WELCOME TO YOUR PHONEBOOK!!" << std::endl;
    PhoneBook c;
    std::string choice;
    do {
        std::cout << std::endl << std::endl << "Choose a valid action (\"ADD\" or \"SEARCH\" or \"EXIT\")" << std::endl;
        std::getline(std::cin, choice);
        if (choice == "ADD") {
            c.add();
        }
        else if (choice == "SEARCH") {
            c.search();
        }
        else if (choice == "EXIT") {
            std::cout << "Okey then, bye bye!" << std::endl;
            exit(0);
        }
        else {
            std::cout << "Wrong input !" << std::endl;
        }
    } while(1);
    return 0;
}