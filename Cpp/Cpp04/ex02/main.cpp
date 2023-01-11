#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

void l() {
    system("leaks a.out");
}
void    ft()
    {
        std::cout << "--------------------------------------------" << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
        std::cout << "--------------------------------------------" << std::endl;
        Animal *table2[6];
        int i_ = 0;
        while (i_ < 3){
            table2[i_] = new Dog();
            i_++;
        }
        while (i_ < 6){
            table2[i_] = new Cat();
            i_++;
        }
        i_ = 0;
        while (i_ < 6){
            delete table2[i_];
            i_++;
        }
        std::cout << "--------------------------------------------" << std::endl;
        //Animal a;
        //a.makeSound();
    }
int main()
{
    ft();
    l();
return 0;
}



