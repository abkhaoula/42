#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type(""){
    std::cout << "WrongAnimal(" << type << "): default constructor called;" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& a) : type(a.type) {
    std::cout << "WrongAnimal(" << type << "): copy constructor called;" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) {
    this->type = a.type;
    std::cout << "WrongAnimal(" << type << "): copy assignement opperator constructor called;" << std::endl;
    return (*this);
}
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal(" << type << "): destructor called;" << std::endl;
}

std::string WrongAnimal::getType ( void ) const {
    return (type);
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal(" << type << "): makes sounds;" << std::endl;
}