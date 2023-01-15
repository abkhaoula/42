#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"


class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string n, int g);
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat& operator=(const Bureaucrat& b);
        std::string getName ( void ) const;
        int getGrade ( void ) const;
        void incrementGrade( void );
        void decrementGrade( void );
        void signForm(Form &f) const;
        virtual ~Bureaucrat();





        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);


#endif
