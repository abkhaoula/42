#include "Cure.hpp"

Cure::Cure(){
    type = "cure";
}
Cure::Cure(const Cure& c) {
    type = c.type;
}
Cure& Cure::operator=(const Cure& c) {
    this->type = c.type;
    return (*this);
}
Cure::~Cure() {}
Cure* Cure::clone() const {
    return new Cure(*this);
}
void Cure::use(ICharacter& target) {
    std::cout<<"* heals"<< target.getName() <<"’s wounds *" << std::endl;
}