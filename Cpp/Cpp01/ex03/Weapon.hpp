#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>
#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string t);
        ~Weapon();
        std::string getType();
        void setType(std::string newType);
};

#endif /* __WEAPON_H__ */