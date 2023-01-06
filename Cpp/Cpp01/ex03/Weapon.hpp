/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:56 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:23:57 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>
#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string t);
        ~Weapon();
        std::string getType();
        void setType(std::string newType);
};

#endif /* __WEAPON_H__ */