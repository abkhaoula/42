/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:24:04 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:24:05 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Harl.hpp"

Harl::Harl() {

    lvl[0].l = "DEBUG";
    lvl[0].f = &Harl::debug;
    lvl[1].l = "INFO";
    lvl[1].f = &Harl::info;
    lvl[2].l = "WARNING";
    lvl[2].f = &Harl::warning;
    lvl[3].l = "ERROR";
    lvl[3].f = &Harl::error;
}
Harl::~Harl() {}
void Harl::debug( void ) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain( std::string level ) {
    if (level != "DEBUG" and level != "INFO" and level != "WARNING" and level != "ERROR")
    {
        std::cout << "Not a valid level !";
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (level == (lvl[i].l))
            (this->*lvl[i].f)();
    }
    
}