#include "Cat.hpp"


Cat::Cat(){
    TheBrain = new Brain();
    type = "Cat";
    std::cout << "Cat(" << type << "): default constructor called;" << std::endl;
}
Cat::Cat(const Cat& c) {
    TheBrain = new Brain();
    *(this->TheBrain) = *(c.TheBrain);
    type = c.type;
    std::cout << "Cat(" << type << "): copy constructor called;" << std::endl;
}
Cat& Cat::operator=(const Cat& c) {
    *(this->TheBrain) = *(c.TheBrain);
    this->type = c.type;
    std::cout << "Cat(" << type << "): copy assignement opperator constructor called;" << std::endl;
    return (*this);
}
Cat::~Cat() {
    delete TheBrain;
    std::cout << "Cat(" << type << "): destructor called;" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat(" << type << "): meows;" << std::endl;
}

