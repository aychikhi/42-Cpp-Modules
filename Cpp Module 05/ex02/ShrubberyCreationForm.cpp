#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
    // std::cout << "ShrubberyCreationForm Constructor was called" << std::endl;
	target = "defaults";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
    // std::cout << "ShrubberyCreationForm Parameterized Constructor was called" << std::endl;
	this->target = obj.target;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	// std::cout << "ShrubberyCreationForm Copy Constructor was called" << std::endl;
	this->target = target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	// std::cout << "ShrubberyCreationForm Copy assignment was called" << std::endl;
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm Destructor was called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
    if (this->getisSigned() == false)
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException(); 
    std::ofstream outfile((this->target + "_shrubbery").c_str());
    if (outfile.is_open()) {
        outfile << "      /\\      " << std::endl;
        outfile << "     /\\*\\     " << std::endl;
        outfile << "    /\\O\\*\\    " << std::endl;
        outfile << "   /*/\\/\\/\\   " << std::endl;
        outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
        outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile.close();
    }
}