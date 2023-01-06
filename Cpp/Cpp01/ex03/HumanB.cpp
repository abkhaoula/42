/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:43 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:23:44 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), w(NULL) {}
HumanB::~HumanB() {}
void HumanB::setWeapon(Weapon &_w) {
    w = &_w;
}
void HumanB::attack()
{
    std::cout << name << " attacks with their " << w->getType() << std::endl;
}
