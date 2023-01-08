#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap c("khaoula");
    ScavTrap s("laila");
    c.attack("v");
    s.attack("v");
    s.guardGate();
}
