#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _required_grade;
    public:
        Form();
        Form(std::string n, int rg);
        Form(const Form& f);
        Form& operator=(const Form& f);
        std::string getName ( void ) const;
        bool getSigned ( void ) const;
        void setSigned ( bool b );
        int getRequiredGrade ( void ) const;
        void beSigned (const Bureaucrat& b);
        virtual ~Form();





        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& f);


#endif
