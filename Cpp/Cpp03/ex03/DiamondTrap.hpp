#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string _name;
    public:
        DiamondTrap( std::string name );
        virtual ~DiamondTrap();
        DiamondTrap(const DiamondTrap& p);
        DiamondTrap& operator=(const DiamondTrap& p);
        void attack(const std::string& target);
        void    whoAmI( void );
};

#endif