#include "Form.hpp"


Form::Form() : _name ("default_name"), _target ("none"), _signed(0), _sign_grade(150), _exec_grade(150){
}

Form::Form(std::string n, std::string t, int rg, int xg) : _name (n), _target (t), _signed(0), _sign_grade(rg), _exec_grade(xg){
    if (rg < 1 or xg < 1) {
        throw Form::GradeTooHighException();
    }
    if (rg > 150 or xg > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& f) : _name(f._name), _target (f._target), _signed(f._signed), _sign_grade(f._sign_grade), _exec_grade(f._exec_grade) {
    if (f._sign_grade < 1 or f._exec_grade < 1) {
        throw Form::GradeTooHighException();
    }
    if (f._sign_grade > 150 or f._exec_grade > 150) {
        throw Form::GradeTooLowException();
    }
}

Form& Form::operator=(const Form& f) {
    if (f._sign_grade < 1 or f._exec_grade < 1)
        throw Form::GradeTooHighException();
    if (f._sign_grade > 150 or f._exec_grade > 150) 
        throw Form::GradeTooLowException();
    _signed = f._signed;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    if (f.getSigned())
        return out << f.getName() << ", form required sign grade " << f.getSignGrade() << " and required execution grade "<< f.getExecGrade()<< " and target "<< f.getTarget() <<" is signed.";
    return out << f.getName() << ", form required sign grade " << f.getSignGrade() << " and required execution grade "<< f.getExecGrade()<< " and target "<< f.getTarget() << " is not signed.";
}

std::string Form::getName ( void ) const {
    return (_name);
}

std::string Form::getTarget ( void ) const {
    return (_target);
}

bool Form::getSigned ( void ) const {
    return (_signed);
}

void Form::setSigned ( bool b ) {
    _signed = b;
}

int Form::getSignGrade ( void ) const {
    return (_sign_grade);
}

int Form::getExecGrade ( void ) const {
    return (_exec_grade);
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

void Form::execute (const Bureaucrat& b) const{
    if (b.getGrade() < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (b.getGrade() > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (!_signed) {
        throw Form::NotSigned();
    }
    b.executeForm(*this);
}

Form::~Form(){}






const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high !!!!"; 
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low !!!!"; 
}

const char* Form::NotSigned::what() const throw() {
    return "Form is not signed !!"; 
}