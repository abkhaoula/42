/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:18:35 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 15:06:51 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int main() {
    //Zombie *z = newZombie("deadly Alive");
    //z->announce();
    //delete z;
    //randomChump( "randomly Alive" );
    Zombie *zombie = zombieHorde( 3, "Hordly Alize" );
    delete [] zombie;
}