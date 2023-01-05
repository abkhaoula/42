/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:19:00 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/05 13:19:01 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string s);
        ~Zombie();
        void setName(std::string s);
        void announce( void );
};

#endif /* __ZOMBIE_H__ */