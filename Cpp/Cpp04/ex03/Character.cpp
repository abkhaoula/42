#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL; 
}


Character::Character(Character const & other) {
    name = other.name;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
    }
}


Character & Character::operator=(Character const & other) {
    name = other.name;
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) 
            delete inventory[i];
        inventory[i] = NULL;
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
                
    }
    return *this;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m->clone();
            break;
        }
        else if (inventory[i]->getType() == "") {
            delete inventory[i];
            inventory[i] = m->clone();
            break;
        }
    }
}
        
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->setType("");
    }
}
        
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}


Character::~Character() {
    for (int i = 0; i < 4; i++) { 
        if (inventory[i])
            delete inventory[i];
    }
}