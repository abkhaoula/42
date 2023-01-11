#include "WrongCat.hpp"


WrongCat::WrongCat(){
    type = "WrongCat";
    std::cout << "WrongCat(" << type << "): default constructor called;" << std::endl;
}
WrongCat::WrongCat(const WrongCat& c) {
    type = c.type;
    std::cout << "WrongCat(" << type << "): copy constructor called;" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& c) {
    this->type = c.type;
    std::cout << "WrongCat(" << type << "): copy assignement opperator constructor called;" << std::endl;
    return (*this);
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat(" << type << "): destructor called;" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat(" << type << "): meows;" << std::endl;
}