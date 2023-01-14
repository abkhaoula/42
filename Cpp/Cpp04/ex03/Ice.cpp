#include "Ice.hpp"

Ice::Ice(){
    type = "ice";
}
Ice::Ice(const Ice& i) {
    type = i.type;
}
Ice& Ice::operator=(const Ice& i){
    this->type = i.type;
    return (*this);
}
Ice::~Ice() {}
Ice* Ice::clone() const {
    return new Ice(*this);
}
void Ice::use(ICharacter& target) {
    std::cout<<"* shoots an ice bolt at "<< target.getName() <<" *" << std::endl;
}