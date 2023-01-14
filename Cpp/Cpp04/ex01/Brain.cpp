#include "Brain.hpp"


Brain::Brain() {
    for(int i = 0; i < 100; i++){
        ideas[i] = "Think";
    }
    std::cout << "Brain created" << std::endl;
}
Brain::Brain(const Brain& b) {
    for(int i = 0; i < 100; i++){
        ideas[i] = b.ideas[i];
    }
    std::cout << "Brain created" << std::endl;
}

Brain& Brain::operator=(const Brain& b) {
    for(int i = 0; i < 100; i++){
        this->ideas[i] = b.ideas[i];
    }
    return (*this);
}
Brain::~Brain() {
    std::cout << "Brain deleted" << std::endl;
}
