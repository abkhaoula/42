#include "Animal.hpp"


Animal::Animal() : type(""){
    std::cout << "Animal(" << type << "): default constructor called;" << std::endl;
}
Animal::Animal(const Animal& a) : type(a.type) {
    std::cout << "Animal(" << type << "): copy constructor called;" << std::endl;
}
Animal& Animal::operator=(const Animal& a) {
    this->type = a.type;
    std::cout << "Animal(" << type << "): copy assignement opperator constructor called;" << std::endl;
    return (*this);
}
Animal::~Animal() {
    std::cout << "Animal(" << type << "): destructor called;" << std::endl;
}

std::string Animal::getType ( void ) const {
    return (type);
}

void Animal::makeSound() const{
    std::cout << "Animal(" << type << "): makes sounds;" << std::endl;
}

