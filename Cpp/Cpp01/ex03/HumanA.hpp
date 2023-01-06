/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:39 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:23:40 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon &w;
    public:
        HumanA(std::string _name, Weapon &w_);
        ~HumanA();
        void setWeapon(Weapon &_w);
        void attack();
};

#endif /* __HUMANA_H__ */