#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap: virtual ClapTrap {
    public:
        ScavTrap(const std::string& name);
        ~ScavTrap();
        ScavTrap(const ScavTrap& p);
        ScavTrap& operator=(const ScavTrap& p);
        void attack(const std::string& target);
        void guardGate();
};

#endif