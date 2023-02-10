#include "Form.hpp"


Form::Form() : _name ("default_name"), _signed(0), _required_grade(150){
}

Form::Form(std::string n, int rg) : _name (n), _signed(0), _required_grade(rg){
    if (rg < 1) {
        throw Form::GradeTooHighException();
    }
    if (rg > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& f) : _name(f._name), _signed(f._signed), _required_grade(f._required_grade) {
    if (f._required_grade < 1) {
        throw Form::GradeTooHighException();
    }
    if (f._required_grade > 150) {
        throw Form::GradeTooLowException();
    }
}

Form& Form::operator=(const Form& f) {
    if (f._required_grade < 1)
        throw Form::GradeTooHighException();
    if (f._required_grade > 150) 
        throw Form::GradeTooLowException();
    //_name = f._name;//check2
    _signed = f._signed;
    //_required_grade = f._required_grade;//check2
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    return out << f.getName() << ", form required grade " << f.getRequiredGrade();
    if (f.getSigned())
        std::cout<< " is ";
    else
        std::cout<< " is not ";
    std::cout<< "signed" << std::endl;
}

std::string Form::getName ( void ) const {
    return (_name);
}

int Form::getRequiredGrade ( void ) const {
    return (_required_grade);
}

bool Form::getSigned ( void ) const {
    return (_signed);
}

void Form::setSigned ( bool b ) {
    _signed = b;
}

void Form::beSigned (const Bureaucrat& b) {
    if (b.getGrade() < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (b.getGrade() > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    b.signForm(*this);
}

Form::~Form(){}






const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high !!!!"; 
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low !!!!"; 
}
