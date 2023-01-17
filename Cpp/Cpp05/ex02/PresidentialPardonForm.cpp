#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", "human", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("Presidential Pardon Form", target, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf) : Form(ppf.getName(), ppf.getTarget(), ppf.getSignGrade(), ppf.getExecGrade()){
    if (ppf.getSigned())
        this->setSigned(1);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ppf) {
    *this = PresidentialPardonForm(ppf);
    return ( *this );
}

void PresidentialPardonForm::executeAction() const{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." <<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}