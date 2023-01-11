#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
std::cout << "--------------------------------------------" << std::endl;
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
std::cout << "--------------------------------------------" << std::endl;
const WrongAnimal* Wrongmeta = new WrongAnimal();
const WrongAnimal* Wrongi = new WrongCat();
std::cout << Wrongi->getType() << " " << std::endl;
Wrongi->makeSound(); //will output the cat sound!
Wrongmeta->makeSound();
std::cout << "--------------------------------------------" << std::endl;
return 0;
}



