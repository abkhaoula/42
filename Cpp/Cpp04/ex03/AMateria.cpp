#include "AMateria.hpp"

AMateria::AMateria() : type(""){}
AMateria::AMateria(std::string const & type) : type(type){}
AMateria::AMateria(const AMateria& am) : type(am.type) {}
AMateria& AMateria::operator=(const AMateria& am) {
    this->type = am.type;
    return (*this);
}
AMateria::~AMateria(){}
std::string const& AMateria::getType() const{
    return (type);
}
void AMateria::setType(std::string newType) {
    type = newType;
}
void AMateria::use(ICharacter& target){
    std::cout << "AMateria(" << target.getName() << "): is being used;" << std::endl;
}