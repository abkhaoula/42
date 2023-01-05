# include "Harl.hpp"
# include <iostream>
# include <string>

int main(int argc, char* argv[]) {
    Harl h;
    

    if (argc != 2)
    {
        std::cout << "Expected 1 argument (level). Received " <<  (argc - 1) << " arguments!" << std::endl;
		return (0);
    }
    std::string levels(argv[1]);
    int level;
    if (levels == "DEBUG") level = 1;
    if (levels == "INFO") level = 2;
    if (levels == "WARNING") level = 3;
    if (levels == "ERROR") level = 4;

    switch (level) {
        case 1:
            std::cout << "[ DEBUG ]" << std::endl;
            h.complain("DEBUG");
            std::cout << "[ INFO ]" << std::endl;
            h.complain("INFO");
            std::cout << "[ WARNING ]" << std::endl;
            h.complain("WARNING");
            std::cout << "[ ERROR ]" << std::endl;
            h.complain("ERROR");
            break;
        case 2:
            std::cout << "[ INFO ]" << std::endl;
            h.complain("INFO");
            std::cout << "[ WARNING ]" << std::endl;
            h.complain("WARNING");
            std::cout << "[ ERROR ]" << std::endl;
            h.complain("ERROR");
            break;
        case 3:
            std::cout << "[ WARNING ]" << std::endl;
            h.complain("WARNING");
            std::cout << "[ ERROR ]" << std::endl;
            h.complain("ERROR");
            break;
        case 4:
            std::cout << "[ ERROR ]" << std::endl;
            h.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;

    }
}