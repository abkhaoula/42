#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
    FragTrap(const std::string& name);
    virtual ~FragTrap();
    FragTrap(const FragTrap& p);
    FragTrap& operator=(const FragTrap& p);
    void attack(const std::string& target);
    void highFivesGuys();
};

#endif