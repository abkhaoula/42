/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:45 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:23:47 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon *w;
    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &_w);
        void attack();
};

#endif /* __HUMANB_H__ */