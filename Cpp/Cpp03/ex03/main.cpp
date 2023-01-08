#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap c("khaoula");
    FragTrap s("laila");
    c.attack("v");
    s.attack("v");
    s.highFivesGuys();
}
