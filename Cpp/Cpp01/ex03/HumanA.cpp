#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &w_) : name(_name), w(&w_) {}
HumanA::~HumanA() {}
void HumanA::setWeapon(Weapon &_w) {
    w = &_w;
}
void HumanA::attack()
{
    std::cout << name << " attacks with their " << w->getType() << std::endl;
}