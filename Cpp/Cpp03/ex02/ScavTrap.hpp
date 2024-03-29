#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap:public ClapTrap {
    public:
        ScavTrap(const std::string& name);
        virtual ~ScavTrap();
        ScavTrap(const ScavTrap& p);
        ScavTrap& operator=(const ScavTrap& p);
        void attack(const std::string& target);
        void guardGate();
};

#endif