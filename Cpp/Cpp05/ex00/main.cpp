#include "Bureaucrat.hpp"

int main () {
    try {
        Bureaucrat b1("sanaa", 150);
        b1 = Bureaucrat("laila", 2);
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