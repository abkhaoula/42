/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:28 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/05 13:08:29 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string s) {
    _name = s;
}
Zombie::~Zombie() {
    std::cout << _name << ": " << "Out ..." << std::endl;
}
void Zombie::announce( void ) {
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
