#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& i);
    Ice& operator=(const Ice& i);
    virtual ~Ice();
    virtual Ice* clone() const;
    virtual void use(ICharacter& target);
};

#endif