#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : ClapTrap {
    public:
    FragTrap(const std::string& name);
    ~FragTrap();
    FragTrap(const FragTrap& p);
    FragTrap& operator=(const FragTrap& p);
    void attack(const std::string& target);
    void highFivesGuys();
};

#endif