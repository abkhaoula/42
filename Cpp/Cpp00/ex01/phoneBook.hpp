/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:06:16 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/05 12:06:17 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact();
        ~Contact();
        Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
        void print(int i);
        void longprint();
};

class PhoneBook {
    private:
        Contact *_contacts[8];
        int _new;
        int _last;
    public:
        PhoneBook();
        ~PhoneBook();
        void add();
        void search();
        void exiting();
};

#endif