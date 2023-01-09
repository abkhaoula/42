#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string _name;
    public:
        DiamondTrap( std::string name );
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap& p);
        DiamondTrap& operator=(const DiamondTrap& p);
        using   ScavTrap::attack;
        void    whoAmI( void );
}

#endif