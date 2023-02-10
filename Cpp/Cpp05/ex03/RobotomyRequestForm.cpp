#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", "human", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("Robotomy Request Form", target, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf) : Form(rrf.getName(), rrf.getTarget(), rrf.getSignGrade(), rrf.getExecGrade()){
    if (rrf.getSigned())
        this->setSigned(1);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rrf) {
    this->setSigned(rrf.getSigned());
    return ( *this );
}

void RobotomyRequestForm::executeAction() const{
    std::cout << "* drilling noises *" << std::endl;
    srand(time(0));
    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed." << std::endl;

}

RobotomyRequestForm::~RobotomyRequestForm() {}