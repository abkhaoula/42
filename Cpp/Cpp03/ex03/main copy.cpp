#include "ClapTrap.hpp"

int main() {
    ClapTrap c1;
    ClapTrap c2("khaoula");
    c1.attack("khaoula");
    c2.takeDamage(10);
    c2.status();
    c2.beRepaired(10);
    c2.status();
    c2.attack("default_player");
    c1.takeDamage(10);
    c1.status();
    c1.beRepaired(10);
    c1.status();
    c1.attack("khaoula");
    c2.takeDamage(10);
    c2.status();
    c2.attack("default_player");
}