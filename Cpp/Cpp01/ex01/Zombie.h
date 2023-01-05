#ifndef ZOMBIE_H
#define ZOMBIE_H

void randomChump( std::string name );
Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif