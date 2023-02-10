#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class Intern {
    public:
        Intern();
        Intern(const Intern& i);
        Form* makeForm(std::string formName, std::string targetName) const;
        Intern& operator=(const Intern& i);
        virtual ~Intern();

};

#endif
