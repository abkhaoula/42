#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		void executeAction() const;
        virtual ~ShrubberyCreationForm();
};


#endif