#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() { }
Zombie::Zombie(std::string s) {
    name = s;
}
Zombie::~Zombie() {
    std::cout << name << ": " << "Out ..." << std::endl;
}
void Zombie::announce( void ) {
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string s) {
    name = s;
}
