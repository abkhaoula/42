#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("default_player"), _hit_points(10), _energy_points(10), _attack_damage(10) {
    std::cout << "ClapTrap " << _name << ": created;" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(10) {
    std::cout << "ClapTrap " << _name << ": created;" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& p) : _name(p._name), _hit_points(p._hit_points), _energy_points(p._energy_points), _attack_damage(p._attack_damage) {
    std::cout << "ClapTrap " << _name << ": created;" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& p) {
    std::cout << "ClapTrap " << _name;
    this->_name = p._name;
    this->_hit_points = p._hit_points;
    this->_energy_points = p._energy_points;
    this->_attack_damage = p._attack_damage;
    std::cout << "is now " << _name << std::endl;

    return (*this);
}
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << ": destroyed;" << std::endl;
}
void ClapTrap::attack(const std::string& target) {
    if (_hit_points == 0)
    {
        std::cout << "ClapTrap " << _name << ": can't attack (not enough hit points);" << std::endl;
        return ;
    }
    if (_energy_points < 1)
    {
        std::cout << "ClapTrap " << _name << ": can't attack (not enough energy points);" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << ": attacks " << target << ";" << std::endl;
    _energy_points = _energy_points - 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount <= 0)
    {
        std::cout << "ClapTrap " << _name << ": can't take damage (amount of damage should be positive);" << std::endl;
        return ;
    }
    if (_hit_points == 0)
    {
        std::cout << "ClapTrap " << _name << ": can't take damage (hit points is already 0);" << std::endl;
        return ;
    }
    if (_hit_points <= (int) amount)
    {
        std::cout << "ClapTrap " << _name << ": takes damage;" << std::endl;
        _hit_points = 0;
        return ;
    }
    std::cout << "ClapTrap " << _name << ": takes damage;" << std::endl;
    _hit_points = _hit_points - amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (amount <= 0)
    {
        std::cout << "ClapTrap " << _name << ": can't repair (amount to be repaired should be positive);" << std::endl;
        return ;
    }
    if (_energy_points < 1)
    {
        std::cout << "ClapTrap " << _name << ": can't repair (not enough energy points);" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << ": got repaired;" << std::endl;
    _energy_points = _energy_points - 1;
    _hit_points = _hit_points + amount;
}
void ClapTrap::status() {
    std::cout << "ClapTrap " << _name << ": " << "hit points:" << _hit_points << ";energy points:" << _energy_points << ";attack damage:" << _attack_damage << ";" << std::endl;
}