/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:18:42 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/05 13:18:43 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"
#include <iostream>

Zombie* newZombie( std::string name ) {
    Zombie* z = new Zombie(name);
    return (z);
}
