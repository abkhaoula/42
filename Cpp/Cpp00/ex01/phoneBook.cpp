/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:06:13 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 13:52:54 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "phoneBook.hpp"

Contact::Contact() {
    _firstName = "";
    _lastName = "";
    _nickname = "";
    _phoneNumber = "";
    _darkestSecret = "";
}
Contact::~Contact() {}
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) : _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret){} 
void Contact::print(int i) {
    std::string display_firstName;
    std::string display_lastName;
    std::string display_nickname;
    if (_firstName.empty())
        return;
    std::string index;
    std::stringstream ss;
    ss << i;
    index = ss.str();
    if (index.length() > 10) {
        index.resize(10);
        index[9] = '.';
    }
    display_firstName = _firstName;
    if (display_firstName.length() > 10) {
        display_firstName.resize(10);
        display_firstName[9] = '.';
    }
    display_lastName = _lastName;
    if (display_lastName.length() > 10) {
        display_lastName.resize(10);
        display_lastName[9] = '.';
    }
    display_nickname = _nickname;
    if (display_nickname.length() > 10) {
        display_nickname.resize(10);
        display_nickname[9] = '.';
    }
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << std::right << index;
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << std::right << display_firstName;
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << std::right << display_lastName;
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << std::right << display_nickname;
    std::cout << "|";
    std::cout << std::endl;
}
void Contact::longprint() {
    if (_firstName.empty())
    {
        std::cout << "Index Out of range ";
        return;    
    }
            
            
    std::cout << "First Name    : " << _firstName << std::endl;
    std::cout << "Last Name     : " << _lastName << std::endl;
    std::cout << "Nickname      : " << _nickname << std::endl;
    std::cout << "Phone Number  : " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}






PhoneBook::PhoneBook() {
    _new = 0;
    _last = 0;
}
PhoneBook::~PhoneBook() {}
void PhoneBook::add() {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;


    do {
        std::cout << "First Name : ";
        if (!std::getline(std::cin, firstName))
        {
            std::cout << "Wrong input !" << std::endl;
            exit (0);
        }
    } while(firstName.empty());
    do {
        std::cout << "Last Name : ";
        if (!std::getline(std::cin, lastName))
        {
            std::cout << "Wrong input !" << std::endl;
            exit (0);
        }
    } while(lastName.empty());
    do {
        std::cout << "Nickname : ";
        if (!std::getline(std::cin, nickname))
        {
            std::cout << "Wrong input !" << std::endl;
            exit (0);
        }
    } while(nickname.empty());
    do {
        std::cout << "Phone Number : ";
        if (!std::getline(std::cin, phoneNumber))
        {
            std::cout << "Wrong input !" << std::endl;
            exit (0);
        }
    } while(phoneNumber.empty());
    do {
        std::cout << "Darkest Secret : ";
        if (!std::getline(std::cin, darkestSecret))
        {
            std::cout << "Wrong input !" << std::endl;
            exit (0);
        }
    } while(darkestSecret.empty());

    if (_new == 8)
    {
        _new = 0;
        _last -= 1;
        delete _contacts[_new];
    }
    _contacts[_new] = new Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    _new += 1;
    _last += 1;
    if (_last >= 8)
        _last = 8;
}
void PhoneBook::search() {
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < _last; i++)
    {
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        _contacts[i]->print(i+1);
    }
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::string index;
    std::cout << std::endl << "Select index: ";
    // read string make sure it can be an int convert to int
    if (!std::getline(std::cin, index))
    {
        std::cout << "Index should be a positive number between 1 and 8!" << std::endl;
        exit (0);
    }
    std::string last;
    std::stringstream ss;
    ss << _last;
    last = ss.str();
    if ((index.length() != 1) or (index[0] < '1') or (index[0] > last[0]))
    {
        std::cout << "Index should be a positive number between 1 and 8!" << std::endl;
        return;
    }
    _contacts[std::atoi(index.c_str())-1]->longprint();
}
 void PhoneBook::exiting() {
    for (int i = 0; i < _last; i++)
    {
        delete _contacts[i];
    }
    std::cout << "Okey then, bye bye!" << std::endl;
    exit(0);
}
