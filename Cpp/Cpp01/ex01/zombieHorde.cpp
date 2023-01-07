/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:19:04 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/05 13:19:05 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"
#include <iostream>

Zombie*	zombieHorde(int N, std::string name) {
	if (N <=0 )
	{
		std::cout<< "Numbers of inputs should be positive" << std::endl;
		return (NULL);
	}
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
    }
	return (horde);
}