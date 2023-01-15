#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
    try {
        Bureaucrat b1("sanaa", 150);
        Form f1("Birth Certificat", 45);
        f1.beSigned(b1);
    }
    catch (std::exception & e)
    {
       std::cout<< e.what() << std::endl;
    }
    try {
        Bureaucrat b1("sanaa", 1);
        b1.incrementGrade();
    }
    catch (std::exception & e)
    {
       std::cout<< e.what() << std::endl;
    }
    try {
        Bureaucrat b1("sanaa", 45);
        b1.decrementGrade();
        std::cout<< b1 << std::endl;
    }
    catch (std::exception & e)
    {
       std::cout<< e.what() << std::endl;
    }
    
}