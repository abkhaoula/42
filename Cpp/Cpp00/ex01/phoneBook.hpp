#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact() {
            _firstName = "";
            _lastName = "";
            _nickname = "";
            _phoneNumber = "";
            _darkestSecret = "";
        }
        ~Contact() {}
        Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) : _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret){} 
        void print(int i) {
            if (_firstName.empty())
                return;
            std::string index;
            std::stringstream ss;
            ss << i;
            index = ss.str();
            if (index.length() > 10) {
                index.resize(9);
                index[8] = '.';
            }
            if (_firstName.length() > 10) {
                _firstName.resize(9);
                _firstName[8] = '.';
            }
            if (_lastName.length() > 10) {
                _lastName.resize(9);
                _lastName[8] = '.';
            }
            if (_nickname.length() > 10) {
                _nickname.resize(9);
                _nickname[8] = '.';
            }
            std::cout << "|";
            std::cout.width(10);
            std::cout << std::right << index;
            std::cout << "|";
            std::cout.width(10);
            std::cout << std::right << _firstName;
            std::cout << "|";
            std::cout.width(10);
            std::cout << std::right << _lastName;
            std::cout << "|";
            std::cout.width(10);
            std::cout << std::right << _nickname;
            std::cout << "|";
            std::cout << std::endl;
        }
        void longprint() {
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
};

class PhoneBook {
    private:
        Contact *contacts[9];
        int _new;
        int _last;
    public:
        PhoneBook() {
            _new = 0;
            _last = 0;
        }
        ~PhoneBook() {}
        void add() {
            std::string firstName;
            std::string lastName;
            std::string nickname;
            std::string phoneNumber;
            std::string darkestSecret;

            // empty string??
            do {
                std::cout << "First Name : ";
                std::getline(std::cin, firstName);
            } while(firstName.empty());
            do {
                std::cout << "Last Name : ";
                std::getline(std::cin, lastName);
            } while(lastName.empty());
            do {
                std::cout << "Nickname : ";
                std::getline(std::cin, nickname);
            } while(nickname.empty());
            do {
                std::cout << "Phone Number : ";
                std::getline(std::cin, phoneNumber);
            } while(phoneNumber.empty());
            do {
                std::cout << "Darkest Secret : ";
                std::getline(std::cin, darkestSecret);
            } while(darkestSecret.empty());

            if (_new == 9)
            {
                _new = 0;
                _last -= 1;
                delete contacts[_new];
            }
            contacts[_new] = new Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            _new += 1;
            _last += 1;
        }
        void search() {
            std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
            std::cout << "|----------|----------|----------|----------|" << std::endl;
            for (int i = 0; i < _last; i++)
            {
                contacts[i]->print(i+1);
            }
            std::cout << "|----------|----------|----------|----------|" << std::endl;
            std::string index;
            std::cout << std::endl << "Select index: ";
            // read string make sure it can be an int convert to int
            std::getline(std::cin, index);
            if ((index.length() != 1) or (index[0] < '1') or (index[0] > '9'))
            {
                std::cout << "Index should be a positive number between 1 and 9!" << std::endl;
                return;
            }
            contacts[std::atoi(index.c_str())-1]->longprint();
        }
};

#endif