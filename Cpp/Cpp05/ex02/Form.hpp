#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        const std::string _target;
        bool _signed;
        const int _sign_grade;
        const int _exec_grade;
    public:
        Form();
        Form(std::string n, std::string t, int rg, int xg);
        Form(const Form& f);
        Form& operator=(const Form& f);
        std::string getName ( void ) const;
        std::string getTarget ( void ) const;
        bool getSigned ( void ) const;
        void setSigned ( bool b );
        int getSignGrade ( void ) const;
        int getExecGrade ( void ) const;
        void beSigned (const Bureaucrat& b);
        void execute(Bureaucrat const & b) const;
		virtual void executeAction() const = 0;
        virtual ~Form();





        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class NotSigned : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& f);


#endif
