#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), w(NULL) {}
HumanB::~HumanB() {}
void HumanB::setWeapon(Weapon &_w) {
    w = &_w;
}
void HumanB::attack()
{
    std::cout << name << " attacks with their " << w->getType() << std::endl;
}
