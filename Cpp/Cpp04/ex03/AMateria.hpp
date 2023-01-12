#ifndef AMATERIAL_HPP
#define AMATERIAL_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria& am);
    AMateria& operator=(const AMateria& am);
    virtual ~AMateria();
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif