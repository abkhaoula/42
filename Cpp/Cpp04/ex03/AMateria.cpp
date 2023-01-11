#include "AMateria.hpp"

AMateria::AMateria() : type(""){}
AMateria::AMateria(std::string const & type) : type(type){}
AMateria::AMateria(const AMateria& am) : type(am.type) {}
AMateria& AMateria::operator=(const AMateria& a){}
AMateria::~AMateria(){}
std::string const& AMateria::getType() const{}
void AMateria::use(ICharacter& target){}