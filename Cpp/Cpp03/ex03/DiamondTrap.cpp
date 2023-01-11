#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name), FragTrap( name ), ScavTrap( name ){
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    FragTrap::_hit_points = 100;
    ScavTrap::_energy_points = 50;
    FragTrap::_attack_damage = 30;
    std::cout << "DiamondTrap " << _name << ": created;" << std::endl;
}
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << ": destroyed;" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& p) : ClapTrap(p), FragTrap(p), ScavTrap(p) {
    this->_name = p._name;
    this->ClapTrap::_name = p._name + "_clap_name";
    std::cout << "DiamondTrap " << _name << ": created;" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& p) {
    std::string tmp = _name;
    ClapTrap::operator=(p);
    this->_name = p._name;
    this->ClapTrap::_name = p._name + "_clap_name";
    std::cout << "DiamondTrap " << this->_name << " is now " << this->_name << std::endl;
    return (*this);
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "DiamondTrap::_name " << this->_name << "; ClapTrap::_name " << ClapTrap::_name << std::endl;
}