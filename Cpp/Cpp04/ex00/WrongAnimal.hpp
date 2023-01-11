#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& a);
        WrongAnimal& operator=(const WrongAnimal& a);
        virtual ~WrongAnimal();
        void makeSound() const;
        std::string getType ( void ) const;
};


#endif