/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:24:17 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:24:18 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
#define __HARL_H__

#include <string>

class Harl {
    struct levels {
        std::string l;
        void (Harl::*f)();
    };
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        levels lvl[4];
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
};

#endif /* __HARL_H__ */