#include "Dog.hpp"


Dog::Dog(){
    TheBrain = new Brain();
    type = "Dog";
    std::cout << "Dog(" << type << "): default constructor called;" << std::endl;
}
Dog::Dog(const Dog& d){
    type = d.type;
    std::cout << "Dog(" << type << "): copy constructor called;" << std::endl;
}
Dog& Dog::operator=(const Dog& d) {
    this->type = d.type;
    std::cout << "Dog(" << type << "): copy assignement opperator constructor called;" << std::endl;
    return (*this);
}
Dog::~Dog() {
    delete TheBrain;
    std::cout << "Dog(" << type << "): destructor called;" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog(" << type << "): barks;" << std::endl;
}