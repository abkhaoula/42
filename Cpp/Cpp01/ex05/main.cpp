# include "Harl.hpp"
#include <iostream>

int main() {
    Harl h;

    std::cout << "DEBUG" << std::endl;
    h.complain("DEBUG");
    std::cout << "INFO" << std::endl;
    h.complain("INFO");
    std::cout << "WARNING" << std::endl;
    h.complain("WARNING");
    std::cout << "ERROR" << std::endl;
    h.complain("ERROR");
}