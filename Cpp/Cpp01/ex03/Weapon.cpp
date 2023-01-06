/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:53 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:23:54 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string t) {
    type = t;
}

Weapon::~Weapon() {}

std::string Weapon::getType() {
    return (type);
}
void Weapon::setType(std::string newType) {
    type = newType;
}