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

void ScavTrap::attack(const std::string& target) {
  if (_hit_points == 0)
    {
        std::cout << "ScavTrap " << _name << ": can't attack (not enough hit points);" << std::endl;
        return ;
    }
    if (_energy_points < 1)
    {
        std::cout << "ScavTrap " << _name << ": can't attack (not enough energy points);" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << _name << ": attacks " << target << ";" << std::endl;
    _energy_points = _energy_points - 1;
}