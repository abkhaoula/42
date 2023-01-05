/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:06:07 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/05 12:06:08 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int main() {
    std::cout << "WELCOME TO YOUR PHONEBOOK!!" << std::endl;
    PhoneBook c;
    std::string choice;
    do {
        std::cout << std::endl << std::endl << "Choose a valid action (\"ADD\" or \"SEARCH\" or \"EXIT\")" << std::endl;
        if (!std::getline(std::cin, choice))
        {
            std::cout << "Wrong input !" << std::endl;
            exit (0);
        }
        if (choice == "ADD") {
            c.add();
        }
        else if (choice == "SEARCH") {
            c.search();
        }
        else if (choice == "EXIT") {
            c.exiting();
        }
        else {
            std::cout << "Wrong input !" << std::endl;
        }
    } while(1);
    return 0;
}