#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* TheBrain;
    public:
        Cat();
        Cat(const Cat& c);
        Cat& operator=(const Cat& c);
        virtual ~Cat();
        void makeSound() const;
};


#endif