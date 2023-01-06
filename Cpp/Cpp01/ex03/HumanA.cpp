/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:37 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:23:38 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &w_) : name(_name), w(w_) {}
HumanA::~HumanA() {}
void HumanA::setWeapon(Weapon &_w) {
    w = _w;
}
void HumanA::attack()
{
    std::cout << name << " attacks with their " << w.getType() << std::endl;
}