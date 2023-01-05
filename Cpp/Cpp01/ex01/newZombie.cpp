#include "Zombie.hpp"
#include "Zombie.h"
#include <iostream>

Zombie* newZombie( std::string name ) {
    Zombie* z = new Zombie(name);
    return (z);
}
