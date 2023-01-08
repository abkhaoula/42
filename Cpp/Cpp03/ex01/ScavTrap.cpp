#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap " << _name << ": created;" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << ": destroyed;" << std::endl;
}

ScavTrap::ScavTrap(const ClapTrap& p) {
    *this = p;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& p) {
    *this = p;
    return (*this);
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}