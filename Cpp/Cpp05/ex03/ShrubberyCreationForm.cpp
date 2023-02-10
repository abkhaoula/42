#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", "human", 72, 45) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("Shrubbery Creation Form", target, 72, 45) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf) : Form(scf.getName(), scf.getTarget(), scf.getSignGrade(), scf.getExecGrade()){
    if (scf.getSigned())
        this->setSigned(1);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf) {
    this->setSigned(scf.getSigned());
    return ( *this );
}

void ShrubberyCreationForm::executeAction() const{
    std::ofstream file;
    std::cout<<"okk"<<std::endl;
    std::string file_name = this->getTarget() + "_shrubbery";
    file.open(file_name.c_str());
    file<< "                                    @ " <<std::endl;
    file<< "                              @ @ @  @ @ @ " <<std::endl;
    file<< "                            @  @\\/@ @ /__@ " <<std::endl;
    file<< "                            @@@ @\\ / @/  @ @ " <<std::endl;
    file<< "                           @\\  \\/@| @ | @ " <<std::endl;
    file<< "                          @__\\@ \\ |/ \\| / @ " <<std::endl;
    file<< "                             __\\|@|  ||/__/@ " <<std::endl;
    file<< "                            /  \\ \\  / /__ " <<std::endl;
    file<< "                           @    \\  \\/ /   @ " <<std::endl;
    file<< "                                 |\" '| " <<std::endl;
    file<< "                                 |\"  | " <<std::endl;
    file<< "                                 |\"  | " <<std::endl;
    file<< "                                ~|\"  |~ " <<std::endl;
    file<< "                            ~~~~       ~~~~ " <<std::endl;
    file<< "                          ~~               ~~~ " <<std::endl;

}

ShrubberyCreationForm::~ShrubberyCreationForm() {}