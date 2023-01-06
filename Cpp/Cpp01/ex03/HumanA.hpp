#ifndef __HUMANA_H__
#define __HUMANA_H__

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon &w;
    public:
        HumanA(std::string _name, Weapon &w_);
        ~HumanA();
        void setWeapon(Weapon &_w);
        void attack();
};

#endif /* __HUMANA_H__ */