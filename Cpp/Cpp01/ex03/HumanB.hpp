#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon *w;
    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &_w);
        void attack();
};

#endif /* __HUMANB_H__ */