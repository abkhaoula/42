/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:18:53 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/05 13:18:54 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() { }
Zombie::Zombie(std::string s) {
    name = s;
}
Zombie::~Zombie() {
    std::cout << name << ": " << "Out ..." << std::endl;
}
void Zombie::announce( void ) {
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string s) {
    name = s;
}
