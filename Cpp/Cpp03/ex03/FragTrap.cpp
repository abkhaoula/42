#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap " << _name << ": created;" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << ": destroyed;" << std::endl;
}

FragTrap::FragTrap(const FragTrap& p) : ClapTrap(p){
    std::cout << "FragTrap " << _name << ": created;" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& p) {
    std::string tmp = _name;
    ClapTrap::operator=(p);
    std::cout << "FragTrap " << _name << " is now " << _name << std::endl;
    return (*this);
}

void FragTrap::attack(const std::string& target) {
    if (_hit_points == 0)
    {
        std::cout << "FragTrap " << _name << ": can't attack (not enough hit points);" << std::endl;
        return ;
    }
    if (_energy_points < 1)
    {
        std::cout << "FragTrap " << _name << ": can't attack (not enough energy points);" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << _name << ": attacks " << target << ";" << std::endl;
    _energy_points = _energy_points - 1;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " requests high fives" << std::endl;
}